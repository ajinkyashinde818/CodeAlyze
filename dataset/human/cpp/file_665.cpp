#include <iostream>

using namespace std;

int main() {
    int R, G, B, N;
    cin >> R >> G >> B >> N;

    int ans = 0;
    int mr = N / R;
    for (int i = 0; i < mr + 1; i++) {
        int mg = (N - i * R) / G;
        for (int j = 0; j < mg + 1; j++) {
            int b = N - i * R - j * G;
            if (b % B == 0) {
                ans += 1;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
