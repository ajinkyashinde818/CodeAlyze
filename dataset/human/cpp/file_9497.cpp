#include <bits/stdc++.h>
using namespace std;

  int main(){
    int N,M;
    cin >> N >> M;
    string A;
    string B;
    string S;
    for (int i=0;i<N;i++){
      cin >> S;
      A+=S;
    }
    for (int i=0;i<M;i++){
      cin >> S;
      B+=S;
    }
    for (int x=0;x<=N-M;x++){
      for (int y=0;y<=N-M;y++){
        int f=0;
        for (int z=0;z<M;z++){
          if (A.substr(x+N*(y+z),M)!=B.substr(z*M,M)){
            break;
          }
          f+=1;
          if (f==M){
            cout << "Yes" << endl;
            return 0;
          }
        }
      }
    }
    cout << "No" <<endl;
      return 0;
  }
