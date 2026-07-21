#include <stdio.h>

void display(int y,int x){
  int i,j;
  char a[2]="#.";
  for(i=0;i<y;i++){
    for(j=0;j<x;j++){
      putchar(a[(i+j)%2]);
    }
    putchar('\n');
  }
}

int main(void){
  int tate,yoko;
  while(1){
    scanf("%d %d",&tate,&yoko);
    if(tate==0&&yoko==0)break;
    display(tate,yoko);
    printf("\n");
  }
  return 0;
}
