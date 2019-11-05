#include "direction.h"

Direction opposite_direction(Direction direction) noexcept
{
  switch (direction) {
    case Direction::North:
      return Direction::South;
    case Direction::East:
      return Direction::West;
    case Direction::South:
      return Direction::North;
    case Direction::West:
      return Direction::East;
    default:
      // No other directions possible
      return direction;
  }
}

Direction clockwise_direction(Direction direction) noexcept
{
  switch (direction) {
    case Direction::North:
      return Direction::East;
    case Direction::East:
      return Direction::South;
    case Direction::South:
      return Direction::West;
    case Direction::West:
      return Direction::North;
    default:
      // No other directions possible
      return direction;
  }
}

Direction counter_clockwise_direction(Direction direction) noexcept
{
  switch (direction) {
    case Direction::North:
      return Direction::West;
    case Direction::East:
      return Direction::North;
    case Direction::South:
      return Direction::East;
    case Direction::West:
      return Direction::South;
    default:
      // No other directions possible
      return direction;
  }
}
