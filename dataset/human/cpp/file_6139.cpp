#include <iostream>
#include <vector>
using namespace std;

int main(){
  long long int N, C;
  cin >> N >> C;
  vector< pair<long long int, long long int> > V;
  long long int x, v;
  for(int i = 0; i < N; ++i){
    cin >> x >> v;
    V.emplace_back(x, v);
  }
  long long int ans = 0, t = 0;
  //右回り
  vector<long long int> R(N), L(N);
  for(int i = 0; i < N; ++i){
    t += V[i].second - V[i].first;
    if(i > 0) t += V[i-1].first;
    ans = max(ans, t);
    R[i] = ans;
  }
  t = 0, ans = 0;
  for(int i = N-1; i >= 0; --i){
    t += V[i].second + V[i].first - C;
    if(i < N-1) t += C - V[i+1].first;
    ans = max(ans, t);
    L[i] = ans;
  }
  t = 0;
  for(int i = 0; i < N-1; ++i){
    t += V[i].second;
    ans = max(ans, t - 2*V[i].first + L[i+1]);
  }
  t = 0;
  for(int i = N-1; i > 0; --i){
    t += V[i].second;
    ans = max(ans, t + 2*(V[i].first - C) + R[i-1]);
  }
  ans = max(ans, R[N-1]);
  ans = max(ans, L[0]);
  cout << ans << endl;
  return 0;
}
