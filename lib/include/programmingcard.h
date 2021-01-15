#ifndef RDCORE_PROGRAMMINGCARD_H
#define RDCORE_PROGRAMMINGCARD_H

#include "board.h"

class ProgrammingCard
{
public:
  ProgrammingCard(Board& board, Board::robot_index_type robot_index) noexcept : board_(board), robot_index_(robot_index) {}
  ProgrammingCard(const ProgrammingCard& other) noexcept = delete;
  ProgrammingCard(ProgrammingCard&& other) noexcept = delete;
  ProgrammingCard& operator=(const ProgrammingCard& other) noexcept = delete;
  ProgrammingCard& operator=(ProgrammingCard&& other) noexcept = delete;
  virtual ~ProgrammingCard() = default;

  virtual void execute() = 0;

protected:
  Board& board_;
  Board::robot_index_type robot_index_;
};
#endif // RDCORE_PROGRAMMINGCARD_H
