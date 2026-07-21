#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;


int main(){
  long long N, C;
  long long x[100010] = {}, v[100010] = {};
  cin >> N >> C;
  for(int i = 1; i <= N; i++){
    cin >> x[i] >> v[i];
  }
  x[N+1] = C;
  long long forward_sum[100001] = {}, backward_sum[100001] = {};
  long long ans = 0;
  for(int i = 1; i <= N; i++){
    forward_sum[i] = forward_sum[i-1] - (x[i] - x[i-1]) + v[i];
    backward_sum[i] = backward_sum[i-1] - (x[N+1 +1 - i] - x[N+1+1-i-1]) + v[N+1-i];
    ans = max(forward_sum[i], ans);
    ans = max(backward_sum[i], ans);
  }
  // forward[i].first番目までのところまで進んでforward[i].secondだけ得点を得るのがi番目
  pair<long long, long long>forward[100001], backward[100001];

  // 前に進んでから後ろに戻るパターン
  for(int i = 1; i <= N; i++){
    forward[i].first = forward[i-i].first;
    forward[i].second = forward[i-1].second;
    if(forward_sum[i] - x[i] > forward[i].second){
      forward[i].first = i;
      forward[i].second = forward_sum[i] - x[i];
    }

    backward[i].first = backward[i-1].first;
    backward[i].second = backward[i-1].second;
    if(backward_sum[i] > backward[i-1].second){
      backward[i].first = i;
      backward[i].second = backward_sum[i];
    }
  }
  for(int i = 1; i <= N; i++){
    ans = max(ans, forward[i].second + backward[N-i].second);
  }

  // 後ろに進んでから前に戻るパターン
  for(int i = 1; i <= N; i++){
    forward[i].first = forward[i-1].first;
    forward[i].second = forward[i-1].second;
    if(forward_sum[i] > forward[i-1].second){
      forward[i].first = i;
      forward[i].second = forward_sum[i];
    }

    backward[i].first = backward[i-1].first;
    backward[i].second = backward[i-1].second;
    if(backward_sum[i] - (x[N+1] - x[N+1-i]) > backward[i].second){
      backward[i].first = i;
      backward[i].second = backward_sum[i] - (x[N+1] - x[N+1-i]);
    }
  }
  for(int i = 1; i <= N; i++){
    ans = max(ans, forward[i].second + backward[N-i].second);
  }
  

  
  cout << ans << endl;
}
