#include "game.h"
#include "robot.h"

#include <memory>

Game::Game(std::size_t board_size_x, std::size_t board_size_y)
  : board_(board_size_x, board_size_y)
{
}

void Game::new_robot(std::string robot_name, Board::position_type starting_position, Direction starting_direction)
{
  robots_.emplace_back(robot_name, starting_position, starting_direction);
}
