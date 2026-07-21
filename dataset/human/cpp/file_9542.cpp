#include<iostream>
#include<cmath>
#include<vector>
#include<set>
#include<algorithm>
#include<tuple>
#include<utility>
#include<cctype>
#include<climits>
#include<map>
#include<queue>
#include<functional>

using namespace std;
template<class T> void chmax(T& a, T b) {if(a < b){a=b;}}
template<class T> void chmin(T& a, T b) {if(a > b){a=b;}}

#define REP(i,a,n) for(int i=a;i<n;++i)
#define RUP(a,b) ((a+b-1)/(b))
#define ENT "\n"
#define REV(v) reverse(v.begin(),v.end())
#define SRTV(v) sort(v.begin(),v.end())
#define SRTAG(a,n) sort(a,a+n,greater<>())
#define MOD 1000000007

typedef long long ll;
typedef tuple<int,int,bool> Tb;

int atcoder(){
    //入力
    int n,m;
    cin >> n >> m;
    string a[n],b[m];
    REP(i,0,n) cin >> a[i];
    REP(i,0,m) cin >> b[i];
    bool ans = false;
    
    //処理
    REP(l,0,n-m+1){
    REP(i,0,n-m+1){
        bool tmp = true;
        REP(j,0,m){
            REP(k,0,m){
                if(a[l+j][i+k]!=b[j][k]) tmp=false;
            }
        }
        if(tmp){
            ans=true;
            break;
        }
    }}

    //出力
    if(ans) cout << "Yes" << ENT;
    else cout << "No" << ENT;
    return 0;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    atcoder();
    return 0;
}
