#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int N, M; cin >> N >> M;
  vector<vector<char>> NN(N, vector<char>(N));
  vector<vector<char>> MM(M, vector<char>(M));
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      cin >> NN.at(i).at(j);
    }
  }
  for(int i=0;i<M;i++){
    for(int j=0;j<M;j++){
      cin >> MM.at(i).at(j);
    }
  }
  int check=0;
  for(int i=0;i<=N-M;i++){
    for(int j=0;j<=N-M;j++){
      if(NN.at(i).at(j)==MM.at(0).at(0)){
          check=0;
          for(int k=0;k<M;k++){
            for(int l=0;l<M;l++){
              if(MM.at(k).at(l)!=NN.at(i+k).at(j+l)){
                check=1;
                break;
              }
            }
            if(check==1){
              break;
            }
          }
        if(check==0) {
          cout << "Yes" << endl;
          return 0;
        }
      }
    }
  }
  cout << "No" << endl;
}
