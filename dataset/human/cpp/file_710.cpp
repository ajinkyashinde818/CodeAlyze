#include<bits/stdc++.h>
#include<iomanip>

using namespace std;
using ll = long long;
constexpr int mod = 1e9+7;
constexpr int md = mod;
constexpr int inf = 1000000;
constexpr int def = inf;
int N;
int R,G,B;
int main(){
    vector<int> v(3);
    cin>>v[0]>>v[1]>>v[2]>>N;
    vector<int> dp(3005);
    dp[0] = 1;
    for(int i=0;i<3;++i){
        for(int j=0;j<=N;++j){
            if(j + v[i] <= N) dp[j+v[i]] += dp[j];
        }
    }
    cout << dp[N] << endl;
    return 0;
}
