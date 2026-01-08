#include "component/data_type_selection.h"
#include "ftxui/component/component.hpp"

using namespace ftxui;
DataTypeSelectionComponent::DataTypeSelectionComponent(
    const std::vector<std::shared_ptr<DataTypeMember>>& members,
    const std::function<void(size_t)>& on_select) {

  button_list_container = Container::Vertical({});

  for (size_t i = 0; i < members.size(); ++i) {
    const auto button = Button(members[i]->name, [i, on_select] {
        on_select(i);
    });
    button_list_container->Add(button);
  }
  Add(button_list_container);
}

Element DataTypeSelectionComponent::OnRender() {
  return vbox({
      text("Add Data Member") | bold,
      separator(),
      button_list_container->Render() | vscroll_indicator | frame | size(HEIGHT, LESS_THAN, 10)
  }) | border;
}
