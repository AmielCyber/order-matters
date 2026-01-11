#ifndef ORDER_MATTERS_BUILDER_H
#define ORDER_MATTERS_BUILDER_H
#include <array>
#include <string>
#include "data_type_member.h"

namespace struct_builder {
  enum class State {
    BuildMode,
    OptimalOutput,
    SizeOutput,
    Full,
  };

  namespace member {
    inline constexpr std::array names =
        {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j"};

    inline constexpr size_t max_size = names.size();

    inline constexpr std::array types = {
      DataType("bool", sizeof(bool)),
      DataType("char", sizeof(char)),
      DataType("int", sizeof(int)),
      DataType("size_t", sizeof(size_t)),
      DataType("double", sizeof(double)),
      DataType("long", sizeof(long)),
      DataType("ptr*", sizeof(nullptr)),
    };
  }
}
#endif //ORDER_MATTERS_BUILDER_H
