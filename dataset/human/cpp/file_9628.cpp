#include <iostream>
#include <vector>
using namespace std;
int main(void){
  int N,M;
  cin >> N >> M;

  vector<vector<char> >A(N,vector<char>(N));
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      cin >> A[i][j];
    }
  }

  vector<vector<char> >B(M,vector<char>(M));
  for(int i=0;i<M;i++){
    for(int j=0;j<M;j++){
      cin >> B[i][j];
    }
  }

  bool match;

  for(int i=0;i<=N-M;i++){
    for(int j=0;j<=N-M;j++){
      match = true;
      for(int k=0;k<M;k++){
        for(int l=0;l<M;l++){
          if(B[k][l] != A[i + k][j + l])
            match = false;
        }
      }
      if(match)
        break;
    }
    if(match)
      break;
  }

  if(match)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;

  return 0;
}
