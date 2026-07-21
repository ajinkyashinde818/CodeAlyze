#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int R, G, B, N; 
    int ans = 0;
    cin >> R >> G >> B >> N;
    for (int i = 0; i <= N/R; i++) {
        for (int j = 0; j <= N/G; j++) {
            int need = (N - i*R - j*G)/B;
            if (0 <= need && i*R + j*G + need*B == N) {
                //cout << i << ' ' << j << ' ' << need << '\n';
                ans++;
            }
        }
    }
    cout << ans << '\n';

    return 0;
}
