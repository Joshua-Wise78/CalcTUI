file(GLOB SOURCES "*cpp")

add_executable(calc_tui ${SOURCES})

target_include_directories(calc_tui PRIVATE ../include)

target_link_libraries(calc_tui
   PRIVATE
      ftxui::screen
      ftxui::dom
      ftxui::component
)
