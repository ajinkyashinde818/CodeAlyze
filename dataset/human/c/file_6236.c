#include <stdio.h>

#define N 200000

int main(){
	int i,j,n,maxv=0,minv;
	int a[N];

	scanf("%d",&n);
	
	for(i=0;i<n;i++) scanf("%d",&a[i]);
	
maxv=-1000000000;	
minv=a[0];
	
for(j=1;j<n;j++){
  if(maxv<a[j]-minv)maxv=a[j]-minv;
  if(minv>a[j])minv=a[j];
	}
	
	
	printf("%d\n",maxv);
	
	return 0;
	}
