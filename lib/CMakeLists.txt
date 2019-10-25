add_library(rdcore SHARED
  board.cpp
  direction.cpp
  game.cpp
  player.cpp
  prcardmove.cpp
  robot.cpp
  tile.cpp
)

set_target_properties(rdcore
  PROPERTIES VERSION 0.1.0
)

target_include_directories(rdcore
  PUBLIC include
  PRIVATE .
)

add_subdirectory(test)
