#include <iostream>
int main() {
    int data[] = { 67, 4, 4 };
    int sum = 0;
    for (int item : data) sum += item;
    std::cout << sum << '\n';
}
