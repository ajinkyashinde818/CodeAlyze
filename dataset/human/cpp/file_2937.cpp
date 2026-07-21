#include <iostream>
#include <vector>

using ll = long long;

int
main(int argc, char** argv) {
    int N;
    std::cin >> N;

    ll ans = 0;
    int minA = 0x7fffffff;
    std::vector<int> A(N);
    int neg = 0;
    for (int i = 0; i < N; i++) {
       std::cin >> A[i];
       ans += std::abs(A[i]);
       if (A[i] < 0) neg++;
       minA = std::min(minA, std::abs(A[i]));
    }

    if ((neg % 2) != 0) {
       ans -= std::abs(minA) * 2;
    }

    std::printf("%lld\n", ans);
    return 0;
}
