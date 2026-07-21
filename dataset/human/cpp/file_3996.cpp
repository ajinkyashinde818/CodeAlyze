#include <iostream>
  #include <complex>
  #include <vector>
  #include <string>
  #include <algorithm>
  #include <cstdio>
  #include <numeric>
  #include <cstring>
  #include <ctime>
  #include <cstdlib>
  #include <set>
  #include <map>
  #include <unordered_map>
  #include <unordered_set>
  #include <list>
  #include <cmath>
  #include <bitset>
  #include <cassert>
  #include <queue>
  #include <stack>
  #include <deque>
 #include <iomanip>
#include <fstream>
#include <climits>
 
  using namespace std;
   
 
//abcdefghijklmnopqrstuvwxyz
//ABCDEFGHIJKLMNOPQRSTUVWXYZ

  typedef long long ll;
  typedef long double lld;
  typedef unsigned long long ull;
  lld INF = 1e18;
  ll mod = 1e9+7;
  // lld PI = 3.141592653;

lld distance(lld x1, lld y1, lld x2, lld y2){
  return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
}
lld btw(lld x1, lld y1, lld x2, lld y2, lld r1, lld r2){

  return max(distance(x1,y1,x2,y2) - r1 - r2, (lld)0);
}

  int main()
  {
      ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
     // fstream cin("text.txt");

      int n;
      lld x0,y0,x1,y1;
      cin>>x0>>y0>>x1>>y1;
      cin>>n;
      vector<vector<lld>> vertices(n+1);
      vertices[0] = {x0, y0, 0};
      for (int i = 1;i<=n;i++){
        lld a,b,c;
        cin>>a>>b>>c;
        vertices[i] = {a,b,c};
      }

      vertices.push_back({x1,y1,0});
      n++;
      vector<vector<lld>> adj(n+1, vector<lld>(n+1));
      for (int i = 0; i<=n;i++){
        for (int j = 0; j<=n;j++){
          adj[i][j] = btw(vertices[i][0], vertices[i][1], vertices[j][0], vertices[j][1], vertices[i][2], vertices[j][2]);
        }
      }

      vector<lld> d(n+1, INF);
      vector<bool> visited(n+1);
      d[0] = 0;
      for (int i = 0; i<=n;i++){
        int v = 0;
        for (int j = 1;j <=n;j++) if (!visited[j] && (visited[v] || d[j]<d[v])) v = j;
        visited[v] = true;
      // cout<<v<<endl;
        for (int j = 0; j<=n;j++){
          d[j] = min(d[j], d[v] + adj[v][j]);
          // cout<<j<<" "<<d[j]<< " "<<adj[v][j]<<endl;
        }
        // cout<<endl;
      }
      cout<<setprecision(30)<<d[n]<<"\n";

}
