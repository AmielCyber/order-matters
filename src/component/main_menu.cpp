#include "component/main_menu.h"
#include <utility>

using namespace ftxui;

MainMenuComponent::MainMenuComponent(std::string app_title)
  :app_title{std::move(app_title)} {
}

Element MainMenuComponent::OnRender() {
  // May add a menu component for different app functionalities.
  return vbox({
    text(app_title) | bold | hcenter ,
  });
}
