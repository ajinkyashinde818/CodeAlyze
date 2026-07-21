#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<long double, int>;

long double f(int x1, int x2, int y1, int y2){
  long double ans;
  ans = sqrt(abs((ll)x1-x2)*abs((ll)x1-x2) + abs((ll)y1-y2) *abs((ll)y1-y2));
  return ans;
}

int main(){
  int xs, ys, xg, yg, n;
  cin >> xs >> ys >> xg >> yg >> n;
  vector<int> xn2(n+2), yn2(n+2), rn2(n+2);
  xn2[0] = xs; yn2[0] = ys; rn2[0] = 0;
  xn2[n+1] = xg; yn2[n+1] = yg; rn2[0] = 0;
  for(int i=1; i<n+1; ++i) cin >> xn2[i] >> yn2[i] >> rn2[i];
  long double ans;
  priority_queue<P, vector<P>, greater<P>> que;
  vector<bool> ok(n+2,true);
  que.push(P(0,0));
  while(1){
    long double dis = que.top().first;
    int pos = que.top().second;
    que.pop();
    if(!ok[pos]) continue;
    ok[pos] = false;
    if(pos == n+1){
      ans = dis;
      break;
    }
    for(int i=1; i<n+2; ++i){
      if(!ok[i]) continue;
      long double ndis = f(xn2[i],xn2[pos],yn2[i],yn2[pos]);
      ndis = max((long double)0, ndis -rn2[i] -rn2[pos]);
      //cout << "now:" << pos << " i:" << i << " dis:" << ndis << endl;
      que.push(P(ndis +dis,i));
    }
  }
  printf("%.10llf\n",ans);
}
