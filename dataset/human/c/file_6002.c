#include<stdio.h>

int main(){
  int mn,profit,data,temp,ptemp,i;
  mn = 1000000001;
  profit = -2000000003;
  scanf("%d",&data);
  scanf("%d",&mn);
  for(i=0;i<data-1;i++){
    scanf("%d",&temp);
    ptemp = temp - mn;
    if(ptemp > profit)profit = ptemp;
    if(mn > temp)mn = temp;
      }
  printf("%d\n",profit);

  return 0;
}
