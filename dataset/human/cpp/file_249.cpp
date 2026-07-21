#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N = 1e5 + 10;

int main() {
    int r, g, b, n, cnt = 0;
    cin >> r >> g >> b >> n;
    for(int i = 0; i <= n; i++) {
        if(i * r > n) break;
        for(int j = 0; j <= n; j++) {
            if(i * r + j * g > n) break;
            int res = i * r + j * g;
            if((n - res) % b == 0) {
                cnt++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}
