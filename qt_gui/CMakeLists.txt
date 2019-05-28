project(RobotDerby)

find_package(Qt5 COMPONENTS Core Gui Widgets REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_executable(robotderby
  main.cpp
  wndmain.cpp
)

set_target_properties(robotderby
  PROPERTIES VERSION 0.1.0
)

target_include_directories(robotderby
  PRIVATE .
  PUBLIC ${Qt5Widgets_INCLUDE_DIRS}
)

target_link_libraries(robotderby
  rdcore
  ${Qt5Widgets_LIBRARIES}
)
