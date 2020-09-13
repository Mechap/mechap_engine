project(engine C)

set(CMAKE_BUILD_TYPE Debug)

file(GLOB_RECURSE SOURCES "*.c" "*.h")

add_library(${PROJECT_NAME} STATIC ${SOURCES})
target_link_libraries(${PROJECT_NAME} SDL2main SDL2 SDL2_image SDL2_mixer SDL2_ttf)

target_include_directories(${PROJECT_NAME}
    PUBLIC ${PROJECT_SOURCE_DIR}/include
)