#include "tile.h"

Tile::Tile() noexcept
  : features_
{ {TileFeature::Floor, true},
  {TileFeature::NorthWall, false},
  {TileFeature::EastWall, false},
  {TileFeature::SouthWall, false},
  {TileFeature::WestWall, false}
}
{

}


void Tile::place_wall(Direction direction)
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
      // No other directions possible
      break;
  }
}


bool Tile::has_wall(Direction direction) const
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
      // No other directions possible
      return false;
  }
}


void Tile::remove_floor()
{
  features_.at(TileFeature::Floor) = false;
}


bool Tile::has_floor() const
{
  return features_.at(TileFeature::Floor);
}
