#include "board.h"

#include <catch2/catch.hpp>

SCENARIO("Placing walls", "[Board]")
{
  GIVEN("a 2 by 2 Board with walls on the edges") {
    Board board(2, 2);
    board.placeWall(0, Direction::North);
    board.placeWall(1, Direction::East);
    board.placeWall(2, Direction::West);
    board.placeWall(3, Direction::South);

    THEN("there must be only the placed walls, nowhere else") {
      REQUIRE(board.wallPresent(0, Direction::North));
      REQUIRE(!board.wallPresent(0, Direction::East));
      REQUIRE(!board.wallPresent(0, Direction::South));
      REQUIRE(!board.wallPresent(0, Direction::West));
      REQUIRE(!board.wallPresent(1, Direction::North));
      REQUIRE(board.wallPresent(1, Direction::East));
      REQUIRE(!board.wallPresent(1, Direction::South));
      REQUIRE(!board.wallPresent(1, Direction::West));
      REQUIRE(!board.wallPresent(2, Direction::North));
      REQUIRE(!board.wallPresent(2, Direction::East));
      REQUIRE(!board.wallPresent(2, Direction::South));
      REQUIRE(board.wallPresent(2, Direction::West));
      REQUIRE(!board.wallPresent(3, Direction::North));
      REQUIRE(!board.wallPresent(3, Direction::East));
      REQUIRE(board.wallPresent(3, Direction::South));
      REQUIRE(!board.wallPresent(3, Direction::West));
    }
  }

  GIVEN("a 2 by 2 Board with walls in the middle") {
    Board board(2, 2);
    board.placeWall(0, Direction::South);
    board.placeWall(0, Direction::East);
    board.placeWall(3, Direction::West);
    board.placeWall(3, Direction::North);

    THEN("there must be walls on all of the tiles") {
      REQUIRE(!board.wallPresent(0, Direction::North));
      REQUIRE(board.wallPresent(0, Direction::East));
      REQUIRE(board.wallPresent(0, Direction::South));
      REQUIRE(!board.wallPresent(0, Direction::West));
      REQUIRE(!board.wallPresent(1, Direction::North));
      REQUIRE(!board.wallPresent(1, Direction::East));
      REQUIRE(board.wallPresent(1, Direction::South));
      REQUIRE(board.wallPresent(1, Direction::West));
      REQUIRE(board.wallPresent(2, Direction::North));
      REQUIRE(board.wallPresent(2, Direction::East));
      REQUIRE(!board.wallPresent(2, Direction::South));
      REQUIRE(!board.wallPresent(2, Direction::West));
      REQUIRE(board.wallPresent(3, Direction::North));
      REQUIRE(!board.wallPresent(3, Direction::East));
      REQUIRE(!board.wallPresent(3, Direction::South));
      REQUIRE(board.wallPresent(3, Direction::West));
    }
  }
}
