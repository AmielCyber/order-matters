#include "ftxui/component/component.hpp"
#include "component/struct_output.h"

using namespace ftxui;

StructOutputComponent::StructOutputComponent(
  const std::shared_ptr<std::vector<struct_builder::DataType> > &members_added,
  const std::shared_ptr<struct_builder::State> &state
) : types_added(members_added), struct_state(state) {
}

Element StructOutputComponent::OnRender() {
  return vbox({
    paragraph(get_struct_output()),
  });
}

std::string StructOutputComponent::get_struct_output() const {
  return struct_builder::Builder::build(*struct_state, *types_added);
}
