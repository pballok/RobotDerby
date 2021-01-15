#include "direction.h"
#include "robot.h"

// cppcheck-suppress passedByValue
Robot::Robot(std::string&& name, Direction starting_direction) noexcept
  : name_(std::move(name)),
    state_(State::Active),
    direction_(starting_direction)
{
}

void Robot::reboot(Direction starting_direction) noexcept
{
  turn_to(starting_direction);
  state_ = State::Rebooting;
}

void Robot::turn(TurnDirection direction) noexcept
{
  switch(direction) {
    case TurnDirection::Clockwise:
      direction_ = clockwise_direction(direction_);
      break;

    case TurnDirection::CounterClockwise:
      direction_ = counter_clockwise_direction(direction_);
      break;

    case TurnDirection::UTurn:
      direction_ = opposite_direction(direction_);
      break;

    default:
      break;
  }
}
