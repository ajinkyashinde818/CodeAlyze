#include <iostream>
using namespace std;
 
int main() {
    int r, g, b, n;
    cin >> r >> g >> b >> n;
    int ans = 0;
 
    for (int i = 0; i < n + 1; i++) {
        if (r*i > n) 
            continue;
 
        for (int j = 0; j < n + 1; j++) {
            if (r*i + g*j > n) 
                continue;
            if ((n - r*i - g*j) % b == 0) 
                ans++;
        }
    }
 
    cout << ans << endl;
    return 0;
}
