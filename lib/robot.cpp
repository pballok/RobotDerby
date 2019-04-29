#include "robot.h"

Robot::Robot(std::string name) noexcept
    : name_(std::move(name)),
      position_on_board_(0),
      direction_(Direction::North)
{

}

void Robot::reboot() noexcept
{
    set_position(0);
    set_direction(Direction::North);
}