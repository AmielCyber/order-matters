#include "struct/builder.h"
#include <format>

std::string struct_builder::Builder::build(const State state, const std::vector<DataType> &members) {
  std::string output = "struct my_struct {\n";
  switch (state) {
    case State::BuildMode:
      output += get_member_output_list(members);
      break;
    case State::SizeOutput:
      output += get_member_output_list_with_size(members);
      break;
    case State::OptimalOutput:
      output += get_optimal_member_output_list(members);
      break;
    default: throw std::runtime_error("Unknown state entered.");
  }
  output += '}';
  return output;
}

std::string struct_builder::Builder::get_member_output_list(
  const std::vector<DataType> &types_added) {
  if (types_added.empty()) return "\n";
  std::string output;
  for (int i = 0; i < types_added.size() && i < member::max_size; ++i) {
    output += std::format("  {} {}{{}};\n", types_added.at(i).name, member::names.at(i));
  }
  return output;
}

std::string struct_builder::Builder::get_member_output_list_with_size(
  const std::vector<DataType> &types_added) {
  if (types_added.empty()) return "\n";
  const std::vector<struct_builder::StructObject> struct_layout = get_layout(types_added);
  std::string output;

  for (int i = 0; i < types_added.size() && i < member::max_size; ++i) {
    output += std::format("  {} {}{{}}; {}\n", types_added.at(i).name, member::names.at(i), get_member_size(struct_layout.at(i))) ;
  }

  size_t total_bytes = struct_layout.back().offset + struct_layout.back().type.size + struct_layout.back().padding;
  output += std::format("  // Struct Size = {} {}\n",total_bytes, total_bytes > 1? "bytes" : "byte");
  return output;
}

std::string struct_builder::Builder::get_optimal_member_output_list(
  const std::vector<DataType> &types_added) {
  auto optimal_ordering = std::vector<DataType>(types_added);
  std::ranges::sort(optimal_ordering, [](const DataType &a, const DataType &b) {
    return a.size > b.size;
  });
  return get_member_output_list_with_size(optimal_ordering);
}

size_t struct_builder::Builder::get_alignment(const std::vector<DataType> &types_added) {
  size_t alignment = 0;
  for (const auto &type: types_added) {
    if (alignment < type.size) {
      alignment = type.size;
    }
  }
  return alignment;
}

std::vector<struct_builder::StructObject> struct_builder::Builder::get_layout(const std::vector<DataType> &types_added) {
  std::vector<StructObject> struct_layout;
  if (types_added.empty()) {
    return struct_layout;
  }
  // Reserve allocation size for performance.
  struct_layout.reserve(struct_layout.size());

  // Get Natural Alignment of Struct
  const size_t alignment = get_alignment(types_added);
  size_t offset = 0;
  for (const DataType& type: types_added) {
    if (!struct_layout.empty() && offset % type.size != 0) {
      size_t padding = 0;
      if (type.size > offset) {
        padding = type.size - offset;
      } else {
        padding = offset % type.size;
      }
      offset += padding;
      // Add padding to previous type
      struct_layout.back().padding = padding;
    }
    struct_layout.emplace_back(type, offset);
    offset += type.size;
  }
  // Add any additional padding.
  struct_layout.back().padding = offset % alignment;
  return struct_layout;
}

std::string struct_builder::Builder::get_member_size(const StructObject &struct_object) {
  std::string output = std::format("// {} byte", struct_object.type.size);
  if (struct_object.type.size > 1) {
    output += 's';
  }
  if (struct_object.padding > 0) {
    output += std::format(" + {} byte", struct_object.padding);
    if (struct_object.padding > 1) {
      output += 's';
    }
    output += " of padding";
  }
  return output;
}