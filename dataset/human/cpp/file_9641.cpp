#include<bits/stdc++.h>
using namespace std;

int main(){
  int N, M;
  cin >> N >> M;
  
  vector<vector<char>> vecA(N,vector<char>(N));
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      cin >> vecA.at(i).at(j);
    }
  }
  
  vector<vector<char>> vecB(M,vector<char>(M));
  for(int k=0; k<M; k++){
    for(int l=0; l<M; l++){
      cin >> vecB.at(k).at(l);
    }
  }
  
  bool flag = false;
  
  for(int m=0; m<N-M+1; m++){
    for(int n=0; n<N-M+1; n++){
      int count = 0;
      if(vecA.at(m).at(n) == vecB.at(0).at(0)){
        for(int x=0; x<M; x++){
          for(int y=0; y<M; y++){
            if(vecA.at(m+x).at(n+y) == vecB.at(x).at(y)){
              count++;
            }
            if(count == M*M){
              flag = true;
            }
          }
        }
      }
    }
  }
  if(flag){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
}
