#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <climits>
#include <iomanip>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
struct edge{
    double p;//点
    double w;//辺の重み*-1
};
struct circle{
  double x;
  double y;
  double r;
};
vector<vector<edge>> graph(100000);
vector<double> res(100000);
double v,e,r;//vは頂点,eは辺,rは始点
void dijkstra(){
  for(int i = 0;i < v;i++)res[i] = pow(10,18);
    res[r] = 0;
    priority_queue<pair<double,double> > que;//重み、頂点
    que.push(make_pair(0,r));
    while(!que.empty()){
        edge now;
        now.p = que.top().second;
        now.w = que.top().first * -1;
        que.pop();
        if(res[now.p] < now.w)continue;
        for(int i = 0;i < graph[now.p].size();i++){
            if(res[graph[now.p][i].p] > now.w + graph[now.p][i].w){
                res[graph[now.p][i].p] = now.w + graph[now.p][i].w;
                que.push(make_pair(res[graph[now.p][i].p] * -1,graph[now.p][i].p));
            }
        }
      //cout << que.size() << " " << now.p << " " << now.w << endl;
    }
}
int main(){
  vector<circle> pos;
  double sx,sy,tx,ty;
  cin >> sx >> sy >> tx >> ty;
  circle s,t;
  s = {sx,sy,0};
  t = {tx,ty,0};
  pos.push_back(s);
  pos.push_back(t);
  double n = 0;
  cin >> n;
  for(int i = 0;i < n;i++){
    double nowx,nowy,nowr;
    cin >> nowx >> nowy >> nowr;
    circle now = {nowx,nowy,nowr};
    pos.push_back(now);
  }
  for(double i = 0;i < n + 1;i++){
    for(double j = i + 1;j < n + 2;j++){
      double cost = sqrt(pow(pos[i].x - pos[j].x,2) + pow(pos[i].y - pos[j].y,2)) - (pos[i].r + pos[j].r);
      if(cost < 0)cost = 0;
      edge memoi = {j,cost};
      edge memoj = {i,cost};
      graph[i].push_back(memoi);
      graph[j].push_back(memoj);
    }
  }
  r = 0;
  v = n + 2;
  e = (n + 2) * (n + 1) / 2;
  for(int i = 0;i < 4;i++){
    for(int j = 0;j < graph[i].size();j++){
      //cout << i << " " << graph[i][j].p << " " << graph[i][j].w << endl;
    }
  }
  dijkstra();
  cout << fixed << setprecision(20) << (double)res[1] << endl;
}
