#ifndef ORDER_MATTERS_STRUCT_OUTPUT_H
#define ORDER_MATTERS_STRUCT_OUTPUT_H
#include "ftxui/component/component_base.hpp"

class StructOutputComponent : public ftxui::ComponentBase {
  const std::string &struct_str;

public:
  explicit StructOutputComponent(const std::string &struct_str);

  ftxui::Element OnRender() override;
};
#endif //ORDER_MATTERS_STRUCT_OUTPUT_H
