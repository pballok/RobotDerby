#ifndef RDCORE_ROBOT_H
#define RDCORE_ROBOT_H

#include <string>

enum class Direction;

class Robot
{
public:
  enum class State { Active, Rebooting };

  Robot(std::string&& name, Direction starting_direction) noexcept;
  Robot(const Robot& other) = default;
  Robot(Robot&& other) = default;
  Robot& operator=(const Robot& other) = delete;
  Robot& operator=(Robot&& other) = delete;
  virtual ~Robot() = default;

  State state() const noexcept { return state_; }

  void turn(TurnDirection direction) noexcept;
  void turn_to(Direction direction) noexcept { direction_ = direction; }
  Direction direction() const noexcept { return direction_; }

  void reboot(Direction starting_direction) noexcept;

private:
  std::string name_;
  State state_;
  Direction direction_;
};

#endif // RDCORE_ROBOT_H
