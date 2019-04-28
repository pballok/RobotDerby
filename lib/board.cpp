#include "board.h"

Board::Board(std::size_t size_x, std::size_t size_y) noexcept
    : size_x_(size_x),
    tiles_(size_x * size_y)
{

}


std::size_t Board::neighbour(std::size_t index, Direction direction) const noexcept
{
    if (index >= invalid_index() || invalid_index() <= 1) {
        return invalid_index();
    }

    switch(direction) {
    case Direction::North:
        return (index >= size_x_ ? index - size_x_ : invalid_index());
    case Direction::East:
        return (index % size_x_ < size_x_ - 1 ? index + 1 : invalid_index());
    case Direction::South:
        return (index < invalid_index() - size_x_ ? index + size_x_ : invalid_index());
    case Direction::West:
        return (index % size_x_ != 0 ? index - 1 : invalid_index());
    }
}


void Board::place_wall(std::size_t index, Direction direction) noexcept
{
    place_single_wall(index, direction);
    place_single_wall(neighbour(index, direction), opposite_direction(direction));
}


bool Board::wall_present(std::size_t index, Direction direction) const noexcept
{
    if (index >= invalid_index()) {
        return false;
    }

    return tiles_.at(index).has_wall(direction);
}


void Board::place_single_wall(std::size_t index, Direction direction) noexcept
{
    if (index >= invalid_index()) {
        return;
    }

    tiles_.at(index).place_wall(direction);
}
