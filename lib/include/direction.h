#ifndef RDCORE_DIRECTION_H
#define RDCORE_DIRECTION_H

enum class Direction {
  North,
  East,
  South,
  West
};

Direction opposite_direction(Direction direction) noexcept;
Direction clockwise_direction(Direction direction) noexcept;
Direction counter_clockwise_direction(Direction direction) noexcept;

enum class TurnDirection {
  Clockwise,
  CounterClockwise,
  UTurn
};
#endif // RDCORE_DIRECTION_H
