#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-5;
using ll = long long;

struct point{
  int x;
  int y;
  int r;
  int equal(point p);
};

int point::equal(point p){
  if(abs(this->x - p.x) < EPS && abs(this->y - p.y) < EPS && abs(this->r - p.r < EPS)){
    return 1;
  }else{
    return 0;
  }
}

double cost_calc(point p1, point p2){
  double cost;

  //cout << (double)sqrt((ll)(p1.x - p2.x) * (p1.x - p2.x) + (ll)(p1.y - p2.y) * (p1.y - p2.y)) - (p1.r + p2.r) << " " ;
  cost = max(0.0, (double)sqrt((ll)(p1.x - p2.x) * (p1.x - p2.x) + (ll)(p1.y - p2.y) * (p1.y - p2.y)) - (p1.r + p2.r));
  //cout << sqrt(pow(p1.x - p2.x,2.0) + pow(p1.y - p2.y, 2.0)) - (p1.r + p2.r) << endl;
  //cost = max(0.0, sqrt(pow(p1.x - p2.x,2.0) + pow(p1.y - p2.y, 2.0)) - (p1.r + p2.r));

  return cost;
}

using SN = pair<double, int>;
priority_queue<SN, vector<SN>, greater<SN>> q;

double solve(){
  /*======Initialize=====*/
  SN sn;
  int x, y, r;
  vector<point> points;

  cin >> x >> y;
  point start = {x,y,0};
  cin >> x >> y;
  point goal = {x,y,0};

  int N;

  cin >> N;
  points.push_back(start);
  for(int i = 0; i < N; i++){
    cin >> x >> y >> r;
    point p = {x,y,r};
    points.push_back(p);
  }
  points.push_back(goal);

  double cost[N + 2];
  double dist[N+2][N+2];

  for(int i = 0; i < N + 2; i++){
    for(int j = 0; j < N + 2; j++){
      dist[i][j] = cost_calc(points[i],points[j]);
    }
  }

  for(int i = 0; i < N + 2; i++){
    cost[i] = DBL_MAX;
  }

  /*
  for(auto &elem:points){
    cout << elem.x << endl;
  }
  */

  sn = {0.0, 0};
  q.push(sn);

  /*======Solver======*/

  int count = 0;


  while(!q.empty()){
    SN here = q.top();
    q.pop();
    count++;


    for(int i = 0; i < N + 2; i++){
      //cout << points[i].x << endl;
      //cout << points[here.second].equal(points[i]) << endl;
      //if(points[here.second].equal(points[i])) continue;
      if(here.first + dist[here.second][i] < cost[i]){
        //cout << here.first + cost_calc(points[here.second], points[i]) << endl;
        cost[i] = here.first + dist[here.second][i];
        //cout << "i : " << i << " cost : " << cost[i] << endl;
        //sn = {cost[i], i};
        q.emplace(cost[i], i);
        //cout << sn.first << endl;
      }
    }
  }

  //cout << "count : " << count << endl;


  return cost[N+1];


}

int main(){
  double ans;
  ans = solve();

  printf("%.10f\n",ans);

  return 0;
}
