#include<stdio.h>
#include <stdlib.h>
int main(void){
 int num,day,q,sum;
	scanf("%d %d %d",&num,&day,&q);
	int a[num];
	sum=q;
	for(int i=0;i<num;i++){
	scanf("%d",&a[i]);
	sum+=((day-1)/a[i]+1);
}
	printf("%d",sum);
	
	return 0;
}
