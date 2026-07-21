#include <stdio.h>
#define MIN_P -1000000000

int main(){
  int i,n,min,profit = MIN_P,nowprice;

  scanf("%d",&n);

  for(i=0;i<n;++i){
    scanf("%d",&nowprice);

    if(i==0)min = nowprice;

    else {
      if(profit < nowprice - min)profit = nowprice - min;
      if(min > nowprice) min = nowprice;
    }

  }
  printf("%d\n",profit);

  return 0;
}
