cmake_minimum_required(VERSION 3.0.0)
project(SDEProj)

include(CTest)
enable_testing()

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")


find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)


add_executable(SDEProj src/main.cpp src/game.cpp src/texture_manager.cpp src/game_object.cpp src/vector_2d.cpp)

include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})
target_link_libraries(SDEProj ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})

#set(CPACK_PROJECT_NAME ${PROJECT_NAME})
#set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
#include(CPack)
