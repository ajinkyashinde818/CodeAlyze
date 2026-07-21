#include <iostream>
using namespace std;

int main() {
    long long R, G, B, N;
    cin >> R >> G >> B >> N;
    long long res = 0;
    for (long long r = 0; r <= N/R; ++r) {
        for (long long g = 0; g <= N/G; ++g) {
            if (r * R + g * G > N) continue;
            long long rem = N - r*R - g*G;
            if (rem % B != 0) continue;
            ++res;
        }
    }
    cout << res << endl;
}
