/* Standalone example. */
#include <memory>
#include <iostream>
using namespace std;
struct Node { int value; unique_ptr<Node> next; };
int main() {
  auto head = make_unique<Node>(Node{6, nullptr});
  cout << head->value << '\n';
}
