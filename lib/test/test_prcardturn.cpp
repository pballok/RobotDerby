#include "direction.h"
#include "prcardturn.h"
#include "robot.h"

#include <catch2/catch.hpp>

SCENARIO("Turning a Robot with a Programming Card", "[PrCard]")
{
  GIVEN("A clockwise Turn PrCard and a Robot facing South") {
    Board board(5, 5);
    auto robot_index = board.placeNewRobot("Robot", 2, Direction::South);
    PrCardTurn card(board, robot_index, TurnDirection::Clockwise);

    card.execute();

    THEN("the Turn Card must turn the Robot to the West") {
      auto* robot = board.robotWithIndex(robot_index);
      REQUIRE(robot != nullptr);
      REQUIRE(board.robotPosition(robot_index) == 2);
      REQUIRE(robot->direction() == Direction::West);
    }
  }

  GIVEN("A counter-clockwise Turn PrCard and a Robot facing South") {
    Board board(5, 5);
    auto robot_index = board.placeNewRobot("Robot", 2, Direction::South);
    PrCardTurn card(board, robot_index, TurnDirection::CounterClockwise);

    card.execute();

    THEN("the Turn Card must turn the Robot to the East") {
      auto* robot = board.robotWithIndex(robot_index);
      REQUIRE(robot != nullptr);
      REQUIRE(board.robotPosition(robot_index) == 2);
      REQUIRE(robot->direction() == Direction::East);
    }
  }

  GIVEN("A u-turn Turn PrCard and a Robot facing South") {
    Board board(5, 5);
    auto robot_index = board.placeNewRobot("Robot", 2, Direction::South);
    PrCardTurn card(board, robot_index, TurnDirection::UTurn);

    card.execute();

    THEN("the Turn Card must turn the Robot to the North") {
      auto* robot = board.robotWithIndex(robot_index);
      REQUIRE(robot != nullptr);
      REQUIRE(board.robotPosition(robot_index) == 2);
      REQUIRE(robot->direction() == Direction::North);
    }
  }
}
