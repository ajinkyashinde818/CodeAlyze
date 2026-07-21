#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using product = pair<ll,ll>;
using graph = vector<vector<ll>>;
using vll = vector<ll>;

int main(){
    ll N;
    cin>>N;
    vll A(N);
    ll negative;
    ll mi=LLONG_MAX;
    ll res=0;
    for(ll i=0;i<N;i++)
    {
        cin>>A[i];
        if(A[i]<=0) negative++;
    }
    for(ll i=0;i<N;i++)
    {
        mi=min(abs(A[i]),mi);
        res+=abs(A[i]);
    }
    if(negative%2==0)cout<<res;
    else cout<<res-mi*2;
    return 0;
}
