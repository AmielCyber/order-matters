#ifndef ORDER_MATTERS_MAIN_MENU_H
#define ORDER_MATTERS_MAIN_MENU_H
#include "ftxui/component/component.hpp"
#include "ftxui/component/component_base.hpp"

class MainMenuComponent: public ftxui::ComponentBase {
public:
  explicit MainMenuComponent(std::string app_title);
  ftxui::Element OnRender() override;
private:
  std::string app_title;
};

#endif //ORDER_MATTERS_MAIN_MENU_H
