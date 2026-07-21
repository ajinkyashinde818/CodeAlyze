#include <bits/stdc++.h>

using namespace std;


int main()
{
  int N, M;
  string S[50];
  string T[50];

  cin >> N >> M;
  for(int i = 0; i < N; i++) cin >> S[i];
  for(int i = 0; i < M; i++) cin >> T[i];

  for(int i = 0; i <= N - M; i++) {
    for(int j = 0; j <= N - M; j++) {
      bool match = true;
      for(int k = 0; k < M; k++) {
        for(int l = 0; l < M; l++) {
          match &= S[i + k][j + l] == T[k][l];
        }
      }
      if(match) {
        cout << "Yes" << endl;
        return (0);
      }
    }
  }
  cout << "No" << endl;
}
