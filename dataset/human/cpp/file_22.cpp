#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int r, g, b, n, ans;

int main()
{
    int i, j;
    scanf("%d%d%d%d", &r, &g, &b, &n);

    for(i=0; i<=n/r; i++)
    {
        for(j=0; j<=n/g; j++)
        {
            int t=n-i*r-j*g;
            if(t>=0 && t%b==0) ans++;
        }
    }
    printf("%d", ans);
}
