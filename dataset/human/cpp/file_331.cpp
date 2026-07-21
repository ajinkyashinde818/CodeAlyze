#include <bits/stdc++.h>

using namespace std;

int main()
{
    int r, g, b, n, ans = 0, tmp;
    cin >> r >> g >> b >> n;

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            tmp = n - (i*r + j*g);
            if(tmp >= 0 && tmp % b == 0) ans++;
        }
    }

    cout << ans << endl;

    return 0;
}
