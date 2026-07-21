#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int main(){
  int A,B,C;
  scanf("%d%d%d",&A,&B,&C);
  int sa;
  sa = C - A - B;
  if(sa <= 1){
    printf("%d\n",B + C);
    return 0;
  }else{
    printf("%d\n",A + B*2 + 1);
    return 0;
  }
}
