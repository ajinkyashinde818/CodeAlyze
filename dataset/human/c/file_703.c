/*
  B - Template Matching
  <http://abc054.contest.atcoder.jp/tasks/abc054_b>
*/

#include <stdio.h>

int main(int argc, char const *argv[]) {

  int N,M;
  int i,j,k,l;
  char A[50][51],B[50][51];
  int judge;

  scanf("%d %d", &N, &M);
  for( i=0; i<N; i++ ){
    scanf("%s", A[i]);
  }
  for( i=0; i<M; i++ ){
    scanf("%s", B[i]);
  }


  for( i=0; i<N; i++ ){
    for( j=0; j<N; j++ ){
      judge = 1;
      for( k=0; k<M; k++ ){
        for( l=0; l<M; l++ ){
          if( i+k >= N ){
            judge = 0;
            break;
          }
          if( j+l >= N ){
            judge = 0;
            break;
          }
          if( A[i+k][j+l] != B[k][l] ){
            judge = 0;
            break;
          }
        }
      }
      if( judge == 1 ){
        printf("Yes\n");
        return 0;
      }
    }
  }

  printf("No\n");
  return 0;
}
