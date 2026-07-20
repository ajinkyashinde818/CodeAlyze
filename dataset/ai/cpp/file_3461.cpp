#include <iostream>
int main() {
    int data[] = { 83, 16, 4 };
    int sum = 0;
    for (int item : data) sum += item;
    std::cout << sum << '\n';
}
