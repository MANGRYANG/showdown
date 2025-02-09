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
*/

GameplayLevel::GameplayLevel()
    : mousePos{0, 0}, consoleRect{0, 0, 0, 0}, selectedPieceIndex(-1, -1), isChessTurn(true)
{
    for (int row = 0; row < 9; ++row)
    {
        for (int col = 0; col < 9; ++col)
        {
            board[row][col] = -1;
        }
    }

    GetAsyncKeyState(VK_LBUTTON);
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
    }

    OUT_OF_LOOP:

    // Chess piece is selected
    if (isChessTurn &&
        board[selectedPieceIndex.xpos][selectedPieceIndex.ypos] >= 0 &&
        board[selectedPieceIndex.xpos][selectedPieceIndex.ypos] <= 6)
    {

    }

    // Janggi piece is selected
    else if (!isChessTurn &&
        board[selectedPieceIndex.xpos][selectedPieceIndex.ypos] >= 7 &&
        board[selectedPieceIndex.xpos][selectedPieceIndex.ypos] <= 13)
    {

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

Vector2 GameplayLevel::BoardPositionToLocation(int xpos, int ypos)
{
    return Vector2((xpos * 4) + 2, ypos * 2 + 1);
}
