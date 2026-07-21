#include <iostream>

using namespace std;

int main() {
    int R, G, B, N;
    cin >> R >> G >> B >> N;

    int ans = 0;
    for (int i = 0; i <= 3000; i++) {
        for (int j = 0; j <= 3000; j++) {
            int t = i * R + j * G;
            if (t <= N and (N - t) % B == 0) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
