#include <iostream>
#include<algorithm>
#include<vector> //動的配列
#include<string> 
#include <list> //双方向リスト
#include <map> //連想配列
#include <set> //集合
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <bitset>


//小さい順から取り出すヒープ
//priority_queue<ll, vector<ll>, greater<ll> > pque1;

typedef long long ll;


using namespace std;

typedef pair<int, int> P;


ll fast_pow(ll x,ll n,ll mod){
    if (n==0) return 1;
    ll res=fast_pow(x*x %mod,n/2,mod);
    if (n&1) res=res*x%mod;
    return res;
}

template <class T>ostream &operator<<(ostream &o,const vector<T>&v)
{o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}

int a,b,c,n;

int main(){
    int cnt=0;
    cin>>a>>b>>c>>n;
    for(int i=0;i<=(n/a);i++){
        for (int j=0;j<=(n/b);j++){
            //cout<<i<<j<<endl;
            if (a*i+b*j<=n && (n-(a*i+b*j))%c==0) cnt++;
        }
    }
    cout<<cnt<<endl;
}
