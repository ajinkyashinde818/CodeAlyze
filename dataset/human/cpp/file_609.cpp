#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int R, G, B, N, count = 0;
    cin >> R >> G >> B >> N;
    for (int i = 0; i <= 3000; i++) {
        for (int j = 0; j <= 3000; j++) {
            if (0 <= (N - R * i - G * j) / B && (N - R * i - G * j) / B <= 3000 && (N - R * i - G * j) % B == 0) {
                count++;
                // cout << i << j << (N - R * i - G * j) / B << endl;
            }
        }
    }
    cout << count << endl;
}
