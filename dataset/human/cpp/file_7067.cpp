#include<iostream>
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <iomanip>//setprecision
#include<math.h>
#include <functional>
#include<climits>
using namespace std;
template <typename T> bool chmax(T &u, const T z) { if (u < z) {u = z; return true;} else return false; }
template <typename T> bool chmin(T &u, const T z) { if (u > z) {u = z; return true;} else return false; }
#define ll  long long 
const ll INF=1LL<<60;
const ll MOD=1000000007;
#define rep(i, n)        for(ll i=0; i<(ll)(n); ++i)
ll dp[2001];
int main(){
    ll a,x=1;cin>>a;
    bool g=true;
    vector<ll>b(a),c(a);
    pair<ll,ll>d,e;
    d.first=0;d.second=0;
    e.second=0;e.first=0;
    rep(i,a){
        cin>>b[i];
        if(i!=0)if(b[i]==b[i-1])x++;
        else {
            if(d.first<x){
                d.first=x;
                d.second=b[i-1];
            }x=1;
        }
    }
    x=1;
    rep(i,a){
        cin>>c[i];
                if(i!=0)if(c[i]==c[i-1])x++;
        else {
            if(e.first<x){
            e.first=x;
            e.second=c[i-1];
            }
            x=1;
        }
    }
    /*if(d.first>a/2&&e.first>a/2&&d.second==e.second){
        cout<<"No";
        return 0;
    }*/
    reverse(c.begin(),c.end());
    rep(i,a){
        if(b[i]==c[i]){
            g=true;
            rep(j,a){
                if(b[i]!=c[j]&&b[j]!=c[i]){
                    swap(c[i],c[j]);
                    g=false;
                    break;
                }
            }
            if(g){cout<<"No";
            return 0;
            }
        }
    }
    cout<<"Yes"<<endl;
    rep(i,a)cout<<c[i]<<" ";
}
