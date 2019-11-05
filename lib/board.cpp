#include "board.h"
#include "robot.h"

Board::Board(std::size_t size_x, std::size_t size_y) noexcept
  : size_x_(size_x),
    tiles_(size_x * size_y)
{

}


Board::position_type Board::neighbour(Board::position_type index, Direction direction) const noexcept
{
  if (index >= invalid_index() || invalid_index() <= 1) {
    return invalid_index();
  }

  switch (direction) {
    case Direction::North:
      return (index >= size_x_ ? index - size_x_ : invalid_index());
    case Direction::East:
      return (index % size_x_ < size_x_ - 1 ? index + 1 : invalid_index());
    case Direction::South:
      return (index < invalid_index() - size_x_ ? index + size_x_ : invalid_index());
    case Direction::West:
      return (index % size_x_ != 0 ? index - 1 : invalid_index());
    default:
      // No other direction possible
      return index;
  }
}


void Board::place_wall(Board::position_type index, Direction direction) noexcept
{
  place_single_wall(index, direction);
  place_single_wall(neighbour(index, direction), opposite_direction(direction));
}


bool Board::wall_present(Board::position_type index, Direction direction) const noexcept
{
  if (index >= invalid_index()) {
    return false;
  }

  return tiles_.at(index).has_wall(direction);
}


void Board::remove_floor(position_type index) noexcept
{
  if (index < invalid_index()) {
    tiles_.at(index).remove_floor();
  }
}


void Board::place_gear(position_type index, TurnDirection direction) noexcept
{
  if (index < invalid_index()) {
    tiles_.at(index).place_gear(direction);
  }
}


void Board::move_robot(Robot& robot, unsigned int number_of_steps, Direction direction) const noexcept
{
  for (unsigned int i = 0; i < number_of_steps; ++i) {
    if (tiles_.at(robot.position()).has_wall(direction)) {
      return;
    }

    auto new_position = neighbour(robot.position(), direction);
    if (new_position == invalid_index() || !tiles_.at(new_position).has_floor()) {
      robot.reboot(0, Direction::North);
      return;
    }

    robot.move_to(new_position);
  }
}


void Board::place_single_wall(Board::position_type index, Direction direction) noexcept
{
  if (index >= invalid_index()) {
    return;
  }

  tiles_.at(index).place_wall(direction);
}
