#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int R, G, B, N;
    cin >> R >> G >> B >> N;
    int ans = 0;

    for(int i = 0; i <= 3000; i++) {
        for(int j = 0; j <= 3000; j++) {
            if(!((N - i*R - j*G)%B) && N >= i*R + j*G) {
                ans++;
            }
        }
    }

    cout << ans << endl;


    return 0;
}
