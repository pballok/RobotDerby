#include "prcardmove.h"

#include "board.h"
#include "robot.h"

PrCardMove::PrCardMove(Board& board, Board::robot_index_type robot_index, std::size_t move_amount) noexcept
  : ProgrammingCard(board, robot_index),
    move_amount_(move_amount)
{
}

void PrCardMove::execute() noexcept
{
  auto robot = board_.robotWithIndex(robot_index_);
  if(robot == nullptr) {
    return;
  }

  board_.moveRobot(robot_index_, move_amount_, robot->direction());
}
