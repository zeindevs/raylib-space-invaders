#include "alien.h"

Texture2D Alien::alienImages[3] = {};

Alien::Alien(int type, Vector2 position)
{
    this->type = type;
    this->position = position;

    if (alienImages[type - 1].id == 0)
    {
        switch (type)
        {
        case 1:
            alienImages[0] = LoadTexture("assets/martian.png");
            break;
        case 2:
            alienImages[1] = LoadTexture("assets/andorian_head.png");
            break;
        case 3:
            alienImages[2] = LoadTexture("assets/predator.png");
            break;
        default:
            alienImages[0] = LoadTexture("assets/alien.png");
            break;
        }
    }
}

Alien::~Alien()
{
}

void Alien::Draw()
{
    DrawTextureV(alienImages[type - 1], position, WHITE);
}

void Alien::Update(int direction)
{
    position.x += direction;
}

int Alien::GetType()
{
    return type;
}

Rectangle Alien::getRect()
{
    return {position.x, position.y, float(alienImages[type - 1].width), float(alienImages[type - 1].height)};
}

void Alien::UnloadImages()
{
    for (int i = 0; i < 3; i++)
    {
        UnloadTexture(alienImages[i]);
    }
}
