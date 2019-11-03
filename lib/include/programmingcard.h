#ifndef RDCORE_PROGRAMMINGCARD_H
#define RDCORE_PROGRAMMINGCARD_H

class Robot;

class ProgrammingCard
{
public:
  ProgrammingCard(Robot& robot) noexcept : robot_(robot) {}
  ProgrammingCard(const ProgrammingCard& other) noexcept = delete;
  ProgrammingCard(ProgrammingCard&& other) noexcept = delete;
  ProgrammingCard& operator=(const ProgrammingCard& other) noexcept = delete;
  ProgrammingCard& operator=(ProgrammingCard&& other) noexcept = delete;
  virtual ~ProgrammingCard() = default;

  virtual void execute() = 0;

protected:
  Robot& robot_;
};
#endif // RDCORE_PROGRAMMINGCARD_H
