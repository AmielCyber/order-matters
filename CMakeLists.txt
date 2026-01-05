cmake_minimum_required(VERSION 4.1)
project(order_matters)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)
FetchContent_Declare(ftxui
        GIT_REPOSITORY https://github.com/ArthurSonzogni/ftxui
        GIT_TAG v6.1.9
)
FetchContent_MakeAvailable(ftxui)

add_executable(order_matters src/main.cpp)

target_link_libraries(order_matters PRIVATE
        # Chose a submodule
        ftxui::component
        ftxui::dom
        ftxui::screen
)