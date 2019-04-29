#include "prcardmove.h"

#include "board.h"
#include "robot.h"

PrCardMove::PrCardMove(Board& board, Robot& robot, std::size_t move_amount) noexcept
    : ProgrammingCard(board, robot),
      move_amount_(move_amount)
{

}


void PrCardMove::execute() noexcept
{
    board_.move_robot(robot_, move_amount_, robot_.direction());
}