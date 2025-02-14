#include "GameplayLevel.h"

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

    timerThread = std::thread(&GameplayLevel::TimerFunction, this);

    GameplayLevel::AddActor(new Text("Time [", firstTimeMessagePosition));
    GameplayLevel::AddActor(new Text("Time [", secondTimeMessagePosition));

    GameplayLevel::AddActor(new Text("PALACE ", isForward ?
        Vector2(firstTimeMessagePosition.xpos + 7, firstTimeMessagePosition.ypos) :
        Vector2(secondTimeMessagePosition.xpos + 7, secondTimeMessagePosition.ypos), Color::Magenta));
    GameplayLevel::AddActor(new Text("KINGDOM", isForward ?
        Vector2(secondTimeMessagePosition.xpos + 7, secondTimeMessagePosition.ypos) :
        Vector2(firstTimeMessagePosition.xpos + 7, firstTimeMessagePosition.ypos), Color::Cyan));

    GameplayLevel::AddActor(new Text("]",
        Vector2(firstTimeMessagePosition.xpos + 15, firstTimeMessagePosition.ypos)));
    GameplayLevel::AddActor(new Text("]",
        Vector2(secondTimeMessagePosition.xpos + 15, secondTimeMessagePosition.ypos)));

    GameplayLevel::AddActor(&firstText);
    GameplayLevel::AddActor(&secondText);

    GameplayLevel::AddActor(new Text("９", isForward ?
        Vector2(secondTimeMessagePosition.xpos + 33, secondTimeMessagePosition.ypos) :
        Vector2(firstTimeMessagePosition.xpos + 33, firstTimeMessagePosition.ypos), Color::Yellow));

    GameplayLevel::ProcessAddedAndDestroyedActor();

    GetAsyncKeyState(VK_LBUTTON & 1);
}

GameplayLevel::~GameplayLevel()
{
    timeLimitForChess = false;
    if (timerThread.joinable()) {
        timerThread.join();
    }
}

void GameplayLevel::Update(float deltaTime)
{
    Super::Update(deltaTime);

    GetWindowRect(consoleWindow, &consoleRect);

    // Game is over
    if (!isLevelStopped)
    {
        if(!IsGameOver())
        {
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
                                    SetNotationDefault(ActorPositionToBoardCoord(currentPiece->GetPosition()), selectedBoardCoord, true);
                                    CatchEnemyPiece(selectedBoardCoord);
                                    Promotion();
                                    CheckStatusSetting();
                                    PrintNotation();

                                    isChessTurn = !isChessTurn;

                                    SetTrianglePosition();
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
                                    SetNotationDefault(ActorPositionToBoardCoord(currentPiece->GetPosition()), selectedBoardCoord, false);
                                    MovePiece(selectedBoardCoord);
                                    Promotion();
                                    CheckStatusSetting();
                                    PrintNotation();

                                    isChessTurn = !isChessTurn;

                                    SetTrianglePosition();
                                }
                            }

                            InitializeBoard();
                        }
                    }
                }
            }
        }

        else
        {
            isLevelStopped = true;

            GameplayLevel::AddActor(new Text("< GAME OVER >", gameOverMessagePosition));

            GameplayLevel::AddActor(new Text("Winner: ", TextLinePositionSetting(1, gameOverMessagePosition)));

            if (isChessWin)
            {
                GameplayLevel::AddActor(new Text("KINGDOM",
                    Vector2(TextLinePositionSetting(1, gameOverMessagePosition).xpos + 8,
                        TextLinePositionSetting(1, gameOverMessagePosition).ypos), Color::Cyan));
            }
            else
            {
                GameplayLevel::AddActor(new Text("PALACE",
                    Vector2(TextLinePositionSetting(1, gameOverMessagePosition).xpos + 8, 
                        TextLinePositionSetting(1, gameOverMessagePosition).ypos), Color::Magenta));
            }

            GameplayLevel::AddActor(new Text("Team",
                Vector2(TextLinePositionSetting(1, gameOverMessagePosition).xpos + 16,
                    TextLinePositionSetting(1, gameOverMessagePosition).ypos)));

            GameplayLevel::ProcessAddedAndDestroyedActor();
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

    for (int i = 0; i < 4; ++i)
    {
        Engine::Get().Render(Vector2(39, 21 + i), "弛", Color::White);
    }
    Engine::Get().Render(Vector2(0, 25), "_______________________________________/", Color::White);

}

