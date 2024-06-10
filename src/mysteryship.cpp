#include "mysteryship.h"

MysteryShip::MysteryShip()
{
    image = LoadTexture("assets/ufo.png");
    alive = false;
}

MysteryShip::~MysteryShip()
{
    UnloadTexture(image);
}

void MysteryShip::Draw()
{
    if (alive)
    {
        DrawTextureV(image, position, WHITE);
    }
}

void MysteryShip::Update()
{
    if (alive)
    {
        position.x += speed;
        if (position.x > GetScreenWidth() - image.width - 25 || position.x < 25)
        {
            alive = false;
        }
    }
}

void MysteryShip::Spawn()
{
    position.y = 0;
    int side = GetRandomValue(0, 1);

    if (side == 0)
    {
        position.x = 25;
        speed = 3;
    }
    else
    {
        position.x = GetScreenWidth() - image.width - 25;
        speed = -3;
    }

    alive = true;
}

Rectangle MysteryShip::getRect()
{
    if (alive)
    {
        return {position.x, position.y, float(image.width), float(image.height)};
    }
    else
    {
        return {position.x, position.y, 0, 0};
    }
}
