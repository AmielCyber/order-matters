#ifndef ORDER_MATTERS_MEMBER_TYPE_SELECT_H
#define ORDER_MATTERS_MEMBER_TYPE_SELECT_H
#include "ftxui/component/component_base.hpp"

class DataTypeSelectComponent : public ftxui::ComponentBase {
  ftxui::Component button_list_container;
  const size_t scrollable_size = 10;

public:
  explicit DataTypeSelectComponent(
    const std::function<void(size_t)> &on_select
  );

  ftxui::Element OnRender() override;
};
#endif //ORDER_MATTERS_MEMBER_TYPE_SELECT_H
