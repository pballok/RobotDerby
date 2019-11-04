#include "prcardturn.h"
#include "robot.h"

#include <catch2/catch.hpp>

SCENARIO("Turning a Robot with a Programming Card", "[PrCard]")
{
  GIVEN("A clockwise Turn PrCard and a Robot") {
    Robot robot("Robot", 2, Direction::South);
    PrCardTurn card(robot, TurnCardType::CLOCKWISE);

    card.execute();

    THEN("the Turn Card must turn the Robot") {
      REQUIRE(robot.position() == 2);
      REQUIRE(robot.direction() == Direction::West);
    }
  }

  GIVEN("A counter-clockwise Turn PrCard and a Robot") {
    Robot robot("Robot", 2, Direction::South);
    PrCardTurn card(robot, TurnCardType::COUNTER_CLOCKWISE);

    card.execute();

    THEN("the Turn Card must turn the Robot") {
      REQUIRE(robot.position() == 2);
      REQUIRE(robot.direction() == Direction::East);
    }
  }

  GIVEN("A u-turn Turn PrCard and a Robot") {
    Robot robot("Robot", 2, Direction::South);
    PrCardTurn card(robot, TurnCardType::U_TURN);

    card.execute();

    THEN("the Turn Card must turn the Robot") {
      REQUIRE(robot.position() == 2);
      REQUIRE(robot.direction() == Direction::North);
    }
  }
}
