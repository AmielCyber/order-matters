#ifndef ORDER_MATTERS_ACTION_COMPONENT_H
#define ORDER_MATTERS_ACTION_COMPONENT_H
#include "ftxui/component/component_base.hpp"

class ActionButtonsComponent : public ftxui::ComponentBase {
  ftxui::Component action_buttons_container;
  int selected_button = 0;
public:
  ActionButtonsComponent(
    const std::function<void()> &on_undo,
    const std::function<void()> &on_clear,
    const std::function<void()> &on_get_size_button,
    const std::function<void()> &on_get_optimal_button
  );
  ftxui::Element OnRender() override;
};

#endif //ORDER_MATTERS_ACTION_COMPONENT_H