cmake_minimum_required(VERSION 3.10)

set(CMAKE_BUILD_TYPE Debug)

project(c-sandbox)

include(FetchContent)

FetchContent_Declare(
  collections-c
  GIT_REPOSITORY https://github.com/srdja/Collections-C.git
  GIT_TAG        master
)

FetchContent_MakeAvailable(collections-c)

file(GLOB MyCSources *.c)
add_executable(c-sandbox ${MyCSources})

target_link_libraries(c-sandbox PRIVATE collectc)
