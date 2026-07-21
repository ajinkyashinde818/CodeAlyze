#include <stdio.h>
long flag[200000];

int main(void){
  long N,M;
  long a,b;
  scanf("%ld%ld",&N,&M);



  for(int i = 0;i < M;i++) flag[i] = 0;
  for(int i = 0;i < M;i++){
    scanf("%ld%ld",&a,&b);
    if(a == 1) flag[b-1]++;
    if(b == N) flag[a-1]++;
  }

  for(int i = 0;i < M;i++){
    if(flag[i] == 2){
      printf("POSSIBLE\n");
      return 0;
    }
  }
  printf("IMPOSSIBLE\n");

  return 0;
}
