#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  ll N, C; cin >> N >> C;
  ll x[N+2], v[N+2];
  ll score[N+2], revscore[N+2];
  ll max_score[N+2], max_revscore[N+2];
  max_score[0] = 0, max_revscore[N+1] = 0;
  for(int i=1;i<=N;i++){
    cin >> x[i] >> v[i];
  }
  score[0] = 0;
  x[0] = 0;
  for(int i=1;i<=N;i++){
    score[i] = score[i-1] + v[i] - (x[i] - x[i-1]);
    max_score[i] = max(score[i], max_score[i-1]);
  }
  /*
  for(int i=1;i<=N;i++){
    cout << i << " " << max_score[i] << endl;
  }
  */
  revscore[N+1] = 0;
  x[N+1] = C;
  for(int i=N;i>=1;i--){
    revscore[i] = revscore[i+1] + v[i] - (x[i+1] - x[i]);
    max_revscore[i] = max(revscore[i], max_revscore[i+1]);
  }
  /*
  cout << "max_revscore is" << endl;
  for(int i=1;i<=N;i++){
    cout << i << " " << max_revscore[i] << endl;
  }
  */
  ll ans = 0;
  // i=0, i=N
  for(int i=0;i<=N;i++){
    ll tmp = max(max_score[i], max_score[i] + max_revscore[i+1] - x[i]);
    ans = max(ans, tmp);
  }
  for(int i=N;i>=1;i--){
    ll tmp = max(max_revscore[i], max_revscore[i] + max_score[i-1] - (C - x[i]));
    ans = max(ans, tmp);
  }
  cout << ans << endl;
}
