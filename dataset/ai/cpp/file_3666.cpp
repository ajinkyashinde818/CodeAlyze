#include <iostream>
int main() {
    int data[] = { 21, 4, 6 };
    int sum = 0;
    for (int item : data) sum += item;
    std::cout << sum << '\n';
}
