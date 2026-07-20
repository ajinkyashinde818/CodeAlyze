#include <iostream>
int main() {
    int data[] = { 22, 32, 5 };
    int sum = 0;
    for (int item : data) sum += item;
    std::cout << sum << '\n';
}
