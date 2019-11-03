#ifndef RDCORE_PRCARDTURN_H
#define RDCORE_PRCARDTURN_H

#include "programmingcard.h"

#include <cstddef>

enum class TurnCardType
{
  CLOCKWISE,
  COUNTER_CLOCKWISE,
  U_TURN
};

class PrCardTurn : public ProgrammingCard
{
public:
  PrCardTurn(Robot& robot, TurnCardType turn_type) noexcept;
  PrCardTurn(const PrCardTurn& other) noexcept = delete;
  PrCardTurn(PrCardTurn&& other) noexcept = delete;
  PrCardTurn& operator=(const PrCardTurn& other) noexcept = delete;
  PrCardTurn& operator=(PrCardTurn&& other) noexcept = delete;
  virtual ~PrCardTurn() = default;

  void execute() noexcept override;

private:
  TurnCardType type_;
};
#endif // RDCORE_PRCARDTURN_H
