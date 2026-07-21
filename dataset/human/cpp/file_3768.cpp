#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
const int MAX_N = 1030;    // Change as necessary

ld x[MAX_N],y[MAX_N],r[MAX_N];

ld dist[MAX_N][MAX_N];
ld D[MAX_N];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  for(int i=0;i<2;i++)
    cin >> x[i] >> y[i];
  
  int n; cin >> n;
  for(int i=0;i<n;i++)
    cin >> x[i+2] >> y[i+2] >> r[i+2];
  
  n += 2;
  
  for(int i=0;i<n;i++)
    for(int j=i;j<n;j++)
      dist[i][j] = dist[j][i] = max((ld)0.0,hypot(x[i]-x[j],y[i]-y[j]) - (r[i]+r[j]));
  
  priority_queue<pair<ld,int> > pq;
  pq.emplace(0,0);
  D[0] = 0;
  for(int i=1;i<n;i++) D[i] = -1;
  
  while(!pq.empty()){
    ld d; int idx;
    tie(d,idx) = pq.top(); pq.pop();
    d *= -1;
    if(D[idx] < d-(1e-9)) continue;
    for(int i=0;i<n;i++)
      if(i != idx && (D[i] < -0.5 || D[i] > d + dist[idx][i])){
	D[i] = d+dist[idx][i];
	pq.emplace(-D[i],i);
      }
  }
  
  cout << fixed << setprecision(10) << D[1] << endl;
  
  return 0;
}
