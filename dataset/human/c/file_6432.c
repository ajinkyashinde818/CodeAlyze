#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main(void){
	
	int n,a,b,c;
	int max=-1000000000;
	
	scanf("%d",&n);
	scanf("%d",&c);
	int min=c;
	for(int i=1;i<n;i++){
		scanf("%d",&a);
		b=a-min;
		if(max<b) max=b;
		if(min>a) min=a;
	}
	
	printf("%d\n",max);
	
	return 0;
}
