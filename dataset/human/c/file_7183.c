#include<stdio.h>
int main(void){
  int tate;
  int yoko;
  int i;
  while(1){

    scanf("%d",&tate);
    scanf("%d",&yoko);

    if(tate==0&&yoko==0)break;

    for(i=0;i<tate;i++){
      int j;
      for(j=0;j<yoko;j++){
        if((i==0||i%2==0)&&(j==0||j%2==0))printf("#");
        else if((i==0||i%2==0)&&j%2!=0)printf(".");
        else if(i%2!=0&&(j%2==0||j==0))printf(".");
        else if(i%2!=0&&j%2!=0)printf("#");
      }
      printf("\n");
    }
      printf("\n");
  }

  return 0;
}
