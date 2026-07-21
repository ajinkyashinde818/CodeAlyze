#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int main(void){
  char str[15];
  int num1,num2,Kth;
  scanf("%s",str);
  sscanf(str,"%d",&num1);
  scanf("%s",str);
  sscanf(str,"%d",&num2);
  scanf("%s",str);
  sscanf(str,"%d",&Kth);
  int comDiv[100];
  int i,testNum;
  for(i = 0, testNum = 1; testNum <= num1 && testNum <= num2 && i<100; testNum++){
    if(num1%testNum==0 && num2%testNum==0){ //testNumがnum1,num2の公約数であったら
      comDiv[i]=testNum;
      //printf("%dth:%d\n",i,comDiv[i]);
      i++;//次の番号にする
    }
  }
  //i--;//最大公約数の入っている位置にする
  printf("%d",comDiv[i-Kth]);
  return 0;
}
