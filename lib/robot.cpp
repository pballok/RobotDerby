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
  turn_to_direction(starting_direction);
}
