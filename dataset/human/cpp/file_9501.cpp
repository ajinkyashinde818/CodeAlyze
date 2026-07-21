//include <bits/stdc++.h>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <sstream>
#include <cmath>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <utility>
#include <string>
#include <set>
#include <map>
#include <cassert>
using namespace std;
typedef long long ll;
typedef double D;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define pf push_front
#define pof push_front
#define pb push_back
#define pob pob_back
#define FOR(i, n) for (int i = 0; i < n; i++)
#define FOR_(i, n) for (int i = n; i >= 0; i--)
#define FOR1(i, n) for(int i = 1; i <= n; i++)
#define FOR2(i, a, b) for (int i = a; a <= b; i++)
#define FOR2_(i, b, a) for (int i = b; i >= a; i--)
#define IOS ios::sync_with_stdio(0); cin.tie(0);
#ifdef momo
#define  debug(...) do{\
fprintf(stderr,"%s - %d : (%s) = ",__PRETTY_FUNCTION__,__LINE__,#__VA_ARGS__);\
_do(__VA_ARGS__);\
}while(0)
template<typename t> void _do(t &&_x){cerr<<_x<<endl;}
template<typename t,typename ...T> void _do(t &&_x,T &&...tail){cerr<<_x<<", ";_do(tail...);}
#else
#define debug(...)
#endif

int N, M;
string A[200], B[200];

bool check(int x1, int y1, int n1, int n2)
{
    FOR(i, n1) {
        FOR(j, n2) {
            if (A[x1+i][y1+j] != B[i][j]) return false;
        }
    }
    return true;
}



int main(void)
{
    IOS;
    
    cin >> N >> M;
    FOR(i, N) cin >> A[i];
    FOR(j, M) cin >> B[j];
    
    bool ans = false;
    FOR(i, N)
        FOR(j, N)
            if (check(i, j, M, M)) {
                ans = true; break;
            }
    if (ans) puts("Yes");
    else puts("No");
    return 0;
}
