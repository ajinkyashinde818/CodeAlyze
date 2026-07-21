#include <stdio.h>
#define N 200000
int main(void){
  int i=0,minv=0,j=0,n=0,maxv=0, Money[N];
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&Money[i]);
  }
  maxv = Money[1]-Money[0];
  minv = Money[0];
  
  for(j = 1; j<=n-1; j++) {
  	if(maxv <Money[j]-minv) maxv = Money[j]-minv;
  	if(Money[j]  < minv) minv = Money[j];
  }
   printf("%d\n",maxv);
   return 0;
}
