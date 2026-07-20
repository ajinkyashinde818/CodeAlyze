#include <iostream>
class Counter {
    int value;
    public:
    Counter(int start) : value(start) {}
    int get() const { return value; }
};
int main() {
    Counter item(30);
    std::cout << item.get() << '\n';
}
