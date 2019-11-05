#include "direction.h"
#include "robot.h"

// cppcheck-suppress passedByValue
Robot::Robot(std::string name, std::size_t starting_position, Direction starting_direction) noexcept
  : name_(std::move(name)),
    position_on_board_(starting_position),
    direction_(starting_direction)
{
}

void Robot::reboot(std::size_t starting_position, Direction starting_direction) noexcept
{
  move_to(starting_position);
  turn_to(starting_direction);
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
