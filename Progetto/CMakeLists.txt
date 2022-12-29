cmake_minimum_required(VERSION 3.23)
project(Progetto C)

set(CMAKE_C_STANDARD 99)

add_executable(Progetto main.c vector.c vector.h gameworld.c gameworld.h player.c player.h logic.c logic.h ai.c ai.h around.c around.h)
