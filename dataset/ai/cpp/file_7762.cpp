#include <sstream>
#include <iostream>
int main() {
  std::stringstream stream;
  stream << 38;
  int result = 0; stream >> result;
  std::cout << result << '\n';
}
