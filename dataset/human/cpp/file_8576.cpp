//TemplateMatching.cpp (B)
#include <iostream>
#include <string>
using namespace std;

int main(){
  int M,N;
  cin >> N >> M;
  string A[N],B[M];
  for(int i = 0; i < N; i++) cin >> A[i];
  for(int i = 0; i < M; i++) cin >> B[i];

  bool flag = false;
  int chk;
  for(int i = 0; i < N - M + 1; i++){
    for(int j = 0; j < N - M + 1; j++){
      chk = 0;
      for(int k = 0; k < M; k++){
        if(B[k] == A[i+k].substr(j,M)) ++chk;
      }
      if(chk == M){
        flag = true;
        break;
      }
    }
    if(flag) break;
  }

  if(flag) printf("Yes\n");
  else printf("No\n");
  return 0;
}
