# Tic Tac CMake file
cmake_minimum_required (VERSION 2.6)

project (TicTac)

find_package(SDL)

set (sources src/main.cc src/game.cc src/board.cc src/square.cc src/player/player.cc
             src/player/human_player.cc src/player/computer_player.cc)
set (libs ${SDL_LIBRARY})

add_executable(tic_tac ${sources})
target_link_libraries(tic_tac ${libs})
