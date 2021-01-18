#include "board.h"
#include "robot.h"

#include <catch2/catch.hpp>

SCENARIO("Move a Robot", "[Board]")
{
  GIVEN("No obstruction during movement") {
    Board board(5, 5);

    auto robot_index = board.placeNewRobot("Pinky", 1, Direction::West);
    board.moveRobot(robot_index, 2, Direction::East);
    board.moveRobot(robot_index, 3, Direction::South);

    THEN("Robot moved to correct destination, direction unchanged") {
      auto* robot = board.robotWithIndex(1);
      REQUIRE(robot != nullptr);
      REQUIRE(board.robotPosition(robot_index) == 18);
      REQUIRE(robot->direction() == Direction::West);
      REQUIRE(robot->state() == Robot::State::Active);
    }
  }

  GIVEN("a Wall obstructing movement") {
    Board board(5, 5);
    board.placeWall(2, Direction::East);
    board.placeWall(2, Direction::South);

    auto robot_index = board.placeNewRobot("Pinky", 1, Direction::West);
    board.moveRobot(robot_index, 2, Direction::East);
    board.moveRobot(robot_index, 3, Direction::South);

    THEN("Robot moved as far as it can, its direction unchanged") {
      auto* robot = board.robotWithIndex(1);
      REQUIRE(robot != nullptr);
      REQUIRE(board.robotPosition(robot_index) == 2);
      REQUIRE(robot->direction() == Direction::West);
      REQUIRE(robot->state() == Robot::State::Active);
    }
  }

  GIVEN("Movement leading off the Board") {
    Board board(5, 5);

    auto robot_index = board.placeNewRobot("Pinky", 20, Direction::West);
    board.moveRobot(robot_index, 2, Direction::East);
    board.moveRobot(robot_index, 3, Direction::South);

    THEN("Robot must be rebooting") {
      auto* robot = board.robotWithIndex(1);
      REQUIRE(robot != nullptr);
      REQUIRE(robot->state() == Robot::State::Rebooting);
    }
  }

  GIVEN("Movement leading into a hole") {
    Board board(5, 5);
    board.removeFloor(13);

    auto robot_index = board.placeNewRobot("Pinky", 1, Direction::West);
    board.moveRobot(robot_index, 2, Direction::East);
    board.moveRobot(robot_index, 3, Direction::South);

    THEN("Robot must be rebooting") {
      auto* robot = board.robotWithIndex(1);
      REQUIRE(robot != nullptr);
      REQUIRE(robot->state() == Robot::State::Rebooting);
    }
  }
}
