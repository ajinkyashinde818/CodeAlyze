#include <iostream>
int main() {
    for (int row = 1; row <= 6; ++row) {
        for (int column = 1; column <= row; ++column) {
            std::cout << column << ' ';
        }
        std::cout << '\n';
    }
}
