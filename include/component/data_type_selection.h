#ifndef ORDER_MATTERS_MEMBER_TYPE_SELECT_H
#define ORDER_MATTERS_MEMBER_TYPE_SELECT_H
#include "ftxui/component/component_base.hpp"
#include "struct/data_type_member.h"

class DataTypeSelectionComponent : public ftxui::ComponentBase {
  ftxui::Component button_list_container;
public:
  DataTypeSelectionComponent(
      const std::vector<std::shared_ptr<DataType>>& members,
      const std::function<void(size_t)>& on_select
  );
  // Override Render to define the visual layout
  ftxui::Element OnRender() override;
};
#endif //ORDER_MATTERS_MEMBER_TYPE_SELECT_H