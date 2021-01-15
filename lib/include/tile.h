#ifndef RDCORE_TILE_H
#define RDCORE_TILE_H

#include "direction.h"
#include "tilefeature.h"

#include <map>

class Tile
{
public:
  Tile() noexcept;
  Tile(const Tile& other) noexcept = delete;
  Tile(Tile&& other) noexcept = delete;
  Tile& operator=(const Tile& other) noexcept = delete;
  Tile& operator=(Tile&& other) noexcept = delete;
  virtual ~Tile() = default;

  void placeWall(Direction direction);
  bool hasWall(Direction direction) const;

  void removeFloor();
  bool hasFloor() const;

  void placeGear(TurnDirection direction);
  bool hasGear(TurnDirection direction);

private:
  std::map<TileFeature, bool> features_;
};

#endif // RDCORE_TILE_H
