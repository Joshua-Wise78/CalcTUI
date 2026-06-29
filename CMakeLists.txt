cmake_minimum_required(VERSION 3.14)
project(calc_tui LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CSS_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(FetchContent)
FetchContent_Declare(ftxui
   GIT_REPOSITORY https://github.com/ArthurSonzogni/FTXUI
   GIT_TAG v5.0.0
)
FetchContent_MakeAvailable(ftxui)

add_subdirectory(src)
