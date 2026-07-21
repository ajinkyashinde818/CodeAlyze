#include <bits/stdc++.h>
using namespace std;


void solve(long long N, long long R){
    long long ans = 0;
    if(N >= 10) ans = R;
    else ans = R + 100 * (10-N);
    cout << ans << endl;
    return;
}

int main(){
    long long N;
    scanf("%lld",&N);
    long long R;
    scanf("%lld",&R);
    solve(N, R);
    return 0;
}
