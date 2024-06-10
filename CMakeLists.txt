cmake_minimum_required(VERSION 3.5)

project(SpaceInvaders VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_INSTALL_PREFIX "install")

set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -mwindows -static")

set(raylib_DIR "D:/Lib/raylib-5.0")

add_subdirectory(${raylib_DIR} raylib)

set(SOURCES
    src/obstacle.cpp
    src/block.cpp
    src/laser.cpp
    src/spaceship.cpp
    src/game.cpp
    src/main.cpp
    src/alien.cpp
    src/mysteryship.cpp
    resources.rc
)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} PRIVATE
    raylib
)

target_include_directories(${PROJECT_NAME} PRIVATE 
    ${CMAKE_SOURCE_DIR}/include
)

install(TARGETS ${PROJECT_NAME}
    RUNTIME DESTINATION .
)

install(DIRECTORY
    ${CMAKE_SOURCE_DIR}/assets/
    DESTINATION ${CMAKE_SOURCE_DIR}/install/assets
)