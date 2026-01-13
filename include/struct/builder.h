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
    OptimalOutput, SizeOutput,
    Full,
  };

  /**
   * Data type of struct member.
   * Contains the name and size of that type.
   */
  struct DataType {
    std::string_view name{};
    size_t size{};

    constexpr DataType(const std::string_view name, const size_t size) : name(name), size(size) {}
  };

  /**
   * Object inside struct containing type (name and size),offset location in struct, and padding.
   */
  struct StructObject {
    /**
     *
     * @param type Data type containing name and size
     * @param offset Offset position in the structure, if is the first object in structure then it will be 0
     * @param padding The amount of padding after this object
     */
    explicit StructObject(const DataType &type, const size_t offset = 0,
                          const size_t padding = 0) : type(type), offset(offset), padding(padding) {}

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

    // Max size containing variable names
    inline constexpr size_t max_size = names.size();

    // Predefined data types, may extend this to common std types
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
    /**
     * Builds a struct based on the passed state, such as just the struct or a struct
     * with size and padding displayed.
     * @param state Struct builder state to determine its output
     * @param members The data type members added to the struct
     * @return string representation of the struct created depending on the state
     */
    static std::string build(State state, const std::vector<DataType> &members);

  private:
    /**
     * Gets a string representation of a structure: struct my_struct {...},
     * @param types_added The types added to the structure.
     * @return string representation of a structure.
     */
    static std::string get_member_output_list(const std::vector<DataType> &types_added);

    /**
     * Gets a string representation of a structure: struct my_struct {...} with comments next to
     * the variable name to display size of type and padding added after that variable.
     * @param types_added The types added to the structure.
     * @return string representation of a structure with comments containing memory layout.
     */
    static std::string get_member_output_list_with_size(const std::vector<DataType> &types_added);

    /**
     * Gets a string representation of a structure that is restructured to get the smallest size:
     * struct my_struct {...} with comments next to the variable name to display size of type and
     * padding added after that variable.
     * @param types_added The types added to the structure.
     * @return string representation of a structure with comments containing memory layout.
     */
    static std::string get_optimal_member_output_list(const std::vector<DataType> &types_added);

    /**
     * Get the natural alignment of a structure based on its type members.
     * @param types_added The types added to the structure.
     * @return The natural alignment of a struct containing the passed types.
     */
    static size_t get_alignment(const std::vector<DataType> &types_added);

    /**
     * Gets the memory layout representation of a structure based on its members.
     * @param types_added The types added to the structure.
     * @return A list of Struct Objects representing the memory layout of a struct.
     */
    static std::vector<StructObject> get_layout(const std::vector<DataType> &types_added);

    /**
     * Provides the comments to add to a struct member to display amount of bytes and padding added to this variable.
     * @param struct_object Struct object
     * @return A comment with struct member layout information.
     */
    static std::string get_member_size(const StructObject &struct_object);
  };
}
#endif //ORDER_MATTERS_BUILDER_H
