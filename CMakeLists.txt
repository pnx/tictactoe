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

find_package(SDL)

if (SDL_FOUND)
    include_directories(${SDL_INCLUDE_DIR})
    set (libs ${libs} ${SDL_LIBRARY})
endif ()

find_package(OpenGL)

if (OPENGL_FOUND) 
    set (libs ${libs} ${OPENGL_LIBRARY})
endif ()

set (libs ${libs} -lSDL_image)

set (src_engine src/Engine/Engine.cc src/Engine/Graphics/Graphics.cc src/Engine/Graphics/Texture.cc)

set (src_game src/main.cc src/game.cc src/board.cc src/square.cc src/player/player.cc
              src/player/human_player.cc src/player/computer_player.cc)

add_executable(tic_tac ${src_game} ${src_engine})
target_link_libraries(tic_tac ${libs})
