#include <stdio.h>

int main(void)
{
 int n,t,R[200000],max,min;

 scanf("%d",&n);

 for(t=0;t<n;t++){
  scanf("%d",&R[t]);
 }

 min=R[0];
 max=R[1]-R[0];
 for(t=1;t<n;t++){
  if( max < R[t]-min ){
    max = R[t]-min;
  }
  if( min > R[t] ){
    min = R[t];
  }
 }

 printf("%d\n",max);

 return 0;

}
