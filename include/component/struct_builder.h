#ifndef ORDER_MATTERS_STRUCT_BUILDER_H
#define ORDER_MATTERS_STRUCT_BUILDER_H
#include "ftxui/component/component_base.hpp"
#include "model/struct_model.h"

class StructBuilderComponent : public ftxui::ComponentBase {
  // MODEL
  std::unique_ptr<StructModel> struct_model;
  ftxui::Component input_container;
  ftxui::Component output_container;

public:
  StructBuilderComponent();
  // VIEW
  ftxui::Element OnRender() override;

private:
  // CONTROLLER
  void add_member(size_t type_index);

  void undo();

  void clear();

  void display_size();

  void display_optimal();
};
#endif //ORDER_MATTERS_STRUCT_BUILDER_H
