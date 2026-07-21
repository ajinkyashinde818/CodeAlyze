#include<stdio.h>

int main(void){

 int x[10000];

 int i = -1, cnt = -1;
 do{
  i++;
  scanf("%d", &x[i]);
  cnt++;
 }while(x[i]);

 for(i = 0; i < cnt; i++){
  printf("Case %d: %d\n", i+1, x[i]);
 }

 return 0;

}
