#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<set>
#include<map>
#include<utility>
#include<tuple>
#include<algorithm>
#include<cmath>
using namespace std;

#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;

int main() {
  int N, M;
  cin >> N >> M;
  vector<string> A(N), B(M);
  rep(i, N) cin >> A[i];
  rep(i, M) cin >> B[i];
  for(int i=0; i<=N-M; i++) {
    for(int j=0; j<=N-M; j++) {
      bool flag=true;
      rep(k, M) {
        rep(l, M) {
          if(B[k][l] != A[i+k][j+l]) {
            flag = false;
            break;
          }
        }
      }
      if(flag) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
  return 0;
}
