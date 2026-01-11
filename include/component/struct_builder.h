#ifndef ORDER_MATTERS_STRUCT_BUILDER_H
#define ORDER_MATTERS_STRUCT_BUILDER_H
#include "ftxui/component/component_base.hpp"
#include "struct/data_type_member.h"
#include "struct/builder.h"

class StructBuilderComponent : public ftxui::ComponentBase {
  std::shared_ptr<std::vector<DataType> > members_added;
  std::shared_ptr<struct_builder::State> state = std::make_shared<struct_builder::State>(
    struct_builder::State::BuildMode);

public:
  ftxui::Element OnRender() override;

private:
  void add_member(size_t type_index);

  void undo();

  void clear();

  void display_size();

  void display_optimal();
};
#endif //ORDER_MATTERS_STRUCT_BUILDER_H
