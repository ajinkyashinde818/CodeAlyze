#include<stdio.h>
int main(){
  int N;
  int i;
  scanf("%d\n", &N);
  if(N >= 1 && N <= 100){
    scanf("%d\n", &i);
    if(i >= 1 && i <= N){
      printf("%d\n", N-i+1);
    }else{
      printf("NONE\n");
    }
  }else{
    printf("NONe\n");
  }
}
