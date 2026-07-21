#include<bits/stdc++.h>
#include<queue>
using namespace std;
int main () {
  int N;
  cin >> N;
  vector<int>A(N);
  vector<int>B(N);
  vector<int>Bnum(N + 1, 0);
  for (int i = 0; i < N; i ++) {
    cin >> A[i];
  }
  for (int i = 0; i < N; i ++) {
    cin >> B[i];
    Bnum[B[i]] ++;
  }
  int r = 0;
  for (int l = 0; l < N; l ++) {
    while (A[l] == B[r] && r < N - 1) r ++;
    swap(B[l], B[r]);
    if (l == r) r ++;
  }
  int l = N - 1;
  for (int r = N - 1; r >= 0; r --) {
    while (A[r] == B[l] && l > 0) l --;
    swap(B[r], B[l]);
    if (l == r) l --;
  }
  for (int i = 0; i < N; i ++) {
    if (A[i] == B[i]) {
      cout << "No" << endl;
      return 0;
    }
  }
  /*priority_queue<pair<int, int>>que;
  for (int i = 1; i <= N; i ++) {
    que.push(make_pair(Bnum[i], i));
  }
  for (int i = 0; i < N; i ++) {
    int pre, kj_;
    tie(pre, kj_) = que.top();
    que.pop();
    if (kj_ == A[i]) {
      int now, kj;
      tie(now, kj) = que.top();
      que.pop();
      if (now == 0) {
        cout << "No" << endl;
        return 0;
      }
      que.push(make_pair(pre, kj_));
      pre = now;
      kj_ = kj;
    }
    B[i] = kj_;
    Bnum[kj_] --;
    que.push(make_pair(pre - 1, kj_));
    cout << kj_ << endl;
  }*/
  cout << "Yes" << endl;
  for (int i = 0; i < N; i ++) {
    cout << B[i];
    if (i < N - 1) cout << ' ';
  }
  cout << endl;
}
