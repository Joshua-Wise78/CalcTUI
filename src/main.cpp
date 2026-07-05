#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/dom/elements.hpp>
#include <string>

int main() {
  using namespace ftxui;

  std::string value = "";

  auto on_click = [&](std::string digit) { value = digit; };

  auto btn1 = Button("1", [&] { on_click("1"); });
  auto btn2 = Button("2", [&] { on_click("2"); });
  auto btn3 = Button("3", [&] { on_click("3"); });

  auto btn4 = Button("4", [&] { on_click("4"); });
  auto btn5 = Button("5", [&] { on_click("5"); });
  auto btn6 = Button("6", [&] { on_click("6"); });

  auto btn7 = Button("7", [&] { on_click("7"); });
  auto btn8 = Button("8", [&] { on_click("8"); });
  auto btn9 = Button("9", [&] { on_click("9"); });

  auto row1 = Container::Horizontal({btn1, btn2, btn3});
  auto row2 = Container::Horizontal({btn4, btn5, btn6});
  auto row3 = Container::Horizontal({btn7, btn8, btn9});
  auto keypad = Container::Vertical({row1, row2, row3});

  auto calculator_ui = Renderer(keypad, [&] {
    return vbox({
        hbox({
            vbox({btn1->Render() | flex}) | border,
            vbox({btn2->Render() | flex}) | border,
            vbox({btn3->Render() | flex}) | border,
        }),
        hbox({
            vbox({btn4->Render() | flex}) | border,
            vbox({btn5->Render() | flex}) | border,
            vbox({btn6->Render() | flex}) | border,
        }),
        hbox({
            vbox({btn7->Render() | flex}) | border,
            vbox({btn8->Render() | flex}) | border,
            vbox({btn9->Render() | flex}) | border,
        }),
        text(" Output: " + value) | border,
    });
  });

  auto screen = ScreenInteractive::FitComponent();
  screen.Loop(calculator_ui);

  return 0;
}
