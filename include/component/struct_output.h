#ifndef ORDER_MATTERS_STRUCT_OUTPUT_H
#define ORDER_MATTERS_STRUCT_OUTPUT_H
#include "ftxui/component/component_base.hpp"
#include "struct/builder.h"


class StructOutputComponent : public ftxui::ComponentBase {
  std::shared_ptr<std::vector<struct_builder::DataType> > types_added;
  std::shared_ptr<struct_builder::State> struct_state;

public:
  StructOutputComponent(const std::shared_ptr<std::vector<struct_builder::DataType> > &members_added,
                        const std::shared_ptr<struct_builder::State> &state);

  ftxui::Element OnRender() override;

private:
  [[nodiscard]] std::string get_struct_output() const;
};
#endif //ORDER_MATTERS_STRUCT_OUTPUT_H
