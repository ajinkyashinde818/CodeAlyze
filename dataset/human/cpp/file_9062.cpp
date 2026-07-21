#include <algorithm>
#include <iostream>
#include <math.h>
#include <string>
using namespace std;
int main() {
  int a,b; cin >> a >> b;
  char A[a][a],B[b][b];
  for(int i=0;i<a;i++){
    for(int j=0;j<a;j++){
      cin >> A[i][j];
    }
  }
  for(int i=0;i<b;i++){
    for(int j=0;j<b;j++){
      cin >> B[i][j];
    }
  }
  string ans="No";
  for(int i=0;i<(a-b+1);i++){
    for(int j=0;j<(a-b+1);j++){
      if(A[i][j]==B[0][0]){
        bool judge=true;
        for(int k=0;k<b;k++){
          for(int l=0;l<b;l++){
            if(A[i+k][j+l]!=B[k][l]) judge=false;
          }
        }
        if(judge) {ans="Yes"; break;}
      }
    }
  }
  cout << ans << endl;
  return 0;
}
