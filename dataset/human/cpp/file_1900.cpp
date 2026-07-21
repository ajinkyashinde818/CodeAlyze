#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

using uint = unsigned int;

const uint sign = 0b10000000000000000000000000000000;
const uint inte = 0b01111111111111111111111110000000;
const uint flot = 0b00000000000000000000000001111111;

int n;

uint input() {
    uint u;

    std::cin >> std::hex >> u;

    return u;
}

std::string format(double d) {
    std::stringstream ss;

    ss << std::fixed << std::setprecision(30) << d;

    std::string str;

    ss >> str;

    str = str.substr(2, str.size() - 1);

    int i;
    for(i = str.size() - 1; i >= 0 && str[i] == '0'; --i) {}

    return str.substr(0, i + 1);
}

int main() {
    std::cin >> n;

    for(int i = 0; i < n; ++i) {
        uint a = input();

        if(sign & a){
            std::cout << "-";
        }

        std::cout << ((inte & a) >> 7) << ".";

        if((flot & a) == 0){
            std::cout << 0 << std::endl;
        }else {
            double d = 0.5;
            double sum = 0;

            for(int i = 0; i < 7; ++i) {
                if(a & (1 << (6 - i))) {
                    sum += d;
                }
                d /= 2;
            }
            std::cout << format(sum) << std::endl;
        }
    }
}
