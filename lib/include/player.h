#ifndef RDCORE_PLAYER_H
#define RDCORE_PLAYER_H

#include <string>

#include "direction.h"
#include "robot.h"

class Player
{
public:
  Player(std::string&& robot_name, std::size_t robot_starting_position, Direction robot_starting_direction) noexcept;
  Player(const Player& other) = default;
  Player(Player&& other) = default;
  Player& operator=(const Player& other) = delete;
  Player& operator+(Player&& other) = delete;
  ~Player() = default;

private:
  Robot robot_;
};

#endif // RDCORE_PLAYER_H
