cmake_minimum_required(VERSION 3.26)

project(CChess
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

if(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
  set(CPACK_SYSTEM_NAME "macos")
else()
  string(TOLOWER "${CMAKE_SYSTEM_NAME}" CPACK_SYSTEM_NAME)
endif()

if(CMAKE_OSX_ARCHITECTURES MATCHES ";")
  set(cchess_arch "universal")
elseif(CMAKE_SYSTEM_PROCESSOR STREQUAL "AMD64")
  set(cchess_arch "x86_64")
else()
  string(TOLOWER "${CMAKE_SYSTEM_PROCESSOR}" cchess_arch)
endif()

set(CPACK_PACKAGE_FILE_NAME "cchess-${CPACK_SYSTEM_NAME}-${cchess_arch}")

if(UNIX)
  set(CPACK_GENERATOR "TGZ")
else()
  set(CPACK_GENERATOR "ZIP")
endif()

include(CPack)
