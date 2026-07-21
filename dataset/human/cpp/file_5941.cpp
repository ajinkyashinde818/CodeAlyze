#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<double,int>;
const ll inf = numeric_limits<ll>::max()/3;

int main(void){
  int n;
  ll c;
  ll arr1[200010],arr2[200010];
  ll *sushi = arr1 + 100005, *dist = arr2 + 100005;
  ll calcl[100005], calcr[100005];
  ll bestl[100005], bestr[100005];
  cin >> n >> c;
  dist[0] = 0;sushi[0] = 0;
  for(int i = 1;i <= n;++i){
    ll x,v;
    cin >> dist[i] >> sushi[i];
    dist[-n-1+i] = c - dist[i];
    sushi[-n-1+i] = sushi[i];
  }
  ll res = 0;
  calcl[0] = 0;
  bestl[0] = 0;
  for(int i = 1;i <= n;++i){
    calcl[i] = calcl[i-1] + sushi[i];
    res = max(res,calcl[i] - dist[i]);
    bestl[i] = max(bestl[i-1],calcl[i] - dist[i]);
  }
  calcr[0] = 0;
  bestr[0] = 0;
  for(int i = 1;i <= n;++i){
    calcr[i] = calcr[i-1] + sushi[-i];
    res = max(res,calcr[i] - dist[-i]);
    bestr[i] = max(bestr[i-1],calcr[i] - dist[-i]);
  }
  for(int i = 1;i <= n;++i){
    res = max(res,calcl[i]  - 2*dist[i] + bestr[n-i]);
  }
  for(int i = 1;i <= n;++i){
    res = max(res,calcr[i]  - 2*dist[-i] + bestl[n-i]);
  }
  cout << res << endl;
  return 0;
}
