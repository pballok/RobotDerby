#include "board.h"

Board::Board(std::size_t size_x, std::size_t size_y) noexcept
    : size_x_(size_x),
      invalid_index_(size_x * size_y)
{

}


std::size_t Board::invalid_index() const noexcept
{
    return invalid_index_;
}


std::size_t Board::neighbour(std::size_t index, Direction direction) const noexcept
{
    if (index >= invalid_index_ || invalid_index_ <= 1) {
        return invalid_index_;
    }

    switch(direction) {
    case Direction::North:
        return (index >= size_x_ ? index - size_x_ : invalid_index_);
    case Direction::East:
        return (index % size_x_ < size_x_ - 1 ? index + 1 : invalid_index_);
    case Direction::South:
        return (index < invalid_index_ - size_x_ ? index + size_x_ : invalid_index_);
    case Direction::West:
        return (index % size_x_ != 0 ? index - 1 : invalid_index_);
    default:
        return invalid_index_;

    }
}
