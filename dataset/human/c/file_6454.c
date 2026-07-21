#include <stdio.h>
int main(){
  int a[200000],i,minv,maxv;
  scanf("%d",&a[0]);
  for(i=1;i<=a[0];i++){
	scanf("%d",&a[i]);
  }
  minv=a[1];
  maxv=a[2]-a[1];
  for(i=2;i<=a[0];i++){
	 if(maxv<a[i]-minv)
	  maxv = a[i]-minv;
	if(minv>a[i])
	  minv = a[i];
  }
  printf("%d\n",maxv);
  return 0;
}
