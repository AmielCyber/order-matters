#ifndef ORDER_MATTERS_DATA_TYPE_MEMBER_H
#define ORDER_MATTERS_DATA_TYPE_MEMBER_H
#include <string>
#include <utility>

struct DataType {
  const std::string_view name{};
  const size_t size{};

  constexpr DataType(std::string_view name, const size_t size) : name(std::move(name)), size(size) {
  }
};

#endif //ORDER_MATTERS_DATA_TYPE_MEMBER_H
