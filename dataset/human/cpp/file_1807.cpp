#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> VI;
typedef vector<VI> VVI;
const double PI = 3.14159265358979323846;
const double EPS = 1e-12;
const int INF = numeric_limits<int>::max() / 2;
const int NEG_INF = numeric_limits<int>::min() / 2;
const int MOD=1e9+7;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll n,m;cin>>n>>m;
  std::vector<ll> ans;
  std::vector<bool> used(n+1);
  for(int i=1;i<=n;i++)used[i]=false;
  for(int i=0;i<m;i++){
      int e;cin>>e;
      ans.push_back(e);
  }
  for(int i=(int)ans.size()-1;i>=0;i--){
      if(!used[ans[i]]){
          cout<<ans[i]<<endl;
          used[ans[i]]=true;
      }
  }
  for(int i=1;i<=n;i++){
      if(!used[i]) cout<<i<<endl;
  }
  return 0;
}
