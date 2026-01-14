#include "ftxui/component/component.hpp"
#include "component/struct_output.h"

using namespace ftxui;

StructOutputComponent::StructOutputComponent(const std::string &struct_str) : struct_str(struct_str) {
}

Element StructOutputComponent::OnRender() {
  return vbox({
    paragraph(struct_str),
  });
}