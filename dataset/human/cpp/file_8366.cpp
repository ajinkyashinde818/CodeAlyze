#include<cstdio>

using namespace std;

int main(){
  int M, N;
  char A[50][50], B[50][50];
  bool f1 = true, f2 = true;;

  scanf("%d %d", &N, &M);

  for(int l = 0; l < N; l++){
    scanf("%s", A[l]);
  }
  for(int l = 0; l < M; l++){
    scanf("%s", B[l]);
  }

  for(int i = 0; i <= (N-M) && f1; i++){
    for(int j = 0; j <= (N-M) && f1; j++){

      for(int k = 0; k < M && f2; k++){
        for(int l = 0; l < M && f2; l++){
          if(A[i+k][j+l] != B[k][l]){
            f2 = false;
          }
          //printf("A(%d,%d)%c B(%d,%d)%c\n", i+k, j+l, A[i+k][j+l], k, l, B[k][l]);
        }
      }
      if(f2){
        f1 = false;
      }
      f2 = true;

    }
  }

  if(!f1){
    printf("Yes");
  }else{
    printf("No");
  }

  return 0;

}
