#include "component/struct_builder.h"

void StructBuilderComponent::add_member(const size_t type_index) {
  if (members_added->size() == struct_builder::member::max_size) {
    *state = struct_builder::State::Full;
    return;
  }
  *state = struct_builder::State::BuildMode;
  members_added->push_back(struct_builder::member::types.at(type_index));
}

void StructBuilderComponent::undo() {
  *state = struct_builder::State::BuildMode;
  if (!members_added->empty()) {
    members_added->pop_back();
  }
}

void StructBuilderComponent::clear() {
  *state = struct_builder::State::BuildMode;
  if (!members_added->empty()) {
    members_added->clear();
  }
}

void StructBuilderComponent::display_size() {
  if (!members_added->empty()) {
    *state = struct_builder::State::SizeOutput;
  } else {
    *state = struct_builder::State::BuildMode;
  }
}

void StructBuilderComponent::display_optimal() {
  if (!members_added->empty()) {
    *state = struct_builder::State::OptimalOutput;
  } else {
    *state = struct_builder::State::BuildMode;
  }
}
