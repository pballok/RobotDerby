#ifndef RDCORE_GAME_H
#define RDCORE_GAME_H

#include "board.h"

#include <string>

class Player;

class Game
{
public:
  Game(std::size_t board_size_x, std::size_t board_size_y) noexcept;
  Game(const Game& other) = delete;
  Game(Game&& other) = delete;
  Game& operator=(const Game& other) = delete;
  Game& operator+(Game&& other) = delete;
  ~Game() = default;

private:
  Board board_;
};

#endif // RDCORE_GAME_H
