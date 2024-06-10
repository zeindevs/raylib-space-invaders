#include "block.h"

Block::Block(Vector2 position)
{
    this->position = position;
}

Block::~Block()
{
}

void Block::Draw()
{
    DrawRectangle(position.x, position.y, 3, 3, {243, 216, 64, 255});
}

Rectangle Block::getRect()
{
    return {position.x, position.y, 3, 3};
}
