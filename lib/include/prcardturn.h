#ifndef RDCORE_PRCARDTURN_H
#define RDCORE_PRCARDTURN_H

#include "programmingcard.h"

#include <cstddef>

enum class TurnDirection;

class PrCardTurn : public ProgrammingCard
{
public:
  PrCardTurn(Robot& robot, TurnDirection direction) noexcept;
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
