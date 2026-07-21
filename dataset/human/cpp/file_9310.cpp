#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int N,M;
  cin >> N >> M;
  vector<vector<char>> A(N,vector<char>(N));
  vector<vector<char>> B(M,vector<char>(M));
  for(int i=0;i<N;i++){
    for(int h=0;h<N;h++){
      cin >> A.at(i).at(h);
    }
  }
  for(int i=0;i<M;i++){
    for(int h=0;h<M;h++){
      cin >> B.at(i).at(h);
    }
  }
  
  int check = 0;
  int ok = 0;
  
  for(int y=0;y<(N-M+1);y++){
    for(int x=0;x<(N-M+1);x++){
      if(ok != 1){
      check = 0;
      for(int w=0;w<M;w++){
        for(int z=0;z<M;z++){
          if(A.at(y+w).at(x+z) == B.at(w).at(z)){
            check++;
          }
        }
      }
      
      if(check == M*M){
        ok += 1;
      }
      }
    }
  }
  
      if(ok == 1){
        cout << "Yes";
      }else{
        cout << "No";
      }
}