void GameplayLevel::InitializeBoard()
{
    for (Actor* actor : actors)
    {
        Piece* tempPieceActor = dynamic_cast<Piece*>(actor);
        MovingMark* tempMarkActor = dynamic_cast<MovingMark*>(actor);

        if (tempPieceActor != nullptr)
        {
            tempPieceActor->SetColor(Color::White);
        }

        else if (tempMarkActor != nullptr)
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
            actor->GetPosition() == consolePosition)
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
                actor->GetPosition() == BoardCoordToActorPosition(reachablePieceCoord))
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
                actor->GetPosition() == BoardCoordToActorPosition(catchablePieceCoord))
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
        if (actor->GetPosition() == destinationPosition)
        {
            Vector2 currentPieceCoord = ActorPositionToBoardCoord(currentPiece->GetPosition());
           
            // Update Board
            int temp = board[destinationCoord.xpos][destinationCoord.ypos];

            board[destinationCoord.xpos][destinationCoord.ypos] =
                board[currentPieceCoord.xpos][currentPieceCoord.ypos];

            board[currentPieceCoord.xpos][currentPieceCoord.ypos] = temp;

            // Move piece
            actor->SetPosition(currentPiece->GetPosition());
            currentPiece->SetPosition(destinationPosition);

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
        if (actor->GetPosition() == destinationPosition)
        {
            Vector2 currentPieceCoord = ActorPositionToBoardCoord(currentPiece->GetPosition());

            // Update Board
            board[destinationCoord.xpos][destinationCoord.ypos] =
                board[currentPieceCoord.xpos][currentPieceCoord.ypos];

            board[currentPieceCoord.xpos][currentPieceCoord.ypos] = -1;

            // Catch enyme piece
            actor->Destroy();
            currentPiece->SetPosition(destinationPosition);
            GameplayLevel::AddActor(new MovingMark(BoardCoordToActorPosition(currentPieceCoord)));
            GameplayLevel::ProcessAddedAndDestroyedActor();

            break;
        }
    }
}

void GameplayLevel::SetNotationDefault(Vector2 startCoord, Vector2 endCoord, bool isCapture)
{
    currentNotation = "";

    switch (board[startCoord.xpos][startCoord.ypos])
    {
    case 0:
        currentNotation += "K";
        break;
    case 1:
        currentNotation += "Q";
        break;
    case 2:
        currentNotation += "R";
        break;
    case 3:
        currentNotation += "B";
        break;
    case 4:
        currentNotation += "N";
        break;
    case 5:
        if (isCapture)
        {
            currentNotation += ('a' + startCoord.ypos);
        }
        break;
    case 6:
        currentNotation += "J";
        break;

    case 7:
        currentNotation += "E";
        break;

    case 8:
        currentNotation += "C";
        break;

    case 9:
        currentNotation += "L";
        break;

    case 10:
        currentNotation += "H";
        break;

    case 11:
        currentNotation += "T";
        break;

    case 12:
        currentNotation += "S";
        break;

    case 13:
        currentNotation += "G";
        break;

    default:
        break;
    }

    if (isCapture)
    {
        currentNotation += "x";
    }
    
    currentNotation += ('a' + endCoord.ypos);
    currentNotation += ('9' - endCoord.xpos);
}

void GameplayLevel::PrintNotation()
{
    notationCounterText = std::to_string(notationCount + 1) + '.';

    int columnLineNumber = (notationCount / 10);
    int indexInLine = notationCount % 10;

    GameplayLevel::AddActor(new Text(notationCounterText.c_str(),
        Vector2(notationMessagePosition.xpos + (indexInLine * 10), notationMessagePosition.ypos + (columnLineNumber * 2)), Color::Yellow));

    GameplayLevel::AddActor(new Text(currentNotation.c_str(),
        Vector2(notationMessagePosition.xpos + 3 + (indexInLine * 10),
            notationMessagePosition.ypos + (columnLineNumber * 2))));

    GameplayLevel::ProcessAddedAndDestroyedActor();

    ++notationCount;
}


void GameplayLevel::Promotion()
{
    int lastRow;

    if (isForward)
    {
        lastRow = 0;
    }
    else
    {
        lastRow = 8;
    }

    for (int x = 0; x < 9; ++x)
    {
        if (board[lastRow][x] == 5)
        {
            Vector2 tempPawnPiecePosition = BoardCoordToActorPosition(Vector2(lastRow, x));

            for (Actor* actor : actors)
            {
                Piece* tempPieceActor = dynamic_cast<Piece*>(actor);
                if (tempPieceActor != nullptr &&
                    actor->GetPosition() == tempPawnPiecePosition)
                {
                    tempPieceActor->Destroy();
                    break;
                }
            }

            currentNotation += "=";

            INPUT_PROMOTIONTYPE:
            switch (_getch())
            {
            case 'Q':
            case 'q':
                GameplayLevel::AddActor(new Queen(tempPawnPiecePosition));
                currentNotation += "Q";
                board[lastRow][x] = 1;
                break;

            case 'R':
            case 'r':
                GameplayLevel::AddActor(new Rook(tempPawnPiecePosition));
                currentNotation += "R";
                board[lastRow][x] = 2;
                break;

            case 'B':
            case 'b':
                GameplayLevel::AddActor(new Bishop(tempPawnPiecePosition));
                currentNotation += "B";
                board[lastRow][x] = 3;
                break;

            case 'N':
            case 'n':
                GameplayLevel::AddActor(new Knight(tempPawnPiecePosition));
                currentNotation += "N";
                board[lastRow][x] = 4;
                break;
            default:
                goto INPUT_PROMOTIONTYPE;
            }

            GameplayLevel::ProcessAddedAndDestroyedActor();

            break;
        }
    }
}

