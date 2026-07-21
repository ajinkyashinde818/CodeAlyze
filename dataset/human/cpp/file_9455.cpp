#include<bits/stdc++.h>
using namespace std;

int main(){
  int N,M;
  cin >> N >> M;
  vector<vector<char>> A(N,vector<char>(N));
  vector<vector<char>> B(M,vector<char>(M));
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      cin >> A.at(i).at(j);
    }
  }
  for(int i=0;i<M;i++){
    for(int j=0;j<M;j++){
      cin >> B.at(i).at(j);
    }
  }
  for(int i=0;i<N-M+1;i++){
    for(int j=0;j<N-M+1;j++){
      bool a=true;
      for(int k=i;k<M+i;k++){
        for(int l=j;l<M+j;l++){
          if(A.at(k).at(l)!=B.at(k-i).at(l-j)){
            a=false;
          }
        }
      }
      if(a){
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
  return 0;
}
