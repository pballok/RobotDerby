#ifndef RDCORE_BOARD_H
#define RDCORE_BOARD_H

#include "direction.h"
#include "robot.h"
#include "tile.h"

#include <memory>
#include <vector>

enum class Direction;

class Board
{
public:
  using position_type = std::size_t;
  using robot_index_type = std::size_t;

  Board(std::size_t size_x, std::size_t size_y) noexcept;
  Board(const Board& other) = delete;
  Board(Board&& other) = delete;
  Board& operator=(const Board& other) = delete;
  Board& operator=(Board&& other) = delete;
  virtual ~Board() = default;

  position_type invalidPositionIndex() const noexcept { return invalid_position_index_; }
  position_type neighbour(position_type position_index, Direction direction) const noexcept;
  void placeWall(position_type position_index, Direction direction) noexcept;
  bool wallPresent(position_type position_index, Direction direction) const noexcept;

  void removeFloor(position_type position_index) noexcept;

  void placeGear(position_type position_index, TurnDirection direction) noexcept;

  robot_index_type placeNewRobot(std::string&& name, position_type starting_position, Direction starting_direction);
  position_type moveRobot(robot_index_type robot_index, unsigned int number_of_steps, Direction direction) noexcept;
  position_type robotPosition(robot_index_type robot_index) const noexcept;
  Robot* robotWithIndex(robot_index_type robot_index) noexcept;

private:

  struct PlacedRobot
  {
    PlacedRobot(std::string&& name, position_type starting_position, Direction starting_direction)
      : robot(std::make_unique<Robot>(std::move(name), starting_direction)),
        position(starting_position) {}
    std::unique_ptr<Robot> robot;
    position_type          position;
  };

  std::size_t size_x_;
  const position_type invalid_position_index_;
  std::vector<Tile> tiles_;
  std::vector<PlacedRobot> robots_;

  void placeSingleWall(position_type position_index, Direction direction) noexcept;
  void placeRobot(robot_index_type robot_index, position_type position_index) noexcept;
};

#endif // RDCORE_BOARD_H
