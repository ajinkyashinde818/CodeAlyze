#include <stdio.h>

int main(void){
	int n,a,minv,maxv,i,b;
	scanf("%d",&n);
	scanf("%d",&b);
	minv=b;

	for(i=2;i<=n;i++){
		scanf("%d",&a);
		if(i==2)
			maxv = a-b;
		if(maxv < a-minv)
			maxv = a-minv;
		if(minv > a)
			minv =a;
	}
	printf("%d\n",maxv);
	return 0;
}
