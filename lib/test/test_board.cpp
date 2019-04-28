#include "board.h"

#include <catch2/catch.hpp>

SCENARIO("Neighbour coordinate calculation", "[Board]")
{
  GIVEN("An empty board") {
    Board board(0, 0);
    
    THEN("all neighbours must be an invalid index") {
      REQUIRE(board.neighbour(0, Direction::North) == board.invalid_index());
      REQUIRE(board.neighbour(0, Direction::East) == board.invalid_index());
      REQUIRE(board.neighbour(0, Direction::South) == board.invalid_index());
      REQUIRE(board.neighbour(0, Direction::West) == board.invalid_index());
    }
  }

  GIVEN("An board with a single cell") {
    Board board(1, 1);
    
    THEN("all neighbours must be an invalid index") {
      REQUIRE(board.neighbour(0, Direction::North) == board.invalid_index());
      REQUIRE(board.neighbour(0, Direction::East) == board.invalid_index());
      REQUIRE(board.neighbour(0, Direction::South) == board.invalid_index());
      REQUIRE(board.neighbour(0, Direction::West) == board.invalid_index());
    }
  }

  GIVEN("A 3 by 4 Board") {
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
