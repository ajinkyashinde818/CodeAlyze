#include<stdio.h>

int main(void){
  int k, s;
  int i;
  int j;
  int count=0;

  scanf("%d %d", &k, &s);

  for(i=0; i<=s && i<=k; i++){
    for(j=0; j<=k && j<=s-i; j++){
      if(s-(i+j)<=k){
        count++;
      }
    }
  }

  printf("%d\n", count);

  return 0;
}
