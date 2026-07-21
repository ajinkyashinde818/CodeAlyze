#include<stdio.h>
int main(void)
{
  int i, j, H, W;

  scanf("%d", &H);
  scanf("%d", &W);

  while(!(H==0 && H==W)){
    for(i=1;i<=H;i++){
      j=1;
      if(i%2!=0){
        while(j<=W){
          if(j%2!=0){
            printf("#");
          }else{
            printf(".");
          }
          j++;
        }
        printf("\n");
      }else{
        while(j<=W){
          if(j%2!=0){
            printf(".");
          }else{
            printf("#");
          }
          j++;
        }
        printf("\n");
      }
    }
    printf("\n");
    scanf("%d", &H);
    scanf("%d", &W);
  }
  return 0;
}
