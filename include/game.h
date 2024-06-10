#ifndef GAME_H
#define GAME_H

#include "alien.h"
#include "laser.h"
#include "mysteryship.h"
#include "obstacle.h"
#include "spaceship.h"
#include <vector>

class Game
{
  public:
    Game();
    ~Game();

    void Draw();
    void Update();
    void HandleInput();

    bool run;
    int lives;
    int score;
    int highScore;
    Music music;

  private:
    Spaceship spaceship;
    std::vector<Obstacle> obstacles;
    std::vector<Alien> aliens;
    std::vector<Laser> alienLasers;
    int aliensDirection;
    constexpr static float alienLaserShootInterval = 0.35;
    float timeLastAlienFired;
    MysteryShip mysteryShip;
    float mysteryShipSpawnInterval;
    float timeLastSpawn;

    void DeleteInactiveLasers();
    void MoveAliens();
    void MoveDownAliens(int distance);
    void AlienShootLaser();
    void CheckForCollisions();
    void GameOver();
    void Reset();
    void InitGame();
    void checkForHighscore();
    void saveForHighscore(int highscore);
    int loadHighscoreFromFile();
    std::vector<Obstacle> CreateObstacles();
    std::vector<Alien> CreateAliens();
    
    Sound explosionSound;
};

#endif // GAME_H
