#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF=1LL<<60;
const int inf=1<<30;
const int mod=1e9+7;
const int MOD=998244353;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;cin >> n;
    string s;cin >> s;
    vector<bool> b(2*n);
    int cnt=0;
    for(int i=1;i<2*n;i++){
        if(s[i-1]!=s[i]){
            b[i]=b[i-1];
        }
        else{
            b[i]=!b[i-1];
        }
        cnt+=b[i];
    }
    if(cnt!=n||s[0]=='W'||s[2*n-1]=='W'){
        cout << 0 << endl;
        return 0;
    }
    ll ans=1;
    ll l=0;
    for(int i=0;i<2*n;i++){
        if(b[i]){
            (ans*=l)%=mod;
            l--;
        }
        else{
            l++;
        }
    }
    for(ll i=1;i<=n;i++){
        (ans*=i)%=mod;
    }
    cout << ans << endl;
}
