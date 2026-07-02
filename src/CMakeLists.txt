file(GLOB SOURCES "*cpp")

add_executable(calc_tui main.cpp ui.cpp calculator.cpp)

target_include_directories(calc_tui PRIVATE .)

target_link_libraries(calc_tui
   PRIVATE
      ftxui::screen
      ftxui::dom
      ftxui::component
)
