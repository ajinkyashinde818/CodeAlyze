#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <iomanip>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int inf = 1<<30;
const int mod = 1e9+7;

int main() {
  int N, M; cin >> N >> M;
  vector<string> A(N), B(M);
  for(int i = 0; i < N; i++) cin >> A[i];
  for(int i = 0; i < M; i++) cin >> B[i];

  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      if(i+M-1 >= N or j+M-1 >= N) continue;
      bool match = true;
      for(int k = 0; k < M; k++) {
        for(int l = 0; l < M; l++) {
          if(A[i+k][j+l] != B[k][l]) match = false;
        }
      }
      if(match) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;


  return 0;
}
