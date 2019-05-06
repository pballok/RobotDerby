#include "direction.h"

Direction opposite_direction(Direction direction)
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
  }
}
