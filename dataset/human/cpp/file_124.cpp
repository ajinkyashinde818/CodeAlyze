#include<iostream>
using namespace std;
typedef long long ll;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    
    int r, g, b, n;
    cin >> r >> g >> b >> n;

    int ans = 0;
    for (int x = 0; x <= n / r; x++) {
        int max_y = (n - r * x) / g;
        for (int y = 0; y <= max_y; y++) {
            if ((n - r * x - g * y) % b == 0) ans++;
        }
    }

    cout << ans << endl;
}
