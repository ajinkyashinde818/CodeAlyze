#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <iostream>
#include <set>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

const int mod = 1e9+7;
#define ll long long int
const double epsilon = 1e-7;

ll ma(ll x, ll y){
    if(x>y)return x;
    return y;
}
struct hoge
{
    ll fx, bx, v, f1, b1, f2, b2, f2m, b2m;
};

struct hoge arr[100000];
int main(void){
    int n;
    ll c;
    scanf("%d %lld", &n, &c);
    ll vsum = 0;
    ll f = 0;
    for(int i = 0;i < n;i++){
        scanf("%lld %lld", &arr[i].fx, &arr[i].v);
        vsum += arr[i].v;
        arr[i].f1 = vsum - arr[i].fx;
        arr[i].f2 = vsum - arr[i].fx*2;
        arr[i].bx = c - arr[i].fx;
        f = ma(f, arr[i].f2);
        arr[i].f2m = f;
    }
    vsum = 0;
    ll b = 0;
    for(int i = n-1;i >= 0;i--){
        vsum += arr[i].v;
        arr[i].b1 = vsum - arr[i].bx;
        arr[i].b2 = vsum - arr[i].bx*2;
        b = ma(b, arr[i].b2);
        arr[i].b2m = b;
    }
    ll ans = 0;
    for(int i = 0;i < n-1;i++){
        ans = ma(ans, arr[i].f1 + arr[i+1].b2m);
    }
    ans = ma(ans, arr[n-1].f1);
    for(int i = n-1;i > 0;i--){
        ans = ma(ans, arr[i].b1 + arr[i-1].f2m);
    }
    ans = ma(ans, arr[0].b1);
    printf("%lld\n", ans);
    return 0;
}
