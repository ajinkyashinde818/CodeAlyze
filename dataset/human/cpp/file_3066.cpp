#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5;

int n, arr[MAXN+10];
ll minval=987654321, s=0, cnt;
int main()
{
    int i, j;

    scanf("%d", &n);
    for(i=1; i<=n; i++)
    {
        scanf("%d", &arr[i]);
        if(arr[i]<0) cnt++;
        arr[i]=abs(arr[i]);
        minval=min(minval, (ll)arr[i]);
        s+=arr[i];
    }
    if(cnt%2==0) printf("%lld", s);
    else printf("%lld", s-minval-minval);
}
