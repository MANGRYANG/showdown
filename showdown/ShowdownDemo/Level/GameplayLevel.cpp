#include "GameplayLevel.h"
#include "Engine/Engine.h"
#include "Actor/ChessPiece/Pawn.h"

/*
* Chess pieces
0: King (K)
1: Queen (Q)
2: Rook (R)
3: Bishop (B)
4: Knight (N)
5: Pawn (P)
6: Jester (J)

* Janggi pieces
7: Emperor (\u6F22)
8: Cannon (\u5305)
9: Elephant (\u8C61)
10: Horse (\u99AC)
11: Chariot (\u8ECA)
12: Soldier (\u5175)
13: Gaurd (\u58EB)

* Moving Mark
14: STAR (*)
*/

GameplayLevel::GameplayLevel(bool isForward)
    : mousePos{ 0, 0 }, consoleRect{ 0, 0, 0, 0 }, selectedBoardCoord(-1, -1),
    isForward(isForward), currentPiece(nullptr)
{
    memset(board, -1, sizeof(board));

    GetAsyncKeyState(VK_LBUTTON & 1);
}

GameplayLevel::~GameplayLevel()
{
}

void GameplayLevel::Update(float deltaTime)
{
    Super::Update(deltaTime);

    GetWindowRect(consoleWindow, &consoleRect);

    if (Engine::Get().GetKeyDown(VK_ESCAPE))
    {
        Engine::Get().Shutdown();
    }

    if (GetAsyncKeyState(VK_LBUTTON) & 1)
    {
        if (GetCursorPos(&mousePos))
        {
            int relativeX = mousePos.x - consoleRect.left;
            int relativeY = mousePos.y - consoleRect.top;
            int titleBarHeight = 30;

            if (relativeX >= 0 && relativeX < (consoleRect.right - consoleRect.left) &&
                relativeY >= titleBarHeight && relativeY < (consoleRect.bottom - consoleRect.top))
            {
                for (int row = 0; row < 9; ++row)
                {
                    for (int col = 0; col < 9; ++col)
                    {
                        if (relativeX > ((col * 32 + 14) + 4) && relativeX < (((col + 1) * 32 + 14) - 4))
                        {
                            if (relativeY > ((row * 33 + 37) + 3) && relativeY < (((row + 1) * 33 + 37) - 3))
                            {
                                selectedBoardCoord.xpos = row;
                                selectedBoardCoord.ypos = col;
                                goto OUT_OF_LOOP;
                            }
                        }
                    }
                }

                OUT_OF_LOOP:

                // Case with piece selected during own turn
                if ((isChessTurn &&
                    board[selectedBoardCoord.xpos][selectedBoardCoord.ypos] >= 0 &&
                    board[selectedBoardCoord.xpos][selectedBoardCoord.ypos] <= 6) ||
                    (!isChessTurn &&
                    board[selectedBoardCoord.xpos][selectedBoardCoord.ypos] >= 7 &&
                    board[selectedBoardCoord.xpos][selectedBoardCoord.ypos] <= 13))
                {
                    if (isSelected)
                    {
                        InitializeBoard();
                    }
                    SelectPiece(selectedBoardCoord);
                    ShowReachableWays();
                    HighlightCatchableEnemies();
                }

                // Case with piece selected during other's turn
                else if ((isChessTurn &&
                    board[selectedBoardCoord.xpos][selectedBoardCoord.ypos] >= 7 &&
                    board[selectedBoardCoord.xpos][selectedBoardCoord.ypos] <= 13) ||
                    (!isChessTurn &&
                    board[selectedBoardCoord.xpos][selectedBoardCoord.ypos] >= 0 &&
                    board[selectedBoardCoord.xpos][selectedBoardCoord.ypos] <= 6))
                {
                    if (isSelected)
                    {
                        // Can be catch enemy piece at selected position
                        if (IsThreatenedPiece(selectedBoardCoord))
                        {
                            CatchEnemyPiece(selectedBoardCoord);
                        }

                        InitializeBoard();
                    }
                }

                // Case without Piece selected
                else
                {
                    if (isSelected)
                    {
                        // Can be moved to the selected position
                        if (IsMarked(selectedBoardCoord))
                        {
                            MovePiece(selectedBoardCoord);
                        }
                    }

                    InitializeBoard();
                }
            }
        }
    }
}

void GameplayLevel::Render()
{
    Super::Render();

    // Rendering the board
    Engine::Get().Render(Vector2(0, 0), "忙式成式成式", Color::White);
    Engine::Get().Render(Vector2(26, 0), "式成式成式忖", Color::White);

    for (int i = 1; i < 9; ++i)
    {
        Engine::Get().Render(Vector2(0, i * 2), "戍式托式托式", Color::White);
        Engine::Get().Render(Vector2(26, i * 2), "式托式托式扣", Color::White);
    }

    Engine::Get().Render(Vector2(0, 18), "戌式扛式扛式", Color::White);
    Engine::Get().Render(Vector2(26, 18), "式扛式扛式戎", Color::White);

    for (int i = 1; i < 10; ++i)
    {
        for (int ix = 0; ix < 3; ++ix)
        {
            Engine::Get().Render(Vector2(ix * 4, i * 2 - 1), "弛", Color::White);
            Engine::Get().Render(Vector2(28 + ix * 4, i * 2 - 1), "弛", Color::White);
        }
    }
}

