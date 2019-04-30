cmake_minimum_required(VERSION 3.0)
project(cpp-docker-example)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_COMPILER /usr/bin/g++-8)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin)

cmake_minimum_required(VERSION 2.8)

file(GLOB project_SRC
    "../src/*.h"
    "../src/*.cpp"
)

add_executable(cpp-docker-example ${project_SRC})

set(cpprestsdk_DIR /usr/lib/${CMAKE_LIBRARY_ARCHITECTURE}/cmake/)

find_package(SQLite3 REQUIRED)
find_package(Boost REQUIRED system)
find_package(cpprestsdk REQUIRED)

target_link_libraries(cpp-docker-example PRIVATE stdc++fs sqlite3 cpprestsdk::cpprest ${Boost_SYSTEM_LIBRARY})