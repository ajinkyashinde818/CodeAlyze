#include <iostream>
using namespace std;
int main() {
    int r, g, b , n; cin >> r >> g >> b >> n;

    int ans = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            int diff = n - r * i - g * j;
            if ( (diff % b == 0) && (diff >= 0) ) ans++;
        }
    }
    cout << ans << endl;
}
