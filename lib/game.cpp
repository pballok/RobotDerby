#include "game.h"

Game::Game(std::size_t board_size_x, std::size_t board_size_y) noexcept
  : board_(board_size_x, board_size_y)
{
}
