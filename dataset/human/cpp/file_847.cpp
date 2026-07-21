#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int r, g, b, n, R, G;
    cin >> r >> g >> b >> n;
    long long int cnt = 0;

    for(long long int i = 0; i <= n / r ; i++){
        R = r * i;
        for(long long int j = 0; j <= (n - R) / g ; j++){
            G = g * j;
            if((n - R - G) % b == 0) cnt++;
        }
    }

    cout << cnt << endl;
}
