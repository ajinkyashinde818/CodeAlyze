#include <stdio.h>
#include <stdlib.h>
int main(){
  int input[2], keep, i, n, max;
  scanf("%d",&n);
  for(i=0; i<n; i++){
    if(i == 0){
      scanf("%d",&input[0]);
      continue;
    }
    if(i == 1){
      scanf("%d",&input[1]);  
      max = input[1] - input[0];
      continue;
    }
    scanf("%d",&keep);
    if(input[0] > input[1])
      input[0] = input[1];
    input[1] = keep;
      if(input[1]-input[0] > max)
	max = input[1]-input[0];
  }
  printf("%d\n",max);
  return 0;
}
