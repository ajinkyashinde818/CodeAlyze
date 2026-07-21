#include <iostream>
#include <string>
#include <algorithm>
#include <ctime>
#include <functional>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <cassert>
#include <bitset>
#include <list>
#include <cstdio>
#include <stdio.h>
#include <string.h>
#define rep(i,m,n) for(ll i=m;i<n;i++)
#define rrep(i,n,m) for(ll i=n;i>=m;i--)
typedef long long ll;
using namespace std;

int main()
{
    int n;
    cin >> n;
    ll a[n];
    rep(i,0,n) cin >> a[i];
    int cnt=0;
    rep(i,0,n)
    {
        if(a[i]<0) cnt++;
    }
    ll ans = 0;
    if(cnt%2 == 0)
    {
        rep(i,0,n) ans += abs(a[i]);
    }
    if(cnt%2 == 1)
    {
        rep(i,0,n) ans += abs(a[i]);
        rep(i,0,n) a[i] = abs(a[i]);
        sort(a, a+n);
        ans -= a[0]*2;
    }
    cout << ans << endl;
    return 0;
}
