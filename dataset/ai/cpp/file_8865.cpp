#include <memory>
#include <iostream>
struct Node { int value; std::unique_ptr<Node> next; };
int main()
{
    auto head = std::make_unique<Node>(Node{6, nullptr});
    std::cout << head->value << '\n';
}
