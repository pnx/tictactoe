# Tic Tac CMake file
cmake_minimum_required (VERSION 2.6)

project (TicTac)

INCLUDE (CheckIncludeFile)
check_include_file (unistd.h HAVE_UNISTD_H)
check_include_file (windows.h HAVE_WINDOWS_H)

add_definitions(-Wall -Werror)
if (HAVE_UNISTD_H)
    add_definitions(-DHAVE_UNISTD_H=1)
endif ()
if (HAVE_WINDOWS_H)
    add_definitions(-DHAVE_WINDOWS_H=1)
endif ()

find_package(SDL REQUIRED)

if (NOT SDL_FOUND)
    message(FATAL_ERROR "SDL not found")
endif()

include_directories("libgfx/include" ${SDL_INCLUDE_DIR})

set (src src/main.cc src/game.cc src/board.cc src/square.cc src/player/player.cc
              src/player/human_player.cc src/player/computer_player.cc)

add_library(libgfx STATIC IMPORTED)
set_property(TARGET libgfx PROPERTY
	IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/libgfx/libgfx.a)

add_executable(tic_tac ${src})
target_link_libraries(tic_tac libgfx SDL GL SDL_image)