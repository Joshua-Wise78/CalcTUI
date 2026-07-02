cmake_minimum_required(VERSION 3.14)
project(calc_tui LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(FetchContent)
FetchContent_Declare(ftxui
   GIT_REPOSITORY https://github.com/ArthurSonzogni/ftxui
   GIT_TAG v7.0.0
)
FetchContent_MakeAvailable(ftxui)

add_subdirectory(src)

target_link_libraries(calc_tui PRIVATE
   ftxui::ftxui
)


target_include_directories(calc_tui PRIVATE src)
