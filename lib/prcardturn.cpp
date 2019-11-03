#include "prcardturn.h"

#include "robot.h"

PrCardTurn::PrCardTurn(Robot& robot, TurnCardType turn_type) noexcept
  : ProgrammingCard(robot),
    type_(turn_type)
{
}

void PrCardTurn::execute() noexcept
{
  switch(type_) {
    case TurnCardType::CLOCKWISE:
      robot_.turn_clockwise();
      break;
    case TurnCardType::COUNTER_CLOCKWISE:
      robot_.turn_counter_clockwise();
      break;
    case TurnCardType::U_TURN:
      robot_.turn_back();
      break;
  }
}
