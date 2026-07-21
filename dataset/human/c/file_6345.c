#include <stdio.h>
#include <limits.h>
int main(void){
  long int len=0,max1=LONG_MIN,min1=LONG_MAX,temp=0;
  int i=0;
  scanf("%ld",&len);
  while(scanf("%ld",&temp)!=EOF){
      if(max1<(temp-min1)){
        max1=temp-min1;
      }
      if(min1>temp){
        min1=temp;
      }
  }
    printf("%ld\n",max1);
}
