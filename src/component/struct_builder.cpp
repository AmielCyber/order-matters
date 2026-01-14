#include "component/struct_builder.h"

#include "component/action_buttons.h"
#include "component/data_type_select.h"
#include "component/struct_output.h"
#include "ftxui/component/component.hpp"

StructBuilderComponent::StructBuilderComponent(){
  struct_model = std::make_unique<StructModel>();
  auto data_selection_component = ftxui::Make<DataTypeSelectComponent>([this](const size_t index) {
    this->add_member(index);
  });
  auto action_buttons_component = ftxui::Make<ActionButtonsComponent>(
    [this](){this->undo();},
    [this](){this->clear();},
    [this](){this->display_size();},
    [this](){this->display_optimal();}
    );
  auto struct_output_component = ftxui::Make<StructOutputComponent>(struct_model->to_string);
  input_container = ftxui::Container::Vertical({data_selection_component, action_buttons_component });
  output_container = ftxui::Container::Vertical({struct_output_component });
  Add(input_container);
  Add(output_container);
}

ftxui::Element StructBuilderComponent::OnRender() {
  return ftxui::hbox({
    ftxui::vbox({
      input_container->Render(),
      ftxui::separator(),
    }),
    ftxui::separator(),
    output_container->Render()
  });
}

void StructBuilderComponent::add_member(const size_t type_index) {
  if (struct_model->members.size() == struct_builder::member::max_size) {
    struct_model->state = struct_builder::State::Full;
    return;
  }
  struct_model->state = struct_builder::State::BuildMode;
  struct_model->members.push_back(struct_builder::member::types.at(type_index));
  struct_model->to_string = struct_builder::Builder::to_string(
    struct_model->state, struct_model->members
  );
}

void StructBuilderComponent::undo() {
  struct_model->state = struct_builder::State::BuildMode;
  if (!struct_model->members.empty()) {
    struct_model->members.pop_back();
    struct_model->to_string = struct_builder::Builder::to_string(
      struct_model->state, struct_model->members
    );
  }
}

void StructBuilderComponent::clear() {
  struct_model->state = struct_builder::State::BuildMode;
  if (!struct_model->members.empty()) {
    struct_model->members.clear();
    struct_model->to_string = struct_builder::Builder::to_string(
      struct_model->state, struct_model->members
    );
  }
}

void StructBuilderComponent::display_size() {
  if (!struct_model->members.empty()) {
    struct_model->state = struct_builder::State::SizeOutput;
    struct_model->to_string = struct_builder::Builder::to_string(
      struct_model->state, struct_model->members
    );
  } else {
    struct_model->state = struct_builder::State::BuildMode;
  }
}

void StructBuilderComponent::display_optimal() {
  if (!struct_model->members.empty()) {
    struct_model->state = struct_builder::State::OptimalOutput;
    struct_model->to_string = struct_builder::Builder::to_string(
      struct_model->state, struct_model->members
    );
  } else {
    struct_model->state = struct_builder::State::BuildMode;
  }
}
