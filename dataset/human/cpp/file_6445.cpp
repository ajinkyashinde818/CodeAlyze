#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<cstdio>
#include<cmath>
#include<numeric>
#include<queue>
#include<stack>
#include<cstring>
#include<limits>
#include<functional>
#define rep(i,a) for(int i=(int)0;i<(int)a;++i)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
using ll=long long;
static const ll mod = 1e9 + 7;
static const ll INF = 1LL << 50;
using namespace std;

int main(){
    int n;
    string s;
    ll ans=1;
    int cnt=0;
    cin>>n>>s;
    vector<ll>num(n+1,1);
    for(int i=1;i<=n;++i){
        num[i]=num[i-1]*i;
        num[i]%=mod;
    }
    vector<int>r(2*n+5,0);
    for(int i=2*n;i>=1;--i){
        //if(i<2*n)if(s[i-1]!=s[i])++cnt;
        if(i%2==1){
            if(s[i-1]=='W')r[i]=r[i+1]+1;
            else {
                ans*=r[i+1];
                ans%=mod;
                r[i]=r[i+1]-1;
                ++cnt;
            }
        }
        else {
            if(s[i-1]=='B')r[i]=r[i+1]+1;
            else {
                ans*=r[i+1];
                ans%=mod;
                r[i]=r[i+1]-1;
                ++cnt;
            }
        }
    }
    if(cnt!=n)cout<<0<<endl;//左として選ぶものの数と右として選ぶものの数が合わない
    else cout<<(ans*num[n])%mod<<endl;
    return 0;
}
