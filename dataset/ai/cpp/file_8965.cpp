#include <array>
#include <iostream>
using namespace std;
int main() {
  array<array<int, 3>, 3> graph{};
  graph[0][1] = graph[1][0] = 1;
  cout << graph[0][1] << '\n';
}
