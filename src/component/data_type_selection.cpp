#include "component/data_type_select.h"
#include "ftxui/component/component.hpp"
#include "struct/builder.h"

using namespace ftxui;

DataTypeSelectComponent::DataTypeSelectComponent(
  const std::function<void(size_t)> &on_select) {
  button_list_container = Container::Vertical({});

  for (size_t i = 0; i < struct_builder::member::types.size(); ++i) {
    const auto button = Button(std::string(struct_builder::member::types.at(i).name), [i, on_select] {
      on_select(i);
    });
    button_list_container->Add(button);
  }
  Add(button_list_container);
}

Element DataTypeSelectComponent::OnRender() {
  return vbox({
           text("Add Data Member") | bold,
           separator(),
           button_list_container->Render() | vscroll_indicator | frame | size(HEIGHT, LESS_THAN, scrollable_size)
         }) | border;
}
