#include <stdio.h>



int main(void){
  
  int N, M;
  
  scanf("%d %d", &N, &M);
  
  char A[N][N+1];
  char B[M][M+1];
  
  
  
  int i;
  int j;
  int x, y;
  int cnt;
  int ans = 0;
  
  for( i = 0; i < N; i++ ){
    scanf("%s", A[i] );
  }
  for( i = 0; i < M; i++ ){
    scanf("%s", B[i] );
  }
  
  
  for( x = 0; x < N - M + 1; x++ ){
    for( y = 0;  y < N - M + 1; y++ ){
      cnt = 0;
      for( i = 0; i < M; i++ ){
        for( j = 0; j < M; j++ ){
          if(A[x+i][y+j] == B[i][j])cnt++;
          else{break;}
        }
      }
      if( cnt == M*M ) ans = 1;
      if( ans ) break;
    }
    if( ans )break;
  }
  
  if( ans ) puts("Yes");
  else{     puts("No");}
  
  
  return 0;
}
