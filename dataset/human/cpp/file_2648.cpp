#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using Map = map<string,ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
ll INF=1LL<<60;
ll MOD=1000000007;


int main(){
    ll N;
    cin >> N;
    vector<ll> A(N,0);
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    ll sum=0;
    ll pc=0;
    ll mc=0;
    for(ll i=0;i<N;i++){
        cin>>A[i];
        if(A[i]>=0)pc++;
        else mc++;
        sum+=llabs(A[i]);
        pq.push(llabs(A[i]));
    ;}
    if(llabs(mc)%2){
        sum-=2*pq.top();
    }
    cout<<sum<<endl;
    

    return 0;
}
