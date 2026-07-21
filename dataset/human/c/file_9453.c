#include <stdio.h>

int main(void){
	int n,d,x,a[100];
	scanf("%d",&n);
	scanf("%d %d",&d,&x);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		x += d / a[i];
		if(d % a[i] != 0)x++;
	}
	printf("%d\n",x);
	return 0;
}
