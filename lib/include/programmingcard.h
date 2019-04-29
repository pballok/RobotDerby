#ifndef RDCORE_PROGRAMMINGCARD_H
#define RDCORE_PROGRAMMINGCARD_H

class Board;
class Robot;

class ProgrammingCard
{
public:
    ProgrammingCard(Board& board, Robot& robot) noexcept : board_(board), robot_(robot) {}
    ProgrammingCard(const ProgrammingCard& other) noexcept = delete;
    ProgrammingCard(ProgrammingCard&& other) noexcept = delete;
    ProgrammingCard& operator=(const ProgrammingCard& other) noexcept = delete;
    ProgrammingCard& operator=(ProgrammingCard&& other) noexcept = delete;
    virtual ~ProgrammingCard() = default;

    virtual void execute() = 0;

protected:
    Board& board_;
    Robot& robot_;
};
#endif // RDCORE_PROGRAMMINGCARD_H
