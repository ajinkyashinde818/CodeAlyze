#include<bits/stdc++.h>
using namespace std;

using i64 = int64_t;

i64 dp[100005][2]={0};

int main(){
    int n;
    cin >> n;
    vector<i64> v={0};
    for(int i=0;i<n;++i){
        i64 a;
        cin >> a;
        v.push_back(a);
    }
    dp[1][0] = v[1]; dp[1][1] = -v[1];
    for(int i=1;i<n;++i){
        dp[i+1][0] = max(dp[i][0]+v[i+1], dp[i][1]-v[i+1]);
        dp[i+1][1] = max(dp[i][0]-v[i+1], dp[i][1]+v[i+1]);
    }
    cout << dp[n][0] << endl;

    return 0;
}
