#include <bits/stdc++.h>
using namespace std;


void solve(long long N, long long R){
    if(N>=10)cout<<R<<endl;
    else
        cout<<R+100*(10-N)<<endl;
}

int main(){
    long long N;
    scanf("%lld",&N);
    long long R;
    scanf("%lld",&R);
    solve(N, R);
    return 0;
}
