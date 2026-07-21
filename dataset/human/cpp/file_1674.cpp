//#include "bits/stdc++.h"
#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <stack>
#include <queue>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <complex>
#include <bitset>
#include <functional>
#include <stack>
#include <regex>
#include <tuple>
#include <iomanip>

#define int long long
#define REP(i,l,r) REPEAT(i,l,r,true) // [l, r)
#define rep(i,n) REP(i,0,n)           // [0, n)
#define REPEAT(i,l,r,condition) for(int i=(condition)?l:r-1;(condition)?i<r:i>=l;(condition)?++i:--i) // false<-[l, r)->true
#define all(e) e.begin(),e.end()
#define rall(e) e.rbegin(),e.rend()
#define pb push_back
#define fs first
#define sc second
#define show(...) cerr<<#__VA_ARGS__<<" = ";_DEBUG(__VA_ARGS__)
#define showlr(n,l,r) cerr<<#n<<" = ";for(int i=l;i<r;i++){cerr<<n[i]<<", ";}cerr<<endl // [l, r)

#define yes puts("Yes")
#define no puts("No")
#define case(i) printf("Case #%lld: ",i)

using namespace std;

using vi=vector<int>;
using pint=pair<int,int>;

inline void io(){cin.tie(0);ios::sync_with_stdio(false);cout.tie(0);cout<<fixed<<setprecision(20);}

template<class T> istream& operator >>(istream &is, vector<T> &v){for(T &e:v)is>>e;return is;}
template<class T> ostream& operator <<(ostream &os, vector<T> v){/*os<<"{"*/;for(T &e:v)os<<e<<(v.size()-(int)(&e-&v[0])>1?" ":"");/*os<<"}"*/;return os;}

void _DEBUG(){}
template<typename H,typename... T> void _DEBUG(H a,T...b){cerr<<a<<(sizeof...(b)?",":"\n");_DEBUG(b...);}

inline void in(){}
template<typename H,typename... T>void in(H &a, T&... b){cin>>a;in(b...);}
inline void out(){}
template<typename H,typename... T> void out(H a, T... b){cout<<a<<(sizeof...(b)?" ":"\n");out(b...);}

template<class T> void resz(int n,T& v){v.resize(n);}
template<class H,class... T> void resz(int n,H& a,T&... b){a.resize(n);resz(n,b...);}

const int INF=1LL<<55;
const int MOD=1000000007;
const double EPS=1e-8;

int n;
set<int> tri;
vi t(1,0);
vector<vi> vecs;

void create(int index){
    if(t[index]==n) return;
    vi tmp;
    int j=0;
    for(int i=t[index]+1;i<=t[index+1];i++,j++){
        vecs[j].pb(i);
        tmp.pb(i);
    }
    //show(j);
    vecs[j]=tmp;
    return create(index+1);
}

signed main(){
    io();

    REP(i,1,1e5){
        if(i*(i+1)/2>1e5) break;
        tri.insert(i*(i+1)/2);
        t.pb(i*(i+1)/2);
    }
    vecs.resize(tri.size()+10);
    in(n);
    if(tri.find(n)==tri.end()){
        no;
        return 0;
    }
    yes;
    int sz;
    create(0);
    rep(i,tri.size()+10){
        if(vecs[i].size()==0){
            sz=i;
            out(i);
            break;
        }
    }
    rep(i,sz){
        out(vecs[i].size(),vecs[i]);
    }

    return 0;
}
