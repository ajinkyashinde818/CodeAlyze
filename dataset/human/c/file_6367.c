#include <stdio.h>
#define N 200000
int main(){
  int a[N],i,j,k;
  int minv,maxv;
  scanf("%d",&k);
  for(i=0;i<k;i++){
  scanf("%d",&a[i]);
  }
  maxv=a[1]-a[0];
  minv=a[0];
  for(j=1;j<k;j++){
    if(maxv<a[j]-minv)
      maxv=a[j]-minv; 
      if(minv>a[j])
      minv=a[j];
  }
  printf("%d\n",maxv);
  return 0;
}
