#include <array>
#include <iostream>
int main() {
  std::array<std::array<int, 3>, 3> graph{};
  graph[0][1] = graph[1][0] = 1;
  std::cout << graph[0][1] << '\n';
}
