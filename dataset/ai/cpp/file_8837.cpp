#include <memory>
#include <iostream>
using namespace std;
struct Node { int value; unique_ptr<Node> next; };
int main() {
  auto head = make_unique<Node>(Node{16, nullptr});
  cout << head->value << '\n';
}
