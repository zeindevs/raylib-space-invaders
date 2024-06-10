#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "block.h"
#include <raylib.h>
#include <vector>

class Obstacle
{
  public:
    Obstacle(Vector2 position);
    ~Obstacle();

    void Draw();
    
    Vector2 position;
    std::vector<Block> blocks;
    static std::vector<std::vector<int>> grid;
};

#endif // OBSTACLE_H
