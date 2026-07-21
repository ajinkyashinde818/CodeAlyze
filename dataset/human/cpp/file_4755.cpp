#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<set>
#include<map>
#include<algorithm>
#include<deque>
#include<stack>
#include<vector>
#include<cmath>
using namespace std;
typedef long long ll;
const ll INF = 0x3f3f3f3f;
const ll mod = 1e9 + 7;
const ll maxn = 1e5 + 5;
const double PI = acos(-1);
void std_quick_io () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int main () {
    std_quick_io();
    int n, r;
    cin >> n >> r;
    if(n >= 10)
    cout <<r;
    else {
        cout << r + 100 *( 10 - n);
    }
    return 0;
}
