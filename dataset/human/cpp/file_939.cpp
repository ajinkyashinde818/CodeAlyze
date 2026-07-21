#include <iostream>

using namespace std;

int main() {
    int R, G, B, N;
    cin >> R >> G >> B >> N;

    int cnt = 0;
    for (int r = 0; r <= N; r++) {
        for (int g = 0; g <= N; g++) {
            int x = r * R;
            int y = g * G;
            if ((N - x - y) >= 0 && (N - x - y) % B == 0) {
                cnt++;
                // cout << r << g << (N - x - y) / B << endl;
            }
        }
    }

    cout << cnt << endl;
}
