cmake_minimum_required(VERSION 4.1)
project(order_matters)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)
FetchContent_Declare(ftxui
        GIT_REPOSITORY https://github.com/ArthurSonzogni/ftxui
        GIT_TAG v6.1.9
)
FetchContent_MakeAvailable(ftxui)

add_executable(order_matters src/main.cpp
        include/component/main_menu.h
        src/component/main_menu.cpp
        include/component/data_type_select.h
        src/component/data_type_selection.cpp
        include/component/action_buttons.h
        src/component/action_buttons.cpp
        include/component/struct_output.h
        src/component/struct_output.cpp
        include/component/struct_builder.h
        src/component/struct_builder.cpp
        include/struct/builder.h
        src/struct/builder.cpp
)

target_include_directories(order_matters PRIVATE
        ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(order_matters PRIVATE
        # Chose a submodule
        ftxui::component
        ftxui::dom
        ftxui::screen
)