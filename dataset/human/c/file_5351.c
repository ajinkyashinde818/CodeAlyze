#include <stdio.h>

int main()
{
  int N, M, X, C[13], A[13][13];
  int sum = 0;
  int j = 0;
  int sum_under = 0;
  int count = 0;
  int sum_end = 200000000;

  scanf("%d", &N);
  scanf("%d", &M);
  scanf("%d", &X);

  for(int i = 0; i < 13; i++){
    C[i] = 0;
    for(int k = 0; k < 13; k++){
      A[i][k] = 0;
    }
  }


  for(int k = 0; k < N; k++){
    scanf("%d", &C[k]);
    for(int i = 0; i < M; i++){
      scanf("%d", &A[k][i]);
    }
  }

  int q, w, e, r, t, y, u, o, p, a, s, d;

  for(q = 0; q < 2; q++){
    for(w = 0; w < 2; w++){
      for(e = 0; e < 2; e++){
        for(r = 0; r < 2; r++){
          for(t = 0; t < 2; t++){
            for(y = 0; y < 2; y++){
              for(u = 0; u < 2; u++){
                for(o = 0; o < 2; o++){
                  for(p = 0; p < 2; p++){
                    for(a = 0; a < 2; a++){
                      for(s = 0; s < 2; s++){
                        for(d = 0; d < 2; d++){
                          sum = q*C[0] + w*C[1] + e*C[2] + r*C[3] + t*C[4] + y*C[5] + u*C[6] + o*C[7] + p*C[8] + a*C[9] + s*C[10] + d*C[11];
                          for(int i = 0; i < M; i++){
                            sum_under = q*A[0][i] + w*A[1][i] + e*A[2][i] + r*A[3][i] + t*A[4][i] + y*A[5][i] + u*A[6][i] + o*A[7][i] + p*A[8][i] + a*A[9][i] + s*A[10][i] + d*A[11][i];
                            if(sum_under >= X){
                              count += 1;
                            }
                          }
                          if(count == M){
                            j = 1;
                            if(sum_end > sum){
                              sum_end = sum;
                            }
                          }
                          count = 0;
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }

if(j == 1){
  printf("%d\n", sum_end);
}
else{
  printf("-1\n");
}


    return 0;
  }
