#ifndef RDCORE_GAME_H
#define RDCORE_GAME_H

#include "board.h"

#include <string>
#include <vector>

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

  const Board& board() const { return board_; }

  void new_player(std::string robot_name, Board::position_type starting_position, Direction starting_direction);

private:
  Board board_;
  std::vector<Player> players_;
};

#endif // RDCORE_GAME_H
