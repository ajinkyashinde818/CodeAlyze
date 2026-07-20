#include <iostream>
int main() {
    int data[] = { 29, 20, 4 };
    int sum = 0;
    for (int item : data) sum += item;
    std::cout << sum << '\n';
}
