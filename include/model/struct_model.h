#ifndef ORDER_MATTERS_STRUCT_MODEL_H
#define ORDER_MATTERS_STRUCT_MODEL_H
#include <string>
#include <vector>
#include "struct/builder.h"


struct StructModel {
  std::vector<struct_builder::DataType> members{};
  struct_builder::State state = struct_builder::State::BuildMode;
  std::string to_string = std::string(struct_builder::Builder::empty_struct_str);
};

#endif //ORDER_MATTERS_STRUCT_MODEL_H