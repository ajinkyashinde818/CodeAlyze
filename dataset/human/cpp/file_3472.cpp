#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;

int main(){
    int N;
    cin>>N;
    vector<ll> A(N);
    ll ans=0;
    for(int i=0; i<N; i++){cin>>A[i];ans+=A[i];}
    sort(A.begin(),A.end());
    vector<ll> C(N/2);
    for(int i=0; i<N/2; i++)C[i]=A[2*i]+A[2*i+1];
    for(int i=0; i<N/2; i++){
        if(C[i]<0) ans-=2*C[i];
        else break;
    }
    cout<<ans;
    return 0;
}
