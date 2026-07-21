#include <bits/stdc++.h>

using namespace std;

int main() {
    int R, G, B, N;
    cin >> R >> G >> B >> N;

    int ans = 0;
    for (int i = 0; i * R <= N; i++) {
        const int cur_r = i * R;
        for (int j = 0; cur_r + j * G <= N; j++) {
            const int cur_g = j * G;
            const int cur_b = N - cur_r - cur_g;
            if (cur_b < 0 || (cur_b > 0 && cur_b % B != 0)) {
                continue;
            }
            // cout << cur_r << " " << cur_g << " " << cur_b << endl;
            ans++;
        }
    }

    cout << ans << endl;
}
