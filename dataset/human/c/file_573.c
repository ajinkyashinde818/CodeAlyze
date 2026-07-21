#include<stdio.h>
#include<stdlib.h>
 
int main(void){
 int N, M;
 int i, j, k, l;
 int flag;
 char **A, **B;
 scanf("%d%d\n", &N, &M);
 A = (char **)malloc(sizeof(char *)*N);
 for(i = 0; i < N; i++) A[i] = (char *)malloc(N);
 B = (char **)malloc(sizeof(char *)*M);
 for(i = 0; i < M; i++) B[i] = (char *)malloc(M);
 for(i = 0; i < N; i++){
  for(j = 0; j < N; j++) A[i][j] = getchar();
  getchar();
 }
 for(i = 0; i < M; i++){
  for(j = 0; j < M; j++) B[i][j] = getchar();
  getchar();
 }
 
 for(i = 0; i <= N - M; i++){
  for(j = 0; j <= N - M; j++){
   flag = 1;
   for(k = 0; k < M; k++){
    for(l = 0; l < M; l++){
     if(A[k + i][l + j] != B[k][l]) flag = 0;
    }
   }
   if(flag){
    printf("Yes\n");
    return 0;
   }
  }
 }
 printf("No\n");
 return 0;
}
