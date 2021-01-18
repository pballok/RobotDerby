#include "board.h"
#include "direction.h"
#include "prcardmove.h"
#include "robot.h"

#include <catch2/catch.hpp>

SCENARIO("Moving a Robot with a Programming Card", "[PrCard]")
{
  GIVEN("A Move PrCard and an empty Board with a Robot on it") {
    Board board(5, 5);
    auto robot_index = board.placeNewRobot("Robot", 2, Direction::South);
    PrCardMove card(board, robot_index, 2);

    card.execute();

    THEN("the Move Card must move the Robot") {
      auto* robot = board.robotWithIndex(robot_index);
      REQUIRE(robot != nullptr);
      REQUIRE(board.robotPosition(robot_index) == 12);
      REQUIRE(robot->direction() == Direction::South);
    }
  }
}
