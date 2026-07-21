#include <iostream>
#include <algorithm>
#include <vector> //動的配列
#include <string>
#include <list> //双方向リスト
#include <map> //連想配列
#include <set> //集合
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <bitset>
#include <numeric>



typedef long long ll;


using namespace std;

typedef pair<int, int> P;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)



ll fast_pow(ll x,ll n,ll mod){
    if (n==0) return 1;
    ll res=fast_pow(x*x %mod,n/2,mod);
    if (n&1) res=res*x%mod;
    return res;
}

template <class T>ostream &operator<<(ostream &o,const vector<T>&v)
{o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}

// n次元配列の初期化。第２引数の型のサイズごとに初期化していく。
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

//小さい順から取り出すヒープ
//priority_queue<ll, vector<ll>, greater<ll> > pque1;




int main(){
    int N;
    cin>>N;
    int x=1e6;
    char a[x];
    rep(i,2*N){
        cin>>a[i];
        
    }
    if (a[0]=='W' or a[2*N]=='W'){
        cout<<0<<endl;
        return 0;
    }
    bool lor=true;
    int left=1;
    ll ans=1;
    ll mod=1e9+7;
    for (int i=1;i<2*N;i++){
        if (a[i]==a[i-1]){
            lor=!lor;
        }
        if (lor==true){
            left++;
        }else {
            ans*=left;
            ans%=mod;
            left--;
        }
        if (left<0){
            cout<<0<<endl;
            return 0;
        }
    }
    if (left!=0){
        cout<<0<<endl;
        return 0;
    }
    
    for (int i=1;i<=N;i++){
        ans*=i;
        ans%=mod;
    }
    cout<<ans%mod<<endl;
    
    
}
