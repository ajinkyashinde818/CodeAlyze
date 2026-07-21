#include <stdio.h>

#define NUMBER 10000

int main(void){
  int i,j;
  int num[NUMBER];
  int max;

  j=0;
  while(1){
    scanf("%d", &num[j]);
    if(num[j]==0)
      break;
    j++;
    max=j;
  }

  for(i=0; i<max; i++){
    printf("Case %d: %d\n", i+1, num[i]);
  }

  return 0;
}
