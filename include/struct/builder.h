#ifndef ORDER_MATTERS_BUILDER_H
#define ORDER_MATTERS_BUILDER_H
#include <array>
#include <string>
#include <vector>

/**
 * struct_builder namespace where we will have all the tools to create
 * a string struct along with metadata of a struct.
 */
namespace struct_builder {
  /**
   * State of the struct builder.
   */
  enum class State {
    BuildMode,
    OptimalOutput,
    SizeOutput,
    Full,
  };

  /**
   * DataType of a struct member.
   * Containing name such as 'bool' and size of that type.
   */
  struct DataType {
    std::string_view name{};
    size_t size{};

    constexpr DataType(const std::string_view name, const size_t size) : name(name), size(size) {
    }
  };

  /**
   * Object inside struct containing type(name and size),
   * offset location in struct, and padding.
   */
  struct StructObject {
    explicit StructObject(const DataType &type, const size_t offset = 0,
                          const size_t padding = 0) : type(type), offset(offset), padding(padding) {
    }

    DataType type;
    size_t offset;
    size_t padding;
  };

  /**
   * Member namespace constants for our application.
   */
  namespace member {
    // Predefined variable names.
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

  /**
   * Builder static class to create string structs along with adding comments containing:
   * the member size and padding size.
   */
  class Builder {
  public:
    static std::string build(State state, const std::vector<DataType> &members);

  private:
    static std::string get_member_output_list(const std::vector<DataType> &types_added);

    static std::string get_member_output_list_with_size(const std::vector<DataType> &types_added);

    static std::string get_optimal_member_output_list(const std::vector<DataType> &types_added);

    static size_t get_alignment(const std::vector<DataType> &types_added);

    static std::vector<StructObject> get_layout(const std::vector<DataType> &types_added);

    static std::string get_member_size(const StructObject &struct_object);
  };
}
#endif //ORDER_MATTERS_BUILDER_H
