add_executable(test_rdcore
  test_main.cpp
  test_board.cpp
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