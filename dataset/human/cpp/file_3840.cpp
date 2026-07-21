#include <bits/stdc++.h>
 
using namespace std;
inline void prep ()
{
  cin.tie (0);
  cin.sync_with_stdio (0);
};
const double pi = acos(-1.);
//printf(%.12lf\n,mid);
// __builtin_popcount(int) count 1's in binary
// get decimal part of number
/*
double intpart;
double thiss = modf((double)(n*m)/(double)k, &intpart);
*/
// round = (int)(num+.5)
long long mod = 1000000007;
 
long long mymod(long long num){
  if (num< 0 && !(num%mod == 0)){
    if (mod == 1){
      return 0;
    }
    return mod-abs(num)%mod;
  }else{
    return num%mod;
  }
}
 
/*string sentence = And I feel fine...;
    istringstream iss(sentence);
*/  
 
double eps = .000000001;

double graph[1002][1002];
double dist(pair<double, double> p1, pair<double, double> p2){
    return sqrt(pow(p1.first-p2.first, 2)+pow(p1.second-p2.second, 2));
}

int main ()
{
  prep();
  double sx, sy, fx, fy;
  cin >> sx >> sy >> fx >> fy;
  int n;
  cin >> n;
  tuple<double, double, double> before[n];
  for (int i=1; i<=n; i++){
      double x, y, r;
      cin >> x >> y >> r;
      for (int j=1; j<i; j++){
          tuple<double, double, double> p = before[j-1];
          double distt = dist({get<0>(p), get<1>(p)}, {x, y});
          graph[i][j] = max(distt-get<2>(p)-r, 0.0);
          graph[j][i] = max(distt-get<2>(p)-r, 0.0);
      }
      before[i-1] = tuple<double, double, double> (x, y, r);
  }
  for (int j=1; j<=n; j++){
      tuple<double, double, double> p = before[j-1];
      double distt = dist({get<0>(p), get<1>(p)}, {sx, sy});
      double distt2 = dist({get<0>(p), get<1>(p)}, {fx, fy});
      graph[0][j] = max(distt-get<2>(p), 0.0);
      graph[j][0] = max(distt-get<2>(p), 0.0);
      graph[n+1][j] = max(distt2-get<2>(p), 0.0);
      graph[j][n+1] = max(distt2-get<2>(p), 0.0);
  }
  graph[0][n+1] = dist({sx, sy}, {fx, fy});
  graph[n+1][0] = dist({sx, sy}, {fx, fy});
  // from 0 to n+1
 
  double curdist[n+2];
  for (int i=0; i<=n+1; i++){
      curdist[i] = graph[i][0];
  }
  bool vis[n+1] = {false};
  for (int i=0; i<=n+1; i++){
      double minnest = 1000000000000000001.0;
      int ind = 0;
      for (int j=0; j<=n; j++){
          if (vis[j]){
              continue;
          }
          if (curdist[j] < minnest){
              minnest = curdist[j];
              ind = j;
          }
      }
      vis[ind] = true;
      for (int j=1; j<=n+1; j++){
          curdist[j] = min(curdist[j], minnest+graph[ind][j]);
      }
  }
  printf("%.9lf", curdist[n+1]);
  return 0; 
}
