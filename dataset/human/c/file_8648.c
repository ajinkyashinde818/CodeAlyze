#include<stdio.h>

int main(){
  int N, a[100000], push = 1, b[100000] = {0}, count = 0, i;
  
  scanf("%d", &N);
  for (i = 0; i < N; i++){
    scanf("%d", &a[i]);
  }
  while(1){
    if(b[push - 1] == 1){
      printf("-1\n");
      return 0;
    }
    b[push - 1] = 1;
    push = a[push - 1];
    count++;
    if(push == 2){
      printf("%d\n", count);
      return 0;
    }
  }
}
