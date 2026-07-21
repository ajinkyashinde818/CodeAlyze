#include <bits/stdc++.h>
using namespace std;

int main() {
    int r, g, b, n;
    int count = 0;
    cin >> r >> g >> b >> n;
    for (int i = 0; i <= n; i += r) {
        for (int j = 0; j <= n; j += g) {
            if (n - i - j >= 0 && (n - i - j) % b == 0) {
                count++;
            }
        }
    }
    cout << count << endl;
    return 0;
}
