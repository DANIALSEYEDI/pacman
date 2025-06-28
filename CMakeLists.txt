cmake_minimum_required(VERSION 3.30)
project(pro C)

set(CMAKE_C_STANDARD 11)

add_executable(pro main.c
        menu.c
        menu.h
        printmap.c
        printmap.h
        color.c
        color.h
        game.c
        game.h
)
target_link_libraries(pro winmm)
