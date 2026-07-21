#include <stdio.h>
#include <limits.h>
#define N 200001
#define imax(a,b) (a>b)?a:b
#define imin(a,b) (a<b)?a:b

int main()
{
  int n,r;
  scanf("%d",&n);
  int ans=INT_MIN,rmin;
  
  int i;
  for(i=0;i<n;i++){
    scanf("%d",&r);
    if(i==0) rmin=r;
    else{
      ans=imax(ans,r-rmin);
      rmin=imin(r,rmin);
    }
  }
  
  printf("%d\n",ans);
  return 0;
}
