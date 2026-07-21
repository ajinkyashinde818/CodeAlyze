#include <stdio.h>
#include <stdlib.h>

int main(void){

  int *flag;
  int *dest;

  int num;

  scanf("%d",&num);

  flag = (int*)calloc(num,sizeof(int));
  dest = (int*)calloc(num,sizeof(int));

  int i;

  for(i = 0; i < num;i++){
    scanf("%d",&dest[i]);
  }

  
  int cnt = 0;
  int current = 1;

  while(1){
    if(flag[current] == 1){
      printf("-1\n");
      break;
    }else{
      flag[current] = 1;
    }

    if(current == 2){
      printf("%d\n",cnt);
      break;
    }
    current = dest[current - 1];
    cnt++;
  }


  free(flag);
  free(dest);
  return 0;
}