void GameplayLevel::InitializeBoard()
{
    for (Actor* actor : actors)
    {
        Piece* tempPieceActor = dynamic_cast<Piece*>(actor);
        if (tempPieceActor != nullptr)
        {
            tempPieceActor->SetColor(Color::White);
        }

        else
        {
            actor->SetActive(false);
        }
    }

    currentPiece = nullptr;
    catchablePieceCoords = {};
    reachablePieceCoords = {};
    isSelected = false;
}

void GameplayLevel::SelectPiece(Vector2 targetCoord)
{
    Vector2 consolePosition = BoardCoordToActorPosition(targetCoord);
    
    for (Actor* actor : actors)
    {
        Piece* tempPieceActor = dynamic_cast<Piece*>(actor);
        if (tempPieceActor != nullptr &&
            actor->Position() == consolePosition)
        {
            currentPiece = tempPieceActor;
            currentPiece->SetColor(Color::Yellow);

            catchablePieceCoords = currentPiece->CatchablePieceCoord(board, selectedBoardCoord, isForward);
            reachablePieceCoords = currentPiece->ReachablePieceCoord(board, selectedBoardCoord, isForward);

            break;
        }
    }

    isSelected = true;
}

void GameplayLevel::ShowReachableWays()
{
    for (Actor* actor : actors)
    {
        for (Vector2 reachablePieceCoord : reachablePieceCoords)
        {
            MovingMark* tempMarkActor = dynamic_cast<MovingMark*>(actor);
            if (tempMarkActor != nullptr &&
                actor->Position() == BoardCoordToActorPosition(reachablePieceCoord))
            {
                tempMarkActor->SetActive(true);
            }
        }
    }
}

void GameplayLevel::HighlightCatchableEnemies()
{
    for (Actor* actor : actors)
    {
        for (Vector2 catchablePieceCoord : catchablePieceCoords)
        {
            Piece* tempEnemyPieceActor = dynamic_cast<Piece*>(actor);
            if (tempEnemyPieceActor != nullptr &&
                actor->Position() == BoardCoordToActorPosition(catchablePieceCoord))
            {
                tempEnemyPieceActor->SetColor(Color::Red);
            }
        }
    }
}

void GameplayLevel::MovePiece(Vector2 destinationCoord)
{
    Vector2 destinationPosition = BoardCoordToActorPosition(destinationCoord);

    for (Actor* actor : actors)
    {
        if (actor->Position() == destinationPosition)
        {
            Vector2 currentPieceCoord = ActorPositionToBoardCoord(currentPiece->Position());
           
            // Update Board
            int temp = board[destinationCoord.xpos][destinationCoord.ypos];

            board[destinationCoord.xpos][destinationCoord.ypos] =
                board[currentPieceCoord.xpos][currentPieceCoord.ypos];

            board[currentPieceCoord.xpos][currentPieceCoord.ypos] = temp;

            // Move piece
            actor->SetPosition(currentPiece->Position());
            currentPiece->SetPosition(destinationPosition);

            InitializeBoard();
            isChessTurn = !isChessTurn;

            break;
        }
    }
}

// Enyme piece must be located at the destination
void GameplayLevel::CatchEnemyPiece(Vector2 destinationCoord)
{
    Vector2 destinationPosition = BoardCoordToActorPosition(destinationCoord);

    for (Actor* actor : actors)
    {
        if (actor->Position() == destinationPosition)
        {
            Vector2 currentPieceCoord = ActorPositionToBoardCoord(currentPiece->Position());

            // Update Board
            board[destinationCoord.xpos][destinationCoord.ypos] =
                board[currentPieceCoord.xpos][currentPieceCoord.ypos];

            board[currentPieceCoord.xpos][currentPieceCoord.ypos] = -1;

            // Catch enyme piece
            actor->Destroy();
            currentPiece->SetPosition(destinationPosition);
            GameplayLevel::AddActor(new MovingMark(BoardCoordToActorPosition(currentPieceCoord)));

            InitializeBoard();
            isChessTurn = !isChessTurn;

            break;
        }
    }
}

bool GameplayLevel::IsMarked(Vector2 targetCoord)
{
    Vector2 consolePosition = BoardCoordToActorPosition(targetCoord);

    for (Actor* actor : actors)
    {
        MovingMark* tempMarkActor = dynamic_cast<MovingMark*>(actor);
        if (tempMarkActor != nullptr &&
            actor->Position() == consolePosition &&
            actor->IsActive())
        {
            return true;
        }
    }
    return false;
}

bool GameplayLevel::IsThreatenedPiece(Vector2 targetCoord)
{
    Vector2 consolePosition = BoardCoordToActorPosition(targetCoord);

    for (Vector2 catchablePieceCoord : catchablePieceCoords)
    {
        Vector2 catchablePiecePosition = BoardCoordToActorPosition(catchablePieceCoord);
        if (consolePosition == catchablePiecePosition)
        {
            for (Actor* actor : actors)
            {
                Piece* tempEnemyPieceActor = dynamic_cast<Piece*>(actor);
                if (tempEnemyPieceActor != nullptr)
                {
                    return true;
                }
            }
        }
    } 
    return false;
}

Vector2 GameplayLevel::BoardCoordToActorPosition(Vector2 boardCoord)
{
    return Vector2((boardCoord.ypos * 4) + 2, (boardCoord.xpos * 2) + 1);
}

Vector2 GameplayLevel::ActorPositionToBoardCoord(Vector2 actorPosition)
{
    return Vector2((actorPosition.ypos - 1) / 2, (actorPosition.xpos - 2) / 4);
}