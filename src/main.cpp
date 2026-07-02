#include <ftxui/component/app.hpp>
#include <ftxui/component/component.hpp>
#include <ftxui/dom/elements.hpp>
#include <string>
#include <vector>

#include "calculator.hpp"

int main() {
  using namespace ftxui;

  std::string display_text = "0";
  Calculator calc; // Sourced from your calculator.hpp

  // 1. Data-driven layout design
  // Adding the operator symbols here scales naturally without extra code
  const std::vector<std::vector<std::string>> grid_layout = {
      {"7", "8", "9", "/"},
      {"4", "5", "6", "*"},
      {"1", "2", "3", "-"},
      {"C", "0", "=", "+"}};

  // 2. Generate components dynamically
  Components rows;
  for (const auto &row_labels : grid_layout) {
    Components row_buttons;
    for (const auto &label : row_labels) {
      // The lambda captures `display_text` by reference so it updates the same
      // string
      row_buttons.push_back(Button(label, [&display_text, label] {
        if (label == "C") {
          display_text = "0";
        } else if (label == "=") {
          // TODO: Hook in `calc.calculate(...)` here
        } else {
          if (display_text == "0")
            display_text = "";
          display_text += label;
        }
      }));
    }
    rows.push_back(Container::Horizontal(std::move(row_buttons)));
  }

  auto calc_grid = Container::Vertical(std::move(rows));

  // 3. Render the application components
  auto main_component = Renderer(calc_grid, [&] {
    return vbox({
               text(display_text) | border | center, // The calculator screen
               separator(),
               calc_grid->Render() | center // The dynamic button grid
           }) |
           border;
  });

  // 4. Start the application loop using ftxui::App
  auto app = App::TerminalOutput();
  app.Loop(main_component);

  return 0;
}
