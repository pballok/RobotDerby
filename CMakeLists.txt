cmake_minimum_required(VERSION 3.6)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(RobotDerby CXX)

include(ExternalProject)
find_package(Git REQUIRED)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall -Wextra -Werror -fPIC")

ExternalProject_Add(
    catch2
    GIT_REPOSITORY      https://github.com/catchorg/Catch2
    GIT_TAG             v2.7.2
    PREFIX              ${CMAKE_SOURCE_DIR}/external
    CONFIGURE_COMMAND   ""
    BUILD_COMMAND       ""
    INSTALL_COMMAND     ""
)
set(CATCH2_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/external/src/catch2/single_include)

set(ALL_SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/lib/*.cpp
)

set(ALL_HEADERS
  ${CMAKE_CURRENT_SOURCE_DIR}/lib/include/*.h
)

set(ALL_TEST_SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/lib/test/*.cpp
)

set(ALL_TEST_HEADERS
)

# ------------------------------------------------------------------------------
# cppcheck
# ------------------------------------------------------------------------------
set(CPPCHECK_ARGS
  --enable=warning,style,performance,portability,unusedFunction
  --std=c++14
  --verbose
  --error-exitcode=1
  --language=c++
  --inline-suppr
  -DMAIN=main
  -I ${CMAKE_SOURCE_DIR}/lib/include
)

add_custom_target(
  cppcheck
  COMMAND cppcheck ${CPPCHECK_ARGS} ${ALL_SOURCES} ${ALL_HEADERS} ${ALL_TEST_SOURCES} ${ALL_TEST_HEADERS}
  COMMENT "running cppcheck"
)

# ------------------------------------------------------------------------------
# astyle
# ------------------------------------------------------------------------------
set(ASTYLE_ARGS
  --style=1tbs
  --lineend=linux
  --suffix=none
  --pad-oper
  --unpad-paren
  --break-closing-brackets
  --align-pointer=type
  --align-reference=type
  --indent-preproc-define
  --indent-switches
  --indent-col1-comments
  --keep-one-line-statements
  --keep-one-line-blocks
  --pad-header
  --convert-tabs
  --min-conditional-indent=0
  --indent=spaces=2
  --close-templates
  --add-brackets
  --break-after-logical
)

add_custom_target(
  astyle
  COMMAND astyle ${ASTYLE_ARGS} ${ALL_SOURCES} ${ALL_HEADERS} ${ALL_TEST_SOURCES} ${ALL_TEST_HEADERS}
  COMMENT "running astyle"
)


# ------------------------------------------------------------------------------
# clang-tidy
# ------------------------------------------------------------------------------
list(APPEND CLANG_TIDY_ARGS
  -p=${CMAKE_BINARY_DIR}
  -header-filter='\(bchest/lib/|bchest/client/|bchest/server/\)'
  -checks='*,-fuchsia-default-arguments,-llvm-header-guard'
)

add_custom_target(
  tidy
  COMMAND clang-tidy ${CLANG_TIDY_ARGS} ${ALL_SOURCES}
  COMMENT "running clang tidy"
)

enable_testing()

add_subdirectory(lib)