void GameplayLevel::CheckStatusSetting()
{
    Vector2 currentCoord = ActorPositionToBoardCoord(currentPiece->GetPosition());

    if ((board[currentCoord.xpos][currentCoord.ypos] > 0 && board[currentCoord.xpos][currentCoord.ypos] < 6) ||
        (board[currentCoord.xpos][currentCoord.ypos] > 7 && board[currentCoord.xpos][currentCoord.ypos] < 13))
    {
        catchablePieceCoords = currentPiece->CatchablePieceCoord(board, selectedBoardCoord, isForward);
        for (Vector2 catchablePieceCoord : catchablePieceCoords)
        {
            if (board[catchablePieceCoord.xpos][catchablePieceCoord.ypos] == 0 ||
                board[catchablePieceCoord.xpos][catchablePieceCoord.ypos] == 7)
            {
                currentNotation += "+";
                break;
            }
        }
    }
}

void GameplayLevel::TimerFunction()
{
    while (timerRunning && !isLevelStopped)
    {
        // 0.01 second
        std::this_thread::sleep_for(std::chrono::milliseconds(10));

        if (isChessTurn) {
            timeLimitForChess -= 1.0;
            if (isForward)
            {
                secondText.SetText(DoubleToTime(timeLimitForChess).c_str());
            }
            else
            {
                firstText.SetText(DoubleToTime(timeLimitForChess).c_str());
            }
        }
        else {
            timeLimitForJanggi -= 1.0;
            if (isForward)
            {
                firstText.SetText(DoubleToTime(timeLimitForJanggi).c_str());
            }
            else
            {
                secondText.SetText(DoubleToTime(timeLimitForJanggi).c_str());
            }
        }

        if (timeLimitForChess <= 0) {
            timerRunning = false;
            isJanggiWin = true;
            break;
        }

        if (timeLimitForJanggi <= 0) {
            timerRunning = false;
            isChessWin = true;
            break;
        }
    }
}

void GameplayLevel::SetTrianglePosition()
{
    if (!isChessTurn)
    {
        for (Actor* actor : actors)
        {
            Text* tempTextActor = dynamic_cast<Text*>(actor);
            if (tempTextActor != nullptr &&
                tempTextActor->GetPosition() ==
                Vector2(secondTimeMessagePosition.xpos + 33, secondTimeMessagePosition.ypos))
            {
                tempTextActor->SetPosition(Vector2(firstTimeMessagePosition.xpos + 33, firstTimeMessagePosition.ypos));
            }
        }
    }
    else
    {
        for (Actor* actor : actors)
        {
            Text* tempTextActor = dynamic_cast<Text*>(actor);
            if (tempTextActor != nullptr &&
                tempTextActor->GetPosition() ==
                Vector2(firstTimeMessagePosition.xpos + 33, firstTimeMessagePosition.ypos))
            {
                tempTextActor->SetPosition(Vector2(secondTimeMessagePosition.xpos + 33, secondTimeMessagePosition.ypos));
            }
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
            actor->GetPosition() == consolePosition &&
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

bool GameplayLevel::IsGameOver()
{
    if (!timerRunning)
    {
        return true;
    }
    else
    {
        isChessWin = true;
        isJanggiWin = true;

        for (int row = 0; row < 9; ++row)
        {
            for (int col = 0; col < 9; ++col)
            {
                if (board[row][col] == 0)
                {
                    isJanggiWin = false;
                }
                if (board[row][col] == 7)
                {
                    isChessWin = false;
                }
            }
        }

        if (isChessWin || isJanggiWin)
        {
            return true;
        }

        return false;
    }

}

Vector2 GameplayLevel::BoardCoordToActorPosition(Vector2 boardCoord)
{
    return Vector2((boardCoord.ypos * 4) + 2, (boardCoord.xpos * 2) + 1);
}

Vector2 GameplayLevel::ActorPositionToBoardCoord(Vector2 actorPosition)
{
    return Vector2((actorPosition.ypos - 1) / 2, (actorPosition.xpos - 2) / 4);
}

Vector2 GameplayLevel::TextLinePositionSetting(int line, Vector2 startPosition)
{
    Vector2 result = startPosition;
    result.ypos += (line * 2);

    return result;
}

std::string GameplayLevel::DoubleToTime(double timeDouble)
{
    int tempTime = (int)timeDouble;
    std::string result = "0";

    result += std::to_string(tempTime / 6000);
    tempTime = tempTime % 6000;
    result += " : ";
    if ((tempTime / 100) < 10)
    {
        result += "0";
    }
    result += std::to_string(tempTime / 100);
    tempTime = tempTime % 100;
    result += " : ";
    if (tempTime < 10)
    {
        result += "0";
    }
    result += std::to_string(tempTime);

    return result;
}

