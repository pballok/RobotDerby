#ifndef RDCORE_ROBOT_H
#define RDCORE_ROBOT_H

#include "direction.h"

#include <string>

class Robot
{
public:
    explicit Robot(std::string name) noexcept;
    Robot(const Robot& other) noexcept = delete;
    Robot(Robot&& other) noexcept = delete;
    Robot& operator=(const Robot& other) noexcept = delete;
    Robot& operator=(Robot&& other) noexcept = delete;
    virtual ~Robot() = default;

    void set_position(std::size_t new_position) noexcept { position_on_board_ = new_position; }
    std::size_t position() const noexcept { return position_on_board_; }

    void set_direction(Direction direction) noexcept { direction_ = direction; }
    Direction direction() const noexcept { return direction_; }

    void reboot() noexcept;

private:
    std::string name_;
    std::size_t position_on_board_;
    Direction direction_;
};

#endif // RDCORE_ROBOT_H
