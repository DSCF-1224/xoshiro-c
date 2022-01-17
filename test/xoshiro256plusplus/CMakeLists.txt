cmake_minimum_required(VERSION 3.10)

project(test_xoshiro)

set(CMAKE_CXX_FLAG         "-Wall -Werror -Wextra")
set(CMAKE_CXX_FLAG_DEBUG   "-O0")
set(CMAKE_CXX_FLAG_RELEASE "-O2")

add_executable(${PROJECT_NAME}
	../../src/rotl.c
	../../src/xoshiro256plusplus.c
	./main.c
)
