cmake_minimum_required(VERSION 3.16)
project(MyProject LANGUAGES C)

set(CMAKE_C_STANDARD 99)

# 하위 디렉토리 추가
add_subdirectory(app)
add_subdirectory(libA)
add_subdirectory(libB)
