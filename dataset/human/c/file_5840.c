#include<stdio.h>
int main(void){
  int line,num,i;
  int max_diff=-1000000000,min;
  scanf("%d",&line);
  scanf("%d",&min);
  while(scanf("%d",&num)!=EOF){
    if(max_diff<num-min) max_diff=num-min;
    if(min>num) min=num;
  }
  printf("%d\n",max_diff);
  return 0;
}
