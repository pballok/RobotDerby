#include "prcardturn.h"

#include "board.h"
#include "robot.h"

// cppcheck-suppress constParameter
PrCardTurn::PrCardTurn(Board& board, Board::robot_index_type robot_index, TurnDirection direction) noexcept
  : ProgrammingCard(board, robot_index),
    direction_(direction)
{
}

void PrCardTurn::execute() noexcept
{
  auto* robot = board_.robotWithIndex(robot_index_);
  if(robot == nullptr) {
    return;
  }

  robot->turn(direction_);
}
