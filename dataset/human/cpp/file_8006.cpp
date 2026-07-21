#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstdlib>
#include<cassert>

#include<cmath>
#include<functional>
#include<algorithm>

#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<set>
#include<unordered_set>
#include<map>
#include<unordered_map>
#include<bitset>
#include<tuple>

#define TEST {IS_TEST=true;}

using namespace std;
using ll = int_fast64_t;
using v_bool = vector <bool>;
using v_ll = vector <ll>;
using v_std = vector <string>;
using p_ll = pair <ll,ll>;
using vv_ll = vector <vector <ll> >;
using vp_ll = vector < p_ll >;

bool IS_TEST=false;
ll ll_min=1LL<<63;
ll ll_max=~ll_min;
ll MOD = 1000000007;

template<class T> bool show_nl(const T&){ return true;}
bool show_nl(const ll&){ return false;}
template<class T,class S> bool show_nl(const pair<T,S>&){ return false;}

template<class T> void show(const T& x,bool newline=false){
  if (!IS_TEST) return;
  cout << x; if (newline) cout << " <#>" <<  endl;
}
void show(const string& x,bool newline=true){
  if (!IS_TEST) return;
  cout << x; if (newline) cout << endl;
}
template<class T,class S> void show(const pair<T,S>& x,bool newline=false){
  if (!IS_TEST) return;
  cout << "{ " << x.first << " " << x.second << " }";
  if (newline) cout << " <#>" <<  endl;
}
template<class T> void show_common3(const T&x){
  if (!IS_TEST) return;
  auto itr=x.begin();
  if (x.begin()==x.end()) {cout<<"<NULL>"<<endl;return;}
  if (show_nl(*itr)){
    cout << "--------------------------------" << endl;
    auto itr=x.begin();
    while(itr!=x.end()){ show(*itr); itr++;}
    cout << "--------------------------------" << endl;
  }else{
    if (itr==x.end()){ cout<<endl; return;}
    while(true){
      show(*itr);itr++;
      if (itr==x.end()) break; else cout << " ";
    }
    cout << endl;
  }
}
template<class T> void show(const vector<T>& x,bool newline=false){
  if (!IS_TEST) return; show_common3(x);
}
template<class T,class S> void show(const set<T,S>& x,bool newline=false){
  if (!IS_TEST) return; show_common3(x);
}
template<class T,class S> void show(const multiset<T,S>& x,bool newline=false){
  if (!IS_TEST) return; show_common3(x);
}
template<class T> void show(const unordered_set<T>& x,bool newline=false){
  if (!IS_TEST) return; show_common3(x);
}
template<class T,class S,class U> void show(const map<T,S,U>& x,bool newline=false){
  if (!IS_TEST) return; show_common3(x);
}
template<class T,class S,class U> void show(const multimap<T,S,U>& x,bool newline=false){
  if (!IS_TEST) return; show_common3(x);
}
template<class T,class S> void show(const unordered_map<T,S>& x,bool newline=false){
  if (!IS_TEST) return; show_common3(x);
}

void load(ll& x){ cin >> x;}
void load(string& x){ cin >> x;}
void load(v_ll& v,ll b,ll e){
    v.assign(e+1,0);
    for(ll i=b;i<e;i++)cin >> v[i];
}

void disp(const ll& x){ cout << x << endl;}
void disp(const string& x){ cout << x << endl;}
void disp(const v_ll& v,ll b,ll e){
    for(ll i=b;i<e;i++){
        if (i!=b) cout << " ";
        cout << v[i];
    }
    cout << endl;
}

v_ll arange(ll n){
    v_ll v(n+1,0);
    for(ll i=0;i<=n;i++)v[i]=i;
    return v;
}
ll vec_sum(const v_ll& v,ll b,ll e){
    ll ans=0;
    for(ll i=b;i<e;i++)ans+=v[i];
    return ans;
}


template<class T> void refl_max(T& x,const T& y){ if (x>=y) return; x=y; }
template<class T> void refl_min(T& x,const T& y){ if (x<=y) return; x=y; }

template<class T,class S> void refl_max(T& x,const T& y,S& xx,const S& yy){
  if (x>=y) return; x=y; xx=yy;
}
template<class T,class S> void refl_min(T& x,const T& y,S& xx,const S& yy){
  if (x<=y) return; x=y; xx=yy;
}

ll N;
v_ll A;
int main(){
    load(N);
    load(A,1,N+1);
    ll ans=ll_max;ll summ=0;
    for(ll i=1;i<=N;i++)summ+=A[i];
    ll x=0,y=summ;
    for(ll i=1;i<=N-1;i++){
        x+=A[i];y-=A[i];
        refl_min(ans,abs(y-x));
    }
    disp(ans);
}
