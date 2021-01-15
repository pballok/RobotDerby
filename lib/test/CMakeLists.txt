add_executable(test_rdcore
  test_board.cpp
  test_board_robot_movement.cpp
  test_board_walls.cpp
  test_main.cpp
  test_prcardmove.cpp
  test_prcardturn.cpp
)

target_link_libraries(test_rdcore
  rdcore
)

add_dependencies(test_rdcore
  catch2
)

target_include_directories(test_rdcore
  PRIVATE .
  PRIVATE ..
  PRIVATE ${CATCH2_INCLUDE_DIR}
)

add_test(
  NAME    TestRDCore
  COMMAND test_rdcore
)

add_custom_target(run_test_rdcore ALL
  COMMAND test_rdcore
)
