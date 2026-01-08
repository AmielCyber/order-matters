#ifndef ORDER_MATTERS_DATA_TYPE_MEMBER_H
#define ORDER_MATTERS_DATA_TYPE_MEMBER_H
#include <string>
#include <utility>

struct DataTypeMember {
  DataTypeMember(std::string name, const size_t size) : name{std::move(name)}, size{size} {}
  const std::string name{};
  const size_t size{};
};

#endif //ORDER_MATTERS_DATA_TYPE_MEMBER_H
