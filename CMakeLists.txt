cmake_minimum_required (VERSION 2.6)
project (Scoreboard)
set (CMAKE_BUILD_TYPE Release)

# The version number.
set (Scoreboard_VERSION_MAJOR 0)
set (Scoreboard_VERSION_MINOR 1)

#
set (CMAKE_CXX_STANDARD 14)
set (CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_CXX_EXTENSIONS OFF)


# Finds SFML package
set (CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})
find_package (SFML REQUIRED graphics window system)



# Creates the executable
add_executable(

    ${PROJECT_NAME}

    src/Main.cpp
    src/Team.hpp
    src/Team.cpp
    src/Scoreboard.hpp
    src/Scoreboard.cpp
    src/ResourceHolder.hpp
    src/ResourceHolder.inl


)

target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES} ${ADDITIONAL_LINK_FLAGS})
