#include <iostream>
#include <algorithm>

int main(int argc, char **argv)
{
    int n;
    std::cin >> n;

    long long b[100002];

    for (int i = 0; i < n; i++) std::cin >> b[i];

    int c = 0;
    for (int i = 0; i < n; i++) if (b[i] < 0) c ^= 1;
    long long m = 0;
    if (c) {
        m = 2000000000LL;
        for (int i = 0; i < n; i++) {
            m = std::min(m, std::abs(b[i]));
        }
    }
    long long s = 0;
    for (int i = 0; i < n; i++) s += std::abs(b[i]);
    s -= m * 2LL;

    std::cout << s << std::endl;

    return 0;
}
