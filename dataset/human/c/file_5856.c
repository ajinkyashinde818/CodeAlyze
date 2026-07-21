#include <stdio.h>
#define N 200000
int main ()
{
  int n,b=0,a[N],i,j,minv,maxv;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  
  minv=a[0];
  maxv=a[1]-a[0];
  for(j=1;j<n;j++){
    
    if((a[j]-minv)>maxv)
      maxv=a[j]-minv;
    if(minv>a[j])
      minv=a[j];
  }

  printf("%d\n",maxv);

  return 0;
}
