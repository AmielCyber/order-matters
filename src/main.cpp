#include "ftxui/component/component.hpp"
#include "ftxui/component/screen_interactive.hpp"
#include "component/main_menu.h"
#include "component/struct_builder.h"
#include "struct/builder.h"

using namespace ftxui;
using struct_builder::DataType;

int main() {
  // Canvas
  // Elements - static elements, only for displaying texts
  // Components - Reactive elements, for updating an element based on an input
  // Container - Contains many elements
  // Renderer - An interactive dynamic component
  //            Renderer(list_of_all_components, function that returns a component
  auto screen = ftxui::ScreenInteractive::Fullscreen();
  auto my_main = Make<MainMenuComponent>("Build Your Struct");
  auto my_builder = Make<StructBuilderComponent>();
  const auto main_component = Container::Vertical({
    my_main,
    my_builder,
  });
  const auto main_renderer = Renderer(main_component, [&] {
    return main_component->Render();
  });


  screen.Loop(main_renderer);
  return 0;
}
