#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>
using namespace std;
const long long  max_n = 5000;
long long cnt[111];
long long b = 1;
long long n,a,W;
const int INF = 1e9;
const int mod = 1e9 + 7;
long long s[max_n],v[max_n],w[1000];
long long dp[max_n];
vector<vector<int> > G;

long long solve(){
    if(n>=10)   return a;
    else    return a+100*(10-n);
}
int main(){
    cin >> n >> a;

    cout << solve() << endl;
    return 0;
}
