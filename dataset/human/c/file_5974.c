#include <stdio.h>
int main(void){
	int a,b,c,i,min,sum;
	scanf("%d",&a);
	scanf("%d",&b);
	scanf("%d",&c);
	sum = c-b;
	if(c<b)
		min=c;
	else
		min=b;
	for(i=2;i<a;i++){
		scanf("%d",&b);
		if(sum < b - min)
			sum = b - min;
		if(min > b)
			min = b;
	} 
	printf("%d\n",sum);
	return 0;
}
