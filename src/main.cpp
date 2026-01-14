#include "ftxui/component/component.hpp"
#include "ftxui/component/screen_interactive.hpp"
#include "component/main_menu.h"
#include "component/struct_builder.h"
#include "struct/builder.h"

using namespace ftxui;
using struct_builder::DataType;

int main() {
  auto screen = ftxui::ScreenInteractive::Fullscreen();

  auto main_menu_component = Make<MainMenuComponent>("Build Your Struct");
  auto struct_builder_component = Make<StructBuilderComponent>();

  const auto main_component = Container::Vertical({
    main_menu_component,
    struct_builder_component,
  });
  const auto root_component = Renderer(main_component, [&] {
    return vbox({
      text("[ESC] Exit"),
      main_component->Render()
    });
  });

  const auto ui = CatchEvent(root_component, [&](const Event &event) {
    if (event == Event::Escape) {
      screen.Exit();
      return true;
    }
    return false;
  });
  screen.Loop(ui);
  return 0;
}
