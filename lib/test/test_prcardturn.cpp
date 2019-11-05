#include "direction.h"
#include "prcardturn.h"
#include "robot.h"

#include <catch2/catch.hpp>

SCENARIO("Turning a Robot with a Programming Card", "[PrCard]")
{
  GIVEN("A clockwise Turn PrCard and a Robot facing South") {
    Robot robot("Robot", 2, Direction::South);
    PrCardTurn card(robot, TurnDirection::Clockwise);

    card.execute();

    THEN("the Turn Card must turn the Robot to the West") {
      REQUIRE(robot.position() == 2);
      REQUIRE(robot.direction() == Direction::West);
    }
  }

  GIVEN("A counter-clockwise Turn PrCard and a Robot facing South") {
    Robot robot("Robot", 2, Direction::South);
    PrCardTurn card(robot, TurnDirection::CounterClockwise);

    card.execute();

    THEN("the Turn Card must turn the Robot to the East") {
      REQUIRE(robot.position() == 2);
      REQUIRE(robot.direction() == Direction::East);
    }
  }

  GIVEN("A u-turn Turn PrCard and a Robot facing South") {
    Robot robot("Robot", 2, Direction::South);
    PrCardTurn card(robot, TurnDirection::UTurn);

    card.execute();

    THEN("the Turn Card must turn the Robot to the North") {
      REQUIRE(robot.position() == 2);
      REQUIRE(robot.direction() == Direction::North);
    }
  }
}
