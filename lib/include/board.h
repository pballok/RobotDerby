#ifndef RDCORE_BOARD_H
#define RDCORE_BOARD_H

#include "direction.h"
#include "tile.h"

#include <vector>

class Robot;

class Board
{
public:
  using position_type = std::size_t;

  Board(std::size_t size_x, std::size_t size_y) noexcept;
  Board(const Board& other) noexcept = delete;
  Board(Board&& other) noexcept = delete;
  Board& operator=(const Board& other) noexcept = delete;
  Board& operator=(Board&& other) noexcept = delete;
  virtual ~Board() = default;

  position_type invalid_index() const noexcept { return tiles_.size(); }
  position_type neighbour(position_type index, Direction direction) const noexcept;
  void place_wall(position_type index, Direction direction) noexcept;
  bool wall_present(position_type index, Direction direction) const noexcept;
  void remove_floor(position_type index) noexcept;

  void move_robot(Robot& robot, unsigned int number_of_steps, Direction direction) const noexcept;

private:
  std::size_t size_x_;
  std::vector<Tile> tiles_;

  void place_single_wall(position_type index, Direction direction) noexcept;
};

#endif // RDCORE_BOARD_H
