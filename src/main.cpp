#include <iostream>
#include <ostream>

#include "component/action_buttons.h"
#include "ftxui/component/component.hpp"
#include "ftxui/component/screen_interactive.hpp"
#include "struct/data_type_member.h"
#include "component/data_type_select.h"
#include "component/main_menu.h"
#include "component/struct_output.h"

using namespace ftxui;
struct wtf {int16_t b;};

int main() {
  // Canvas
  // Elements - static elements, only for displaying texts
  // Components - Reactive elements, for updating an element based on an input
  // Container - Contains many elements
  // Renderer - An interactive dynamic component
  //            Renderer(list_of_all_components, function that returns a component
  auto screen = ftxui::ScreenInteractive::FitComponent();
  auto main_container = Container::Horizontal({});
  auto on_undo = [] {
    std::cout << "UndoOOOOOOOOOOOOOOOOOOOOOOOOOOOOOoo" << '\n';
  };
  auto on_clear = [] {
    std::cout << std::endl << "___________________________________-Cleared" << '\n';
  };
  auto on_get_size = [] {
    std::cout << std::endl << "_____________________________________Get Size" << '\n';
  };
  auto on_get_optimal = [] {
    std::cout << std::endl << "-------------------------------------Get Optimal" << '\n';
  };
  std::vector<DataType> members = {
    DataType("bool", sizeof(bool)),
    DataType("int", sizeof(int)),
    DataType("long", sizeof(long)),
  };
  std::shared_ptr<struct_builder::State> my_state = std::make_shared<struct_builder::State>(struct_builder::State::SizeOutput);
  std::shared_ptr<std::vector<DataType> > members_added = std::make_shared<std::vector<DataType>>(members);
  std::vector<std::string> k = {"bool a{};", "int b{};", "char c{};"};
  std::shared_ptr<std::vector<std::string>> list = std::make_shared<std::vector<std::string>>(k);

  auto my_main = Make<MainMenuComponent>("Build Your Struct");
  auto my_action = Make<ActionButtonsComponent>(on_undo, on_clear, on_get_size, on_get_optimal);
  auto my_struct_output = Make<StructOutputComponent>(members_added, my_state);
  auto my_data_type_select = Make<DataTypeSelectComponent>([](size_t i) {
    std::cout << "Selected " << i << std::endl;
  });
  const auto main_component = Container::Horizontal({
    my_struct_output,
  });
  const auto main_renderer = Renderer(main_component, [&] {
    return main_component->Render();
  });


  screen.Loop(main_renderer);
  return 0;
}