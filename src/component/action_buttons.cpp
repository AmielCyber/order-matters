#include "component/action_buttons.h"
#include "ftxui/component/component.hpp"

using namespace ftxui;

ActionButtonsComponent::ActionButtonsComponent(
  const std::function<void()> &on_undo,
  const std::function<void()> &on_clear,
  const std::function<void()> &on_get_size_button,
  const std::function<void()> &on_get_optimal_button
) {
  const auto button_options = ButtonOption::Animated();
  const auto undo_button = Button(std::format("{: <8}", "Undo"), on_undo, button_options);
  const auto clear_button = Button(std::format("{: <8}", "Clear"), on_clear, button_options);
  const auto size_button = Button(std::format("{: <8}", "Size"), on_get_size_button, button_options);
  const auto optimal_button = Button(std::format("{: <8}", "Optimal"), on_get_optimal_button, button_options);
  action_buttons_container = Container::Vertical({
    Container::Horizontal({undo_button, clear_button}, &selected_button) | flex,
    Container::Horizontal({size_button, optimal_button}, &selected_button) | flex,
  });
  Add(action_buttons_container);
}

Element ActionButtonsComponent::OnRender() {
  return vbox({
           text("Action") | bold,
           separator(),
           action_buttons_container->Render()
         }) | border;
}
