cmake_minimum_required(VERSION 3.26)

project(CChess
  VERSION 0.1.0
  DESCRIPTION "Terminal-based chess written in C"
  HOMEPAGE_URL "https://github.com/KR4DE/cchess"
  LANGUAGES C
)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")

if(CMAKE_C_COMPILER_FRONTEND_VARIANT STREQUAL "GNU")
  add_compile_options(
    -Wall
    -Wextra
    -Wpedantic
  )
elseif(CMAKE_C_COMPILER_FRONTEND_VARIANT STREQUAL "MSVC")
  add_compile_options(
    /W4
    /wd4244
    /wd4267
  )
endif()

include_directories(include)

add_library(cchess_core STATIC
  src/board.c
  src/display.c
  src/game.c
  src/input.c
  src/move.c
)

link_libraries(cchess_core)

add_executable(cchess src/main.c)
add_executable(cchess-test-board tests/test_board.c)
add_executable(cchess-test-move tests/test_move.c)

enable_testing()

add_test(NAME board COMMAND cchess-test-board)
add_test(NAME move COMMAND cchess-test-move)

install(TARGETS cchess RUNTIME DESTINATION .)
install(FILES README.md LICENSE DESTINATION .)

set(CPACK_PACKAGE_NAME "cchess")

if(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
  set(CPACK_SYSTEM_NAME "macos")
else()
  string(TOLOWER "${CMAKE_SYSTEM_NAME}" CPACK_SYSTEM_NAME)
endif()

if(CMAKE_OSX_ARCHITECTURES MATCHES ";")
  string(APPEND CPACK_SYSTEM_NAME "-universal")
elseif(CMAKE_SYSTEM_PROCESSOR STREQUAL "AMD64")
  string(APPEND CPACK_SYSTEM_NAME "-x86_64")
else()
  string(TOLOWER "${CPACK_SYSTEM_NAME}-${CMAKE_SYSTEM_PROCESSOR}" CPACK_SYSTEM_NAME)
endif()

if(UNIX)
  set(CPACK_GENERATOR "TGZ")
else()
  set(CPACK_GENERATOR "ZIP")
endif()

include(CPack)
