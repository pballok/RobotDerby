#include "board.h"
#include "robot.h"

#include <catch2/catch.hpp>

SCENARIO("Neighbour coordinate calculation", "[Board]")
{
  GIVEN("an empty board") {
    Board board(0, 0);

    THEN("all neighbours must be an invalid index") {
      REQUIRE(board.neighbour(0, Direction::North) == board.invalid_index());
      REQUIRE(board.neighbour(0, Direction::East) == board.invalid_index());
      REQUIRE(board.neighbour(0, Direction::South) == board.invalid_index());
      REQUIRE(board.neighbour(0, Direction::West) == board.invalid_index());
    }
  }

  GIVEN("a board with a single cell") {
    Board board(1, 1);

    THEN("all neighbours must be an invalid index") {
      REQUIRE(board.neighbour(0, Direction::North) == board.invalid_index());
      REQUIRE(board.neighbour(0, Direction::East) == board.invalid_index());
      REQUIRE(board.neighbour(0, Direction::South) == board.invalid_index());
      REQUIRE(board.neighbour(0, Direction::West) == board.invalid_index());
    }
  }

  GIVEN("a 3 by 4 Board") {
    Board board(3, 4);

    THEN("the north neighbour calculations must be correct") {
      REQUIRE(board.neighbour(0, Direction::North) == board.invalid_index());
      REQUIRE(board.neighbour(1, Direction::North) == board.invalid_index());
      REQUIRE(board.neighbour(2, Direction::North) == board.invalid_index());
      REQUIRE(board.neighbour(3, Direction::North) == 0);
      REQUIRE(board.neighbour(4, Direction::North) == 1);
      REQUIRE(board.neighbour(5, Direction::North) == 2);
      REQUIRE(board.neighbour(6, Direction::North) == 3);
      REQUIRE(board.neighbour(7, Direction::North) == 4);
      REQUIRE(board.neighbour(8, Direction::North) == 5);
      REQUIRE(board.neighbour(9, Direction::North) == 6);
      REQUIRE(board.neighbour(10, Direction::North) == 7);
      REQUIRE(board.neighbour(11, Direction::North) == 8);
      REQUIRE(board.neighbour(12, Direction::North) == board.invalid_index());
    }

    THEN("the east neighbour calculations must be correct") {
      REQUIRE(board.neighbour(0, Direction::East) == 1);
      REQUIRE(board.neighbour(1, Direction::East) == 2);
      REQUIRE(board.neighbour(2, Direction::East) == board.invalid_index());
      REQUIRE(board.neighbour(3, Direction::East) == 4);
      REQUIRE(board.neighbour(4, Direction::East) == 5);
      REQUIRE(board.neighbour(5, Direction::East) == board.invalid_index());
      REQUIRE(board.neighbour(6, Direction::East) == 7);
      REQUIRE(board.neighbour(7, Direction::East) == 8);
      REQUIRE(board.neighbour(8, Direction::East) == board.invalid_index());
      REQUIRE(board.neighbour(9, Direction::East) == 10);
      REQUIRE(board.neighbour(10, Direction::East) == 11);
      REQUIRE(board.neighbour(11, Direction::East) == board.invalid_index());
      REQUIRE(board.neighbour(12, Direction::East) == board.invalid_index());
    }

    THEN("the south neighbour calculations must be correct") {
      REQUIRE(board.neighbour(0, Direction::South) == 3);
      REQUIRE(board.neighbour(1, Direction::South) == 4);
      REQUIRE(board.neighbour(2, Direction::South) == 5);
      REQUIRE(board.neighbour(3, Direction::South) == 6);
      REQUIRE(board.neighbour(4, Direction::South) == 7);
      REQUIRE(board.neighbour(5, Direction::South) == 8);
      REQUIRE(board.neighbour(6, Direction::South) == 9);
      REQUIRE(board.neighbour(7, Direction::South) == 10);
      REQUIRE(board.neighbour(8, Direction::South) == 11);
      REQUIRE(board.neighbour(9, Direction::South) == board.invalid_index());
      REQUIRE(board.neighbour(10, Direction::South) == board.invalid_index());
      REQUIRE(board.neighbour(11, Direction::South) == board.invalid_index());
      REQUIRE(board.neighbour(12, Direction::South) == board.invalid_index());
    }

    THEN("the west neighbour calculations must be correct") {
      REQUIRE(board.neighbour(0, Direction::West) == board.invalid_index());
      REQUIRE(board.neighbour(1, Direction::West) == 0);
      REQUIRE(board.neighbour(2, Direction::West) == 1);
      REQUIRE(board.neighbour(3, Direction::West) == board.invalid_index());
      REQUIRE(board.neighbour(4, Direction::West) == 3);
      REQUIRE(board.neighbour(5, Direction::West) == 4);
      REQUIRE(board.neighbour(6, Direction::West) == board.invalid_index());
      REQUIRE(board.neighbour(7, Direction::West) == 6);
      REQUIRE(board.neighbour(8, Direction::West) == 7);
      REQUIRE(board.neighbour(9, Direction::West) == board.invalid_index());
      REQUIRE(board.neighbour(10, Direction::West) == 9);
      REQUIRE(board.neighbour(11, Direction::West) == 10);
      REQUIRE(board.neighbour(12, Direction::West) == board.invalid_index());
    }
  }
}

