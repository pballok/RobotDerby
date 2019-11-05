#include "prcardturn.h"

#include "robot.h"

PrCardTurn::PrCardTurn(Robot& robot, TurnDirection direction) noexcept
  : ProgrammingCard(robot),
    direction_(direction)
{
}

void PrCardTurn::execute() noexcept
{
  robot_.turn(direction_);
}
