#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
using namespace std;

#define ll long long
#define mst(a) memset(a, 0, sizeof a)

const int mod = 1e9+7;
const int maxn = 1e5+50;
const int inf = 1e9;

ll x[maxn];
int v[maxn];
ll w[maxn];
ll sum_pre[maxn], sum_suf[maxn];
ll max_pre[maxn], max_suf[maxn];

int main()
{
    int n;
    ll c;
    cin >> n >> c;
    for (int i = 0; i < n; ++i)
    {
        cin >> x[i] >> v[i];
    }
    for (int i = 0; i < n; ++i)
    {
        sum_pre[i] = !i ? v[i] : sum_pre[i-1] + v[i];
        max_pre[i] = !i ? v[i]-x[i] : max(max_pre[i-1], sum_pre[i]-x[i]);        
    }
    for (int i = n-1; i >= 0; --i)
    {
        sum_suf[i] = (i == n-1) ? v[i] : sum_suf[i+1] + v[i];
        max_suf[i] = (i == n-1) ? v[i]-c+x[i] : max(max_suf[i+1], sum_suf[i]-c+x[i]);
    }
    ll ans = 0, tmp = 0;
    for (int i = 0; i < n; ++i)
    {
        tmp = sum_pre[i] - x[i];
      //  printf("%d %lld ", i, tmp);
        tmp += max(0LL, max_suf[i+1]-x[i]);
       // printf("%lld ", tmp);
        ans = max(ans, tmp);
        tmp = sum_suf[i] - c + x[i];
        //printf("%lld ", tmp);
        tmp += max(0LL, max_pre[i-1]-c+x[i]);
        ans = max(ans, tmp);
        //printf("%lld\n", tmp);
    }
    printf("%lld\n", ans);
    return 0;
}
