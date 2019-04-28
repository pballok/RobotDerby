#ifndef RDCORE_BOARD_H
#define RDCORE_BOARD_H

#include "direction.h"
#include "tile.h"

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

    std::size_t invalid_index() const noexcept { return tiles_.size(); }
    std::size_t neighbour(std::size_t index, Direction direction) const noexcept;
    void place_wall(std::size_t index, Direction direction) noexcept;
    bool wall_present(std::size_t index, Direction direction) const noexcept;

private:
    std::size_t size_x_;
    std::vector<Tile> tiles_;

    void place_single_wall(std::size_t index, Direction direction) noexcept;
};

#endif // RDCORE_BOARD_H