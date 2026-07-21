/*
    Prodigia comploratus,
    silens, oro:
    "Regnet exitium."
*/
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const int N = 2e5 + 5, MOD = 1e9 + 7;
const ll inf = 1e15;
char len[100000000];
int n;
int main(){
    
    int r,g,b,n;
    cin >> r >> g >> b >> n;
    int ans = 0;
    for(int i = 0; i * r <= n; i++)
        for(int j = 0; i * r + j * b <= n; j++)
            if((n - (i * r) - (j * b)) % g == 0)
                ans++;
    cout << ans << '\n';
    return 0;
}
