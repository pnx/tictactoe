# libgfx CMake file
cmake_minimum_required (VERSION 2.6)

project (libgfx)

OPTION (SHARED_BUILD "Build Shared Library" OFF)

set (LIB_TYPE STATIC)
if (SHARED_BUILD)
  set (LIB_TYPE SHARED)
endif()

add_definitions(-Wall -Werror)

find_package(SDL REQUIRED)
find_package(SDL_image REQUIRED)
find_package(OpenGL REQUIRED)

if (NOT SDL_FOUND)
    message(FATAL_ERROR "SDL not found")
endif()

if (NOT SDLIMAGE_FOUND)
    message(FATAL_ERROR "SDL_image not found")
endif()

include_directories("include/gfx" ${SDL_INCLUDE_DIR})
set (libs ${libs} ${OPENGL_LIBRARY} ${SDL_LIBRARY} ${SDLIMAGE_LIBRARY})

set (src src/Engine.cc src/Graphics/Graphics.cc src/Graphics/Texture.cc
	src/Entity.cc src/Input/Mouse.cc)

add_library(gfx ${LIB_TYPE} ${src})