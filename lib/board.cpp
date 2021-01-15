#include "board.h"
#include "robot.h"

#include <memory>

Board::Board(std::size_t size_x, std::size_t size_y) noexcept
  : size_x_(size_x),
    invalid_position_index_(size_x * size_y),
    tiles_(invalid_position_index_)
{

}


Board::position_type Board::neighbour(Board::position_type position_index, Direction direction) const noexcept
{
  if (position_index >= invalid_position_index_ || invalid_position_index_ <= 1) {
    return invalid_position_index_;
  }

  switch (direction) {
    case Direction::North:
      return (position_index >= size_x_ ? position_index - size_x_ : invalid_position_index_);
    case Direction::East:
      return (position_index % size_x_ < size_x_ - 1 ? position_index + 1 : invalid_position_index_);
    case Direction::South:
      return (position_index < invalid_position_index_ - size_x_ ? position_index + size_x_ : invalid_position_index_);
    case Direction::West:
      return (position_index % size_x_ != 0 ? position_index - 1 : invalid_position_index_);
    default:
      // No other direction possible
      return position_index;
  }
}


void Board::placeWall(Board::position_type position_index, Direction direction) noexcept
{
  placeSingleWall(position_index, direction);
  placeSingleWall(neighbour(position_index, direction), opposite_direction(direction));
}


bool Board::wallPresent(Board::position_type position_index, Direction direction) const noexcept
{
  if (position_index >= invalid_position_index_) {
    return false;
  }

  return tiles_.at(position_index).hasWall(direction);
}


void Board::removeFloor(position_type position_index) noexcept
{
  if (position_index < invalid_position_index_) {
    tiles_.at(position_index).removeFloor();
  }
}


void Board::placeGear(position_type position_index, TurnDirection direction) noexcept
{
  if (position_index < invalid_position_index_) {
    tiles_.at(position_index).placeGear(direction);
  }
}

Board::robot_index_type Board::placeNewRobot(std::string&& name, position_type starting_position, Direction starting_direction)
{
  robots_.emplace_back(std::move(name), starting_position, starting_direction);
  return robots_.size();
}


Board::position_type Board::moveRobot(robot_index_type robot_index, unsigned int number_of_steps, Direction direction) noexcept
{
  auto current_position = robotPosition(robot_index);
  if(current_position == invalid_position_index_) {
    return invalid_position_index_;
  }

  for (unsigned int i = 0; i < number_of_steps; ++i) {
    if (tiles_.at(current_position).hasWall(direction)) {
      return current_position;
    }

    auto new_position = neighbour(current_position, direction);
    auto r = robotWithIndex(robot_index);
    if (new_position == invalid_position_index_ || !tiles_.at(new_position).hasFloor()) {
      r->reboot(Direction::North);
      placeRobot(robot_index, 0);  // Reboot token position goes here
      return 0;  // Reboot token position goes here
    }

    placeRobot(robot_index, new_position);
    current_position = new_position;
  }

  return current_position;
}


Board::position_type Board::robotPosition(robot_index_type robot_index) const noexcept
{
  if(robot_index == 0 || robot_index > robots_.size()) {
    return invalid_position_index_;
  }

  return robots_.at(robot_index - 1).position;
}


Robot* Board::robotWithIndex(robot_index_type robot_index) noexcept
{
  if(robot_index == 0 || robot_index > robots_.size()) {
    return nullptr;
  }

  return robots_.at(robot_index - 1).robot.get();
}


void Board::placeSingleWall(Board::position_type position_index, Direction direction) noexcept
{
  if (position_index >= invalid_position_index_) {
    return;
  }

  tiles_.at(position_index).placeWall(direction);
}


void Board::placeRobot(robot_index_type robot_index, position_type position_index) noexcept
{
  if(robot_index == 0 || robot_index > robots_.size()) {
    return;
  }

  if (position_index >= invalid_position_index_) {
    return;
  }

  robots_.at(robot_index - 1).position = position_index;
}
