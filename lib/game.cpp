#include "game.h"
#include "player.h"

Game::Game(std::size_t board_size_x, std::size_t board_size_y) noexcept
  : board_(board_size_x, board_size_y)
{
}

void Game::new_player(std::string robot_name, Board::position_type starting_position, Direction starting_direction)
{
  players_.emplace_back(std::move(robot_name), starting_position, starting_direction);
}
