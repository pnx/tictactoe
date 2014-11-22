# Tic Tac CMake file
cmake_minimum_required (VERSION 2.6)

project (TicTac)

INCLUDE (CheckIncludeFile)
check_include_file (unistd.h HAVE_UNISTD_H)
check_include_file (windows.h HAVE_WINDOWS_H)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
if (NOT MSVC)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror")
endif ()

if (HAVE_UNISTD_H)
    add_definitions(-DHAVE_UNISTD_H=1)
endif ()
if (HAVE_WINDOWS_H)
    add_definitions(-DHAVE_WINDOWS_H=1)
endif ()

add_definitions(-Isrc)

find_package(SDL REQUIRED)
find_package(SDL_image REQUIRED)
find_package(OpenGL REQUIRED)

if (NOT SDL_FOUND)
    message(FATAL_ERROR "SDL not found")
endif()

if (NOT SDLIMAGE_FOUND)
    message(FATAL_ERROR "SDL_image not found")
endif()


include_directories(${SDL_INCLUDE_DIR})
set (libs ${libs} ${OPENGL_LIBRARY} ${SDL_LIBRARY} ${SDLIMAGE_LIBRARY})

set (src_engine src/Engine/Engine.cc src/Engine/Graphics/Graphics.cc src/Engine/Graphics/Texture.cc
                src/Engine/Entity.cc src/Engine/Input/Mouse.cc)

set (src_game src/main.cc src/game.cc src/board.cc src/square.cc src/player/player.cc
              src/player/human_player.cc src/player/computer_player.cc)

add_executable(tic_tac ${src_game} ${src_engine})
target_link_libraries(tic_tac ${libs})
