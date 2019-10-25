#ifndef RDCORE_GAME_H
#define RDCORE_GAME_H

#include "board.h"

#include <string>
#include <vector>

class Robot;

class Game
{
public:
  Game(std::size_t board_size_x, std::size_t board_size_y) noexcept;
  ~Game() = default;
  Game(const Game& other) noexcept = delete;
  Game(Game&& other) noexcept = delete;
  Game& operator=(const Game& other) noexcept = delete;
  Game& operator+(Game&& other) noexcept = delete;

  const Board& board() const { return board_; }

  void new_robot(std::string robot_name, Board::position_type starting_position, Direction starting_direction);

private:
  Board board_;
  std::vector<std::unique_ptr<Robot>> robots_;
};

#endif // RDCORE_GAME_H
