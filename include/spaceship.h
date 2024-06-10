#ifndef SPACESHIP_H
#define SPACESHIP_H

#include <raylib.h>
#include <vector>

#include "laser.h"

class Spaceship
{
  public:
    Spaceship();
    ~Spaceship();
    void Draw();
    void MoveLeft();
    void MoveRight();
    void FireLaser();
    Rectangle getRect();
    void Reset();

    std::vector<Laser> lasers;

  private:
    Texture2D image;
    Vector2 position;
    double lastFireTime;
    Sound laserSound;
};

#endif // SPACESHIP_H
