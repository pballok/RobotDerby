#ifndef RDCORE_PRCARDTURN_H
#define RDCORE_PRCARDTURN_H

#include "programmingcard.h"

enum class TurnDirection;

class PrCardTurn : public ProgrammingCard
{
public:
  PrCardTurn(Board& board, Board::robot_index_type robot_index, TurnDirection direction) noexcept;
  PrCardTurn(const PrCardTurn& other) noexcept = delete;
  PrCardTurn(PrCardTurn&& other) noexcept = delete;
  PrCardTurn& operator=(const PrCardTurn& other) noexcept = delete;
  PrCardTurn& operator=(PrCardTurn&& other) noexcept = delete;
  virtual ~PrCardTurn() = default;

  void execute() noexcept override;

private:
  TurnDirection direction_;
};

#endif // RDCORE_PRCARDTURN_H
