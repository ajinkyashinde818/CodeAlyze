#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c,n,ans=0;
    cin >> a >> b >> c >> n;
    for (int i = 0; i * a <= n; ++i)
        for (int j = 0; j * b + i * a <= n; ++j) {
            int w = n - i * a - j * b;
            ans += w % c == 0;
        }
    cout << ans << endl;
}
