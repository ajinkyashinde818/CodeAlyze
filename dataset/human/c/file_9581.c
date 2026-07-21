#include <stdio.h>
int main (){
int n,d,x,i,sum,k;
  scanf ("%d%d%d",&n,&d,&x);
  for (i=0;i<n;i++){
    scanf ("%d",&k);
  sum=sum+(d-1)/k+1;
  }
  sum=sum+x;
  printf ("%d",sum);
return 0;
}
