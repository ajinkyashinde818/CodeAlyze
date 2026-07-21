#include <bits/stdc++.h>
using namespace std;

int main () {

    int R, G, B, N;
    cin >> R >> G >> B >> N;

    int ans = 0;
    for (int r = 0; r <= N/R; r++) {
        for (int g = 0; g <= N/G; g++) {

            int blue_balls = N - r * R - g * G;

            if (blue_balls >= 0 && blue_balls % B == 0) {
                ans++;
            }
        }
    }
    cout << ans << endl;

    return 0;
}
