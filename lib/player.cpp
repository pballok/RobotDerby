#include "player.h"

#include <utility>

Player::Player(std::string&& robot_name, std::size_t robot_starting_position, Direction robot_starting_direction) noexcept
  : robot_(std::forward<std::string>(robot_name), robot_starting_position, robot_starting_direction)
{
}
