#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);    
    int R, G, B, N;
    cin >> R >> G >> B >> N;
    long long ans = 0;
    for (int r = 0; r <= 3000; ++r) {
        for (int g = 0; g <= 3000; ++g) {
            int left = N - r * R - g * G;
            if (left >= 0 && left % B == 0) {
                ++ans;
            }
        }
    }
    cout << ans;
    return 0;
}
