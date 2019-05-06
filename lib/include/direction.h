#ifndef RDCORE_DIRECTION_H
#define RDCORE_DIRECTION_H

enum class Direction {
  North,
  East,
  South,
  West
};

Direction opposite_direction(Direction);

#endif // RDCORE_DIRECTION_H