#include <bits/stdc++.h>
using namespace std;

int main(){
  int N, M;
  cin >> N >> M;
  vector<vector<char>> A(N, vector<char>(N));
  vector<vector<char>> B(M, vector<char>(M));

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> A.at(i).at(j);
    }
  }
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < M; j++) {
      cin >> B.at(i).at(j);
    }
  }


  for (int l = 0; l <= N-M; l++) {
    for (int k = 0; k <= N-M; k++) {
      bool flag=true;
      for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
          if (A.at(i+l).at(j+k)!=B.at(i).at(j)){
            flag=false;
          }
        }
      }
      if(flag){
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
}
