#include <iostream>
#include <string>
using namespace std;

bool judge(int j, char *a, char *b, int M){
  bool ans=false;
  int l=0;
  for(int k=j; k<M+j; k++){
    if(a[k]!=b[l]){
      ans=false;
      break;
    }
    l++;
    ans=true;
  }
  return ans;
}

int main(){

  int M, N;
  cin >> N >> M;

  char A[N][N], B[M][M];
  bool ans=false;

  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      cin >> A[i][j];
    }
  }
  for(int i=0; i<M; i++){
    for(int j=0; j<M; j++){
      cin >> B[i][j];
    }
  }

  for(int i=0; i<N-M+1; i++){
    for(int j=0; j<N-M+1; j++){
      if(A[i][j]==B[i][0]){
        for(int k=i; k<M+i; k++){
            ans = judge(j, A[k], B[k], M);
            if(!ans) break;
        }
        if(ans){
          cout << "Yes" << endl;
          return 0;
        }
      }
    }
  }

  cout << "No" << endl;

  return 0;
}
