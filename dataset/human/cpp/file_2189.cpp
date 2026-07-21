#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[100000][2];
ll solve(ll a[], int s, int e, int f){
    if(s > e)
    return 0;
    if(dp[s][f] != INT_MIN){
    return dp[s][f];
    }
    ll so = INT_MIN;
    if(f == 0)
    so = a[s] + solve(a, s + 1, e, 0);
    else
    so = -a[s] + solve(a, s + 1, e, 0);
    //cout << s << " " << f << " " << so << endl;
    if(s < e){
        if(f == 0)
        so = std::max(so, -a[s] + solve(a, s + 1, e, 1));
        else
        so = std::max(so, a[s] + solve(a, s + 1, e, 1));
    }
    //cout << s << " " << f << " " << so << endl;
    return dp[s][f] = so;
}
int main() {
    int n;
    cin >> n;
    ll a[n];
    for(int i = 0; i < n; i++)
    cin >> a[i];
    for(int i = 0; i < 100000; i++){
        for(int j = 0; j < 2; j++)
            dp[i][j] = INT_MIN;
    }
    cout << solve(a, 0, n-1, 0); 
    return 0;
}
