#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main()
{
    ll N;
    string S;
    cin >> N >> S;
    ll res = 1;
    ll cand = 0;
    for(ll i=0;i<2*N;i++){
        if(
            (S[i]=='B') && (cand%2==0)
         || (S[i]=='W') && (cand%2==1)
        ){
          cand++;
        }else{
          res *= cand;
          res %= 1000000007;
          cand--;
        }
    }
    if(cand!=0) res = 0;
    for(ll i=1; i<=N; i++){
        res *= i;
        res %= 1000000007;
    }
    cout<<res<<endl;

    return 0;
}
