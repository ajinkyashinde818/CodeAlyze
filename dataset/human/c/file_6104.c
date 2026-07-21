#include<stdio.h>
#include<limits.h>

int main(){
  int i,buy,value,sell=0,profit=INT_MIN,num,flag=0;
  scanf("%d",&num);
  scanf("%d",&buy);
  for(i=0;i<num-1;i++){
    scanf("%d",&value);
    if(buy > value && i < num-2){
      sell=value;
      if(profit < (sell - buy))profit = sell - buy;
      buy=value;
      sell = 0;
    }
    else if(sell <= value){
      sell=value;
    }
    if(profit < (sell - buy))profit = sell - buy;
  }
  printf("%d\n",profit);
  return 0;
}
