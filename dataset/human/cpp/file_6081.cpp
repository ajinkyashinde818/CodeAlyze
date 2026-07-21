#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long lli;
typedef double lld;
typedef vector<lli> vll;
typedef vector<bool> vbl;
typedef vector<double> vdl;
typedef vector<vector<lli>> mat;
typedef vector<vdl> mad;
typedef unordered_map<lli,unordered_map<lli,lli>> graph;
typedef complex<double> cmp;
typedef vector<cmp> vcl;

lli n,c;
vll x,v;

template<class T,class Compare>
class segment_tree {
private:
  lli n;
  T d;
  vector<T>* v;
  T _query(lli a,lli b,lli k,lli l,lli r){
    if(r <= a || b <= l) return d;
    if(a <= l && r <= b) return this->v->at(k);
    else {
      T vl = _query(a,b,k*2+1,l,(l+r)/2);
      T vr = _query(a,b,k*2+2,(l+r)/2,r);
      return func(vl,vr);
    }
  }
public:
  segment_tree (){}
  segment_tree(lli n,T d = INT_MAX){
    this->n = 1;
    while(n > this->n) this->n <<= 1;
    v = new vector<T>(this->n*2,d);
    this->d = d;
  }
  void update(lli i,T x){
    i += n-1;
    this->v->at(i) = x;
    while(i > 0){
      i = (i-1)/2;
      this->v->at(i) = func(this->v->at(i*2+1),this->v->at(i*2+2));
    }
  }
  T query(lli a,lli b){
    return _query(a,b,0,0,n);
  }
  T func(T a,T b){
    if(Compare()(a,b)) return a;
    else return b;
  }
};
lli ans = 0;
lli fans;
lli mem;

int main(){
  cin >> n >> c;
  x = v = vll(n);
  for(lli i = 0;i < n;i++) cin >> x[i] >> v[i];
  vll sg(n);
  lli s = 0;
  for(int i = 0;i < n;i++){
    s += v[i];
    if(s > x[i]) sg[i] = s-x[i];
  }
  for(int i = 1;i < n;i++){
    sg[i] = max(sg[i-1],sg[i]);
  }
  vll gs(n);
  s = 0;
  for(int i = n-1;i >= 0;i--){
    s += v[i];
    if(s > (c-x[i]))gs[i] = s-(c-x[i]);
  }
  for(int i = n-1;i > 0;i--){
    gs[i-1] = max(gs[i],gs[i-1]);
  }
  ans = max(*max_element(sg.begin(),sg.end()),*max_element(gs.begin(),gs.end()));
  for(int i = 0;i < n-1;i++){
    if(sg[i]+gs[i+1] > x[i]) ans = max(ans,sg[i]-x[i]+gs[i+1]);
  }
  for(int i = n-1;i > 0;i--){
    if(gs[i]+sg[i-1] > c-x[i]) ans = max(ans,gs[i]-(c-x[i])+sg[i-1]);
  }
  cout << ans << endl;
  return 0;
}
