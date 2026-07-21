#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int64_t N, M;
  cin >> N >> M;

  vector<string> A(N);
  vector<string> B(M);

  for (int64_t i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  for (int64_t i = 0; i < M; i++) {
    cin >> B.at(i);
  }
  cout << endl; 

  for (int64_t i = 0; i < N - M + 1; i++) {
    vector<size_t> positions;

    size_t pos = A.at(i).find(B.at(0), 0);
    while (pos != string::npos) {
      positions.push_back(pos);
      pos = A.at(i).find(B.at(0), pos + 1);
    }

    for (size_t p : positions) {
      bool flag = true;
      for (int64_t j = 1; j < M; j++) {
        auto A_sub = A.at(i + j).substr(p, M);
        if (A_sub.compare(B.at(j)) != 0) {
          flag = false;
          break;
        }
      }
      if (flag) {
        cout << "Yes"; 
        return 0; 
      }
    }
  }

  cout << "No"; 

  return 0;
}
