#include "game.h"
#include <iostream>
#include <string>

const Color COLOR_GREY = {29, 29, 27, 255};
const Color COLOR_YELLOW = {243, 216, 63, 255};
const int offset = 50;
const int SCREEN_HEIGHT = 1280;
const int SCREEN_WIDTH = 640;

std::string FormatWithLeadingZeros(int number, int width)
{
    std::string numberText = std::to_string(number);
    int leadingZeros = width - numberText.length();
    numberText = std::string(leadingZeros, '0') + numberText;
    return numberText;
}

int main()
{
    std::cout << "C++ Space Invaders" << std::endl;

    InitWindow(SCREEN_HEIGHT, SCREEN_WIDTH, "C++ Space Invaders");
    InitAudioDevice();

    Font font = LoadFontEx("assets/fonts/monogram.ttf", 64, 0, 0);
    Texture2D spaceshipImage = LoadTexture("assets/star_wars_naboo_ship.png");

    SetTargetFPS(60);

    Game game;

    while (!WindowShouldClose())
    {
        UpdateMusicStream(game.music);

        game.HandleInput();
        game.Update();

        BeginDrawing();

        ClearBackground(COLOR_GREY);

        DrawRectangleRoundedLines({10, 10, 1260, 620}, 0.18f, 20, 2, COLOR_YELLOW);
        DrawLineEx({50, 560}, {1225, 560}, 3, COLOR_YELLOW);

        if (game.run)
        {
            DrawText("LEVEL 01", 1075, 580, 34, COLOR_YELLOW);
        }
        else
        {
            DrawText("GAME OVER", 1025, 580, 34, COLOR_YELLOW);
        }

        float x = 50.0;
        for (int i = 0; i < game.lives; i++)
        {
            DrawTextureV(spaceshipImage, {x, 570}, WHITE);
            x += 50;
        }

        DrawTextEx(font, "SCORE", {55, 25}, 34, 2, COLOR_YELLOW);
        std::string scoreText = FormatWithLeadingZeros(game.score, 5);
        DrawTextEx(font, scoreText.c_str(), {185, 25}, 34, 2, COLOR_YELLOW);

        DrawTextEx(font, "HIGH-SCORE", {885, 25}, 34, 2, COLOR_YELLOW);
        std::string highScoreText = FormatWithLeadingZeros(game.highScore, 5);
        DrawTextEx(font, highScoreText.c_str(), {1115, 25}, 34, 2, COLOR_YELLOW);

        DrawLineEx({50, 70}, {1225, 70}, 3, COLOR_YELLOW);

        game.Draw();

        DrawFPS(10, 10);

        EndDrawing();
    }

    CloseAudioDevice();
    CloseWindow();

    return 0;
}
