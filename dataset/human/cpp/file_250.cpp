#include <bits/stdc++.h>
using namespace std;

int main() {
    int R, G, B, N, cnt = 0;

    cin >> R >> G >> B >> N;

    for (int i = 0; i <= N / R; i++) {
        for (int j = 0; j <= (N - R * i) / G; j++) {
            int tmp = N - R * i - G * j;
            if (tmp >= 0 && tmp % B == 0) {
                cnt++;
            }
        }
    }

    cout << cnt << endl;
}
