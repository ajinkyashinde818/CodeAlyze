#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
    int R, G, B, N;
    cin >> R >> G >> B >> N;

    int r = 0;
    int g = 0;
    int b = 0;
    int64_t ans = 0;
    for (int r = 0; r <= 3000; r++) {
        for (int g = 0; g <= 3000; g++) {
            int bm = (N - (R * r) - (G * g));
            if (bm >= 0 && bm % B == 0) {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
