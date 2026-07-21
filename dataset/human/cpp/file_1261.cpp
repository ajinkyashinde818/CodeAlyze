#include <iostream>
using namespace std;

int main() {
    int R, G, B, N; cin >> R >> G >> B >> N;
    int n_r = N / R, n_g = N / G;
    int b, r_b, count = 0;
    for (int r = 0; r <= n_r; r++) {
        for (int g = 0; g <= n_g; g++) {
            b = (N - R * r - G * g) / B;
            r_b = (N - R * r - G * g) % B;
            if (b >= 0 && r_b == 0) count++;
        }
    }
    cout << count << endl;
    return 0;
}
