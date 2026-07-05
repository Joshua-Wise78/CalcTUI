#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>

int main() {
  using namespace ftxui;

  Element document = vbox({
      hbox({
          vbox({text("1") | flex}) | border,
          vbox({text("2") | flex}) | border,
          vbox({text("3") | flex}) | border,
      }),
      hbox({
          vbox({text("4") | flex}) | border,
          vbox({text("5") | flex}) | border,
          vbox({text("6") | flex}) | border,
      }),
      hbox({
          vbox({text("7") | flex}) | border,
          vbox({text("8") | flex}) | border,
          vbox({text("9") | flex}) | border,
      }),
  });

  auto screen = Screen::Create(Dimension::Full(), Dimension::Fit(document));
  Render(screen, document);
  screen.Print();
  return 0;
}
