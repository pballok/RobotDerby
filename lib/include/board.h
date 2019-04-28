#ifndef RDCORE_BOARD_H
#define RDCORE_BOARD_H

#include "direction.h"

#include <vector>

class Board
{
public:
    Board(std::size_t size_x, std::size_t size_y) noexcept;
    Board(const Board& other) noexcept = delete;
    Board(Board&& other) noexcept = delete;
    Board& operator=(const Board& other) noexcept = delete;
    Board& operator+(Board&& other) noexcept = delete;
    virtual ~Board() = default;

    std::size_t invalid_index() const noexcept;
    std::size_t neighbour(std::size_t index, Direction direction) const noexcept;

private:
    std::size_t size_x_;
    std::size_t invalid_index_;
};

#endif // RDCORE_BOARD_H