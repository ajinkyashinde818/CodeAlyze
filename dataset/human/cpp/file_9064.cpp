#include <bits/stdc++.h>
using namespace std;
int main() {
  int N , M;
  cin >> N >> M;
  vector<vector<char>> data(N, vector<char>(N));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> data.at(i).at(j);
    }
  }
  vector<vector<char>> tada(M, vector<char>(M));
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < M; j++) {
      cin >> tada.at(i).at(j);
    }
  }
  bool dandy = false;
  for(int i = 0; i < N - M + 1; i++){
    for(int j = 0; j < N - M + 1; j++){
      bool lady = true;
      for(int k = 0; k < M; k++){
        for(int l = 0; l < M; l++){
          if(data.at(i + k).at(j + l) != tada.at(k).at(l)){
            lady = false;
          }
        }
      }
      if (lady) {
        dandy = true;
      }
    }
  }
  if(dandy){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
}
