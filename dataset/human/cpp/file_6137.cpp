#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>
using namespace std;
int n;
long long int x[100003];
long long int v[100003];
long long int ls[100003];
long long int rs[100003];
long long int c;
int main()
{
    scanf("%d%lld", &n, &c);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld%lld", &x[i], &v[i]);
    }
    x[n+1] = c;
    long long int cur = 0;
    for(int i=1;i<=n;i++)
    {
        cur += v[i] - (x[i] - x[i-1]);
        ls[i] = max(ls[i-1], cur);
    }
    cur = 0;
    for(int i=n;i;i--)
    {
        cur += v[i] - (x[i+1] - x[i]);
        rs[i] = max(rs[i+1], cur);
    }
    long long int ans = max(ls[n], rs[1]);
    for(int i=1;i<=n;i++)
    {
        ans = max({ls[i] + rs[i+1] - x[i], rs[i] + ls[i-1] - (c - x[i]), ans});
    }
    printf("%lld\n", ans);
}
