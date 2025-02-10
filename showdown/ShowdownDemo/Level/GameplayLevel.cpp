#include "GameplayLevel.h"
#include "Engine/Engine.h"

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
    : mousePos{0, 0}, consoleRect{0, 0, 0, 0}, selectedPieceIndex(-1, -1),
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
                                selectedPieceIndex.xpos = row;
                                selectedPieceIndex.ypos = col;
                                goto OUT_OF_LOOP;
                            }
                        }
                    }
                }
            }
        }

    OUT_OF_LOOP:
        // Chess piece is selected
        if (board[selectedPieceIndex.xpos][selectedPieceIndex.ypos] >= 0 &&
            board[selectedPieceIndex.xpos][selectedPieceIndex.ypos] <= 6)
        {
            if (isSelected)
            {
                if (currentPiece != nullptr)
                {
                    for (std::pair<int, int> catchablePosition : catchablePositions)
                    {
                        for (Actor* actor : actors)
                        {
                            if (actor->IsActive() &&
                                actor->Position() == BoardCoordToPosition(catchablePosition.second, catchablePosition.first))
                            {
                                Piece* catchablePiece = dynamic_cast<Piece*>(actor);
                                if (catchablePiece)
                                {
                                    catchablePiece->SetColor(Color::White);
                                }
                            }
                        }
                    }
                    currentPiece->SetColor(Color::White);
                    currentPiece = nullptr;
                    catchablePositions = {};
                    movingMarkPositions = {};
                }

                isSelected = false;
                DeactivateMovingMark();
            }

            Vector2 selectedPosition = BoardCoordToPosition(selectedPieceIndex.ypos, selectedPieceIndex.xpos);

            for (Actor* actor : actors)
            {
                if (actor->Position() == selectedPosition)
                {
                    isSelected = true;

                    currentPiece = dynamic_cast<Piece*>(actor);
                    currentPiece->SetColor(Color::Yellow);
                    catchablePositions =
                        currentPiece->CatchablePiecePosition(board, selectedPieceIndex.xpos, selectedPieceIndex.ypos, isForward);
                    movingMarkPositions =
                        currentPiece->ReachablePiecePosition(board, selectedPieceIndex.xpos, selectedPieceIndex.ypos, isForward);
                }
            }

            for (std::pair<int, int> catchablePosition : catchablePositions)
            {
                for (Actor* actor : actors)
                {
                    if (actor->IsActive() &&
                        actor->Position() == BoardCoordToPosition(catchablePosition.second, catchablePosition.first))
                    {
                        Piece* catchablePiece = dynamic_cast<Piece*>(actor);
                        if (catchablePiece)
                        {
                            catchablePiece->SetColor(Color::Red);
                        }
                    }
                }
            }

            if (!movingMarkPositions.empty())
            {
                for (std::pair<int, int> movingMarkPosition : movingMarkPositions)
                {
                    for (Actor* actor : actors)
                    {
                        if (actor->Position() == BoardCoordToPosition(movingMarkPosition.second, movingMarkPosition.first))
                        {
                            MovingMark* movingMark = dynamic_cast<MovingMark*>(actor);
                            movingMark->SetActive(true);
                        }
                    }
                }
            }
        }

        // Janggi piece is selected
        if (board[selectedPieceIndex.xpos][selectedPieceIndex.ypos] >= 7 &&
            board[selectedPieceIndex.xpos][selectedPieceIndex.ypos] <= 13)
        {
            if (isSelected)
            {
                if (currentPiece != nullptr)
                {
                    for (std::pair<int, int> catchablePosition : catchablePositions)
                    {
                        for (Actor* actor : actors)
                        {
                            if (actor->IsActive() &&
                                actor->Position() == BoardCoordToPosition(catchablePosition.second, catchablePosition.first))
                            {
                                Piece* catchablePiece = dynamic_cast<Piece*>(actor);
                                if (catchablePiece)
                                {
                                    catchablePiece->SetColor(Color::White);
                                }
                            }
                        }
                    }
                    currentPiece->SetColor(Color::White);
                    currentPiece = nullptr;
                    catchablePositions = {};
                    movingMarkPositions = {};
                }

                isSelected = false;
                DeactivateMovingMark();
            }

            Vector2 selectedPosition = BoardCoordToPosition(selectedPieceIndex.ypos, selectedPieceIndex.xpos);

            for (Actor* actor : actors)
            {
                if (actor->Position() == selectedPosition)
                {
                    isSelected = true;

                    currentPiece = dynamic_cast<Piece*>(actor);
                    currentPiece->SetColor(Color::Yellow);
                    catchablePositions =
                        currentPiece->CatchablePiecePosition(board, selectedPieceIndex.xpos, selectedPieceIndex.ypos, isForward);
                    movingMarkPositions =
                        currentPiece->ReachablePiecePosition(board, selectedPieceIndex.xpos, selectedPieceIndex.ypos, isForward);
                }
            }

            for (std::pair<int, int> catchablePosition : catchablePositions)
            {
                for (Actor* actor : actors)
                {
                    if (actor->IsActive() &&
                        actor->Position() == BoardCoordToPosition(catchablePosition.second, catchablePosition.first))
                    {
                        Piece* catchablePiece = dynamic_cast<Piece*>(actor);
                        if (catchablePiece)
                        {
                            catchablePiece->SetColor(Color::Red);
                        }
                    }
                }
            }

            if (!movingMarkPositions.empty())
            {
                for (std::pair<int, int> movingMarkPosition : movingMarkPositions)
                {
                    for (Actor* actor : actors)
                    {
                        if (actor->Position() == BoardCoordToPosition(movingMarkPosition.second, movingMarkPosition.first))
                        {
                            MovingMark* movingMark = dynamic_cast<MovingMark*>(actor);
                            movingMark->SetActive(true);
                        }
                    }
                }
            }
        }

        // Select a space that is not piece
        else if (board[selectedPieceIndex.xpos][selectedPieceIndex.ypos] == -1)
        {
            for (Actor* actor : actors)
            {
                if (actor->Position() == BoardCoordToPosition(selectedPieceIndex.ypos, selectedPieceIndex.xpos))
                {
                    // Select STAR (MOVE)
                    if (actor->IsActive())
                    {
                        Vector2 startpoint = currentPiece->Position();
                        Vector2 destination = BoardCoordToPosition(selectedPieceIndex.ypos, selectedPieceIndex.xpos);

                        currentPiece->SetPosition(destination);
                        currentPiece->SetColor(Color::White);

                        // Update Board
                        if (startpoint != destination)
                        {
                            board[PositionToBoardCoord(destination).ypos][PositionToBoardCoord(destination).xpos] =
                                board[PositionToBoardCoord(startpoint).ypos][PositionToBoardCoord(startpoint).xpos];

                            board[PositionToBoardCoord(startpoint).ypos][PositionToBoardCoord(startpoint).xpos] = -1;
                        }

                        for (Actor* temp : actors)
                        {
                            if (typeid(*temp).name() == typeid(MovingMark).name() &&
                                temp->Position() == destination)
                            {
                                temp->SetPosition(startpoint);
                            }
                        }
                    }
                    else
                    {
                        if (currentPiece != nullptr)
                        {
                            currentPiece->SetColor(Color::White);
                            currentPiece = nullptr;
                            catchablePositions = {};
                            movingMarkPositions = {};
                        }
                    }

                    for (std::pair<int, int> catchablePosition : catchablePositions)
                    {
                        for (Actor* actor : actors)
                        {
                            if (actor->IsActive() &&
                                actor->Position() == BoardCoordToPosition(catchablePosition.second, catchablePosition.first))
                            {
                                Piece* catchablePiece = dynamic_cast<Piece*>(actor);
                                if (catchablePiece)
                                {
                                    catchablePiece->SetColor(Color::White);
                                }
                            }
                        }
                    }

                    isSelected = false;
                    DeactivateMovingMark();
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

Vector2 GameplayLevel::BoardCoordToPosition(int xpos, int ypos)
{
    return Vector2((xpos * 4) + 2, (ypos * 2) + 1);
}

Vector2 GameplayLevel::PositionToBoardCoord(Vector2 position)
{
    return Vector2((position.xpos - 2) / 4, (position.ypos - 1) / 2);
}

void GameplayLevel::DeactivateMovingMark()
{
    for (Actor* actor : actors)
    {
        if (typeid(*actor).name() == typeid(MovingMark).name())
        {
            actor->SetActive(false);
        }
    }
}