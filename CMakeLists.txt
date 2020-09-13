cmake_minimum_required(VERSION 3.17)
project(engine)

# SDL2
link_directories(C:/SDL2-2.0.12/lib/x64)
link_directories(C:/SDL2_image-2.0.5/lib/x64)
link_directories(C:/SDL2_mixer-2.0.4/lib/x64)
link_directories(C:/SDL2_ttf-2.0.15/lib/x64)

option (FORCE_COLORED_OUTPUT "Always produce ANSI-colored output (Clang only)." TRUE)
if (${FORCE_COLORED_OUTPUT})
    if ("${CMAKE_C_COMPILER_ID}" STREQUAL "Clang")
       add_compile_options (-Wall -Wextra -Wno-newline-eof -pedantic -fcolor-diagnostics -fansi-escape-codes)
    endif ()
endif ()

add_subdirectory(engine)
add_subdirectory(test)