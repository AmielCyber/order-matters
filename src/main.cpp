#include <iostream>
#include <ostream>

struct my_struct{};

int main() {
  std::cout << "Struct Size: " << '\n';
  std::cout << '\t' << "my_struct{}; // "<< sizeof(my_struct) << " byte" << std::endl;
  return 0;
}
