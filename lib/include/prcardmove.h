#ifndef RDCORE_PRCARDMOVE_H
#define RDCORE_PRCARDMOVE_H

#include "programmingcard.h"

#include <cstddef>

class Board;

class PrCardMove : public ProgrammingCard
{
public:
  PrCardMove(Board& board, Robot& robot, std::size_t move_amount) noexcept;
  PrCardMove(const PrCardMove& other) noexcept = delete;
  PrCardMove(PrCardMove&& other) noexcept = delete;
  PrCardMove& operator=(const PrCardMove& other) noexcept = delete;
  PrCardMove& operator=(PrCardMove&& other) noexcept = delete;
  virtual ~PrCardMove() = default;

  void execute() noexcept override;

private:
  Board& board_;
  std::size_t move_amount_;
};
#endif // RDCORE_PRCARDMOVE_H
