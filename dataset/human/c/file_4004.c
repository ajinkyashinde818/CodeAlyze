#include <stdio.h>

int main(void)
{
  int a,b,k,i,j;

  scanf("%d%d%d",&a,&b,&k);
  j=0;
  for(i=100;i>=1;i--){
        if((a%i==0)&&(b%i==0)) j++;
        if(j==k){
                printf("%d\n",i);
                break;
                }
  }
  return 0;
}
