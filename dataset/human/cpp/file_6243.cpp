#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
  ll N, C;
  cin >> N >> C;
  vector<pair<ll, ll>> xv(N);
  for (ll i=0; i<N; i++){
    cin >> xv[i].first >> xv[i].second;
  }
  vector<ll> right(N,0), left(N,0), rev_right(N,0), rev_left(N);
  for (int i=0; i<N; i++){
    if (i>0) {
      right[i] += right[i-1];
      rev_right[i] += rev_right[i-1];
      right[i] += xv[i].second - (xv[i].first - xv[i-1].first);
      rev_right[i] += xv[i].second - (xv[i].first - xv[i-1].first)*2;
    } else {
      right[i] += xv[i].second - xv[i].first;
      rev_right[i] += xv[i].second - xv[i].first*2;
    }
  }
  for (int i=N-1; i>-1; i--){
    if (i<N-1){
      left[i] += left[i+1];
      left[i] += xv[i].second - (xv[i+1].first - xv[i].first);
      rev_left[i] += rev_left[i+1];
      rev_left[i] += xv[i].second - (xv[i+1].first - xv[i].first)*2;
    } else {
      left[i] += xv[i].second - (C-xv[i].first);
      rev_left[i] += xv[i].second - (C-xv[i].first)*2;
    }
  }
  vector<ll> best_right(N), best_left(N), rev_best_right(N), rev_best_left(N);
  best_right[0] = right[0];
  best_left[N-1] = left[N-1];
  rev_best_right[0] = rev_right[0];
  rev_best_left[N-1] = rev_left[N-1];
  for (int i=1; i<N; i++){
    best_right[i] = max(right[i], best_right[i-1]);
    rev_best_right[i] = max(rev_right[i], rev_best_right[i-1]);
  }
  for (int i=N-2; i>-1; i--){
    best_left[i] = max(left[i], best_left[i+1]);
    rev_best_left[i] = max(rev_left[i], rev_best_left[i+1]);
  }
  ll ans = 0;
  ans = max(ans, best_right[N-1]);
  ans = max(ans, best_left[0]);
  for (int i=0; i<N-1; i++){
    // cout << rev_best_right[i]+best_left[i+1] << endl;
    ans = max(ans, rev_best_right[i]+best_left[i+1]);
  }
  for (int i=N-1; i>0; i--){
    // cout << rev_best_left[i]+best_right[i-1] << endl;
    ans = max(ans, rev_best_left[i]+best_right[i-1]);
  }
  cout << ans << endl;
}