SCENARIO("Placing walls", "[Board]")
{
  GIVEN("a 2 by 2 Board with walls on the edges") {
    Board board(2, 2);
    board.place_wall(0, Direction::North);
    board.place_wall(1, Direction::East);
    board.place_wall(2, Direction::West);
    board.place_wall(3, Direction::South);

    THEN("there must be only the placed walls, nowhere else") {
      REQUIRE(board.wall_present(0, Direction::North));
      REQUIRE(!board.wall_present(0, Direction::East));
      REQUIRE(!board.wall_present(0, Direction::South));
      REQUIRE(!board.wall_present(0, Direction::West));
      REQUIRE(!board.wall_present(1, Direction::North));
      REQUIRE(board.wall_present(1, Direction::East));
      REQUIRE(!board.wall_present(1, Direction::South));
      REQUIRE(!board.wall_present(1, Direction::West));
      REQUIRE(!board.wall_present(2, Direction::North));
      REQUIRE(!board.wall_present(2, Direction::East));
      REQUIRE(!board.wall_present(2, Direction::South));
      REQUIRE(board.wall_present(2, Direction::West));
      REQUIRE(!board.wall_present(3, Direction::North));
      REQUIRE(!board.wall_present(3, Direction::East));
      REQUIRE(board.wall_present(3, Direction::South));
      REQUIRE(!board.wall_present(3, Direction::West));
    }
  }

  GIVEN("a 2 by 2 Board with walls in the middle") {
    Board board(2, 2);
    board.place_wall(0, Direction::South);
    board.place_wall(0, Direction::East);
    board.place_wall(3, Direction::West);
    board.place_wall(3, Direction::North);

    THEN("there must be walls on all of the tiles") {
      REQUIRE(!board.wall_present(0, Direction::North));
      REQUIRE(board.wall_present(0, Direction::East));
      REQUIRE(board.wall_present(0, Direction::South));
      REQUIRE(!board.wall_present(0, Direction::West));
      REQUIRE(!board.wall_present(1, Direction::North));
      REQUIRE(!board.wall_present(1, Direction::East));
      REQUIRE(board.wall_present(1, Direction::South));
      REQUIRE(board.wall_present(1, Direction::West));
      REQUIRE(board.wall_present(2, Direction::North));
      REQUIRE(board.wall_present(2, Direction::East));
      REQUIRE(!board.wall_present(2, Direction::South));
      REQUIRE(!board.wall_present(2, Direction::West));
      REQUIRE(board.wall_present(3, Direction::North));
      REQUIRE(!board.wall_present(3, Direction::East));
      REQUIRE(!board.wall_present(3, Direction::South));
      REQUIRE(board.wall_present(3, Direction::West));
    }
  }
}

SCENARIO("Move a Robot", "[Board]")
{
  GIVEN("No obstruction during movement") {
    Board board(5, 5);

    Robot robot("Pinky", 1, Direction::West);
    board.move_robot(robot, 2, Direction::East);
    board.move_robot(robot, 3, Direction::South);

    THEN("Robot moved to correct destination, direction unchanged") {
      REQUIRE(robot.position() == 18);
      REQUIRE(robot.direction() == Direction::West);
    }
  }

  GIVEN("a Wall obstructing movement") {
    Board board(5, 5);
    board.place_wall(2, Direction::East);
    board.place_wall(2, Direction::South);

    Robot robot("Pinky", 1, Direction::West);
    board.move_robot(robot, 2, Direction::East);
    board.move_robot(robot, 3, Direction::South);

    THEN("Robot moved as far as it can, its direction unchanged") {
      REQUIRE(robot.position() == 2);
      REQUIRE(robot.direction() == Direction::West);
    }
  }

  GIVEN("Movement leading off the Board") {
    Board board(5, 5);
    Robot robot("Pinky", 20, Direction::West);
    board.move_robot(robot, 2, Direction::East);
    board.move_robot(robot, 3, Direction::South);

    THEN("Robot must be rebooted") {
      REQUIRE(robot.position() == 0);
      REQUIRE(robot.direction() == Direction::North);
    }
  }

  GIVEN("Movement leading into a hole") {
    Board board(5, 5);
    board.remove_floor(13);
    Robot robot("Pinky", 1, Direction::West);
    board.move_robot(robot, 2, Direction::East);
    board.move_robot(robot, 3, Direction::South);

    THEN("Robot must be rebooted") {
      REQUIRE(robot.position() == 0);
      REQUIRE(robot.direction() == Direction::North);
    }
  }
}
