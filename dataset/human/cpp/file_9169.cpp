#include <bits/stdc++.h>
using namespace std;
int main () {
  int N, M;
  cin >> N >> M;
  vector<vector<char>> main(N, vector<char> (N)), sub(M, vector<char> (M));
  for(int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> main.at(i).at(j);
    }
  }
  for(int i = 0; i < M; i++) {
    for (int j = 0; j < M; j++) {
      cin >> sub.at(i).at(j);
    }
  }
  int count, flag = 0;
  for(int i = 0; i < N - M + 1; i++) {
    for (int j = 0; j < N - M + 1; j++) {
      count = 0;
      for (int k = 0; k < M; k++) {
        for (int l = 0; l < M; l++) {
          if(main.at(i + k).at(j + l) == sub.at(k).at(l)) count++;
        }
      }
      if(count == M * M) flag = 1;
    }
    if (flag == 1) break;
  }
  if(flag == 1)cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
