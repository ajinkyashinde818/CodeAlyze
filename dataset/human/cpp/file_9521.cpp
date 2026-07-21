#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,m;
  cin >> n >> m;
  
  const int nmmax = 50;
  
  char A[nmmax][nmmax],B[nmmax][nmmax];
  
  for(int y=0;y<n;y++){
    for(int x=0;x<n;x++){
      cin >> A[y][x];
    }
  }
  
  for(int y=0;y<m;++y){
    for(int x=0;x<m;++x){
      cin >> B[y][x];
    }
  }
  
  bool exist = false;
  
  for(int ly=0;ly<n;ly++){
    for(int lx=0;lx<n;++lx){
      if(ly+m-1>=n || lx+m-1>=n) continue;
      
      bool match = true;
      for(int y=0;y<m;y++){
        for(int x=0;x<m;++x){
          if(A[ly+y][lx+x]!=B[y][x]) {
            match = false;
            break;
          }
        }
      if(match == false)break;
      }
      
      if(match) exist = true;
    }
  }
  
  if(exist)cout << "Yes" << endl;
  else cout << "No" << endl;
  
}
