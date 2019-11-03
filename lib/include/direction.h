#ifndef RDCORE_DIRECTION_H
#define RDCORE_DIRECTION_H

enum class Direction {
  North,
  East,
  South,
  West
};

Direction opposite_direction(Direction direction);
Direction clockwise_direction(Direction direction);
Direction counter_clockwise_direction(Direction direction);

#endif // RDCORE_DIRECTION_H
