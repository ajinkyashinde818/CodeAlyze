#include <iostream>

int main() {
    int N;
    int A[100001];
    std::cin >> N;
    long long ans = 0;
    int parity = 0;
    int absmin = 1000000000;
    for (int i = 1; i <= N; ++i) {
        std::cin >> A[i];
        if (A[i] >= 0) {
        } else {
            A[i] = -A[i];
            parity = (parity == 0) ? 1 : 0;
        }
        ans += A[i];
        absmin = (A[i] < absmin) ? A[i] : absmin;
    }
    ans = ans - 2 * absmin * parity;
    std::cout << ans << "\n";
    return 0;
}
