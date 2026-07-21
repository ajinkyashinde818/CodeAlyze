#include<stdio.h>
int main(void)
{
  int H, W, i, j;
  while(1){
       
      scanf("%d %d", &H, &W);
       
      if(H == 0 && W == 0){
      break;
    }
      for(j = 1;j < H + 1;j++){
      if(j % 2 == 1){
        for(i = 1;i < W + 1;i++){
        if(i % 2 == 1){
            printf("#");
          }
        if(i % 2 == 0)
          {
            printf(".");
          }
          }
        printf("\n");
        }
         
        if(j % 2 == 0)
          {
        for(i = 1;i < W + 1;i++)
          {
            if(i % 2 == 1)
              {
            printf(".");
              }
            if(i % 2 == 0)
              {
            printf("#");
              }
          }
        printf("\n");
          }
        }
      printf("\n");
    }
     
  return 0;
}
