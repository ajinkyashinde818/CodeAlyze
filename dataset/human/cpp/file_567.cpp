#include <bits/stdc++.h>
using namespace std;
int R, G, B, n;
int main() {
    cin >> R >> G >> B >> n;
    int r, g, b;
    int rmax = n/R; int gmax = n/G; int bmax = n/B;

    int cnt = 0;
    for(int i = 0; i <= rmax; ++i) {
        for(int j = 0; j <= gmax; ++j) {
            if(R*i+G*j <= n) {
                if((n - R*i - G*j) % B == 0) cnt++;
            }
        }
    }
    cout << cnt << endl;
}
