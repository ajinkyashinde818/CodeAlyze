#include <iostream>

using namespace std;

int main() {

    int r, g, b, n;
    cin >> r >> g >> b >> n;

    long long int ans = 0;

    for (int i = 0; i <= n/r; i++) {
        for (int j = 0; j <= n/g; j++) {
            int kari = r*i+g*j;
            if ((n-kari) >= 0 && (n-kari) % b == 0) {
                //cout << i << ' ' << j << endl;
                ans++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
