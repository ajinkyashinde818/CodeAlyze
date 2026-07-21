#include <stdio.h>
#include <stdlib.h>

int main(void){
  int N,R,a;
  
  a=scanf("%d %d",&N,&R);
  
  if(a!=2){
    printf("正しく入力されていません\n");
    exit(1);
  }
  
  if(N>=10){
    printf("%d\n",R);
  }
  else{
    printf("%d\n",R+100*(10-N));
  }
  return 0;
}
