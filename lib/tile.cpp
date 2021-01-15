#include "tile.h"

Tile::Tile() noexcept
  : features_{ {TileFeature::Floor, true},
               {TileFeature::NorthWall, false},
               {TileFeature::EastWall, false},
               {TileFeature::SouthWall, false},
               {TileFeature::WestWall, false},
               {TileFeature::GearClockwise, false},
               {TileFeature::GearCounterClockwise, false}
             }
{

}


void Tile::placeWall(Direction direction)
{
  switch (direction) {
    case Direction::North:
      features_.at(TileFeature::NorthWall) = true;
      break;

    case Direction::East:
      features_.at(TileFeature::EastWall) = true;
      break;

    case Direction::South:
      features_.at(TileFeature::SouthWall) = true;
      break;

    case Direction::West:
      features_.at(TileFeature::WestWall) = true;
      break;

    default:
      // No other direction possible
      break;
  }
}


bool Tile::hasWall(Direction direction) const
{
  switch (direction) {
    case Direction::North:
      return features_.at(TileFeature::NorthWall);

    case Direction::East:
      return features_.at(TileFeature::EastWall);

    case Direction::South:
      return features_.at(TileFeature::SouthWall);

    case Direction::West:
      return features_.at(TileFeature::WestWall);

    default:
      // No other direction possible
      return false;
  }
}


void Tile::removeFloor()
{
  features_.at(TileFeature::Floor) = false;
}


bool Tile::hasFloor() const
{
  return features_.at(TileFeature::Floor);
}


void Tile::placeGear(TurnDirection direction)
{
  switch(direction)
  {
    case TurnDirection::Clockwise:
      features_.at(TileFeature::GearClockwise) = true;
      break;

    case TurnDirection::CounterClockwise:
      features_.at(TileFeature::GearCounterClockwise) = true;
      break;

    default:
      // No other type of Gear exists
      break;
  }
}


bool Tile::hasGear(TurnDirection direction)
{
  switch(direction)
  {
    case TurnDirection::Clockwise:
      return features_.at(TileFeature::GearClockwise);

    case TurnDirection::CounterClockwise:
      return features_.at(TileFeature::GearCounterClockwise);

    default:
      // No other type of Gear exists
      return false;
  }
}
