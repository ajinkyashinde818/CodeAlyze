#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b;
  cin >>a>>b;
  char A[a][a];
  char B[b][b];
  for(int i=0;i<a;i++) cin >> A[i];
  for(int i=0;i<b;i++) cin >> B[i];
  
  for(int i=0;i<a;i++){
    for(int j=0;j<a;j++){
      bool br=false;
      for(int k=0;k<b;k++){
        for(int l=0;l<b;l++){
          if(A[i+k][j+l] != B[k][l]){
            br = true;
            break;
          }
        }
        if(br) break;
        if(k == b-1){
          cout << "Yes" << endl;
          return 0;
        }
      }
    }
  }
  cout << "No" << endl;
}
