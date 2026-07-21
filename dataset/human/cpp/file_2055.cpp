#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF=1LL<<60;
const int inf=1<<30;
const int mod=1e9+7;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;cin >> n;
    vector<ll> b(n);
    ll sum=0,cnt=0;
    for(int i=0;i<n;i++){
        ll a;cin >> a;
        sum+=abs(a);
        b[i]=abs(a);
        if(a<0){
            cnt++;
        }
    }
    sort(b.begin(),b.end());
    if(cnt%2==0){
        cout << sum << endl;
    }
    else{
        cout << sum-b[0]*2 << endl;
    }
}
