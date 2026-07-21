#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const ll LINF = 1e18;

template <class T>ostream &operator<<(ostream &o,const vector<T>&v)
{o<<"[";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"]";return o;}
template <class T, class U>ostream &operator<<(ostream &o, const pair<T, U>&p)
{o<<"{"<<p.first<<", "<<p.second<<"}";return o;}
template <class T, class U>ostream &operator<<(ostream &o, const map<T, U>&obj)
{o<<"{";for(auto itr=obj.begin();itr!=obj.end();++itr)o<<(itr!=obj.begin()?", ":"")<<*itr;o<<"}";return o;}

int main()
{
  int r,g,b,n;
  cin >> r >> g >> b >> n;
  vector<int> cnt(n+1,0);

  for(int i=0;i<=n/r;i++){
    for(int j=0;j<=n/g;j++){
      if(i*r+j*g <= n) cnt[i*r+j*g]++;
    }
  }
  int ans = 0;
  for(int i=0;i<=n/b;i++){
    if(i*b<=n) ans += cnt[n-i*b];
  }
  cout << ans << endl;
  return 0;
}
