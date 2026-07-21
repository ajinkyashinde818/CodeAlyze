#include<stdio.h>
int main(void)
{
	int i,s;
	int a[10];
	for(i=0;i<10;i++){
		scanf("%d",&a[i]);
	}
	s=a[0]+a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9];
	printf("%d\n",s);
	return 0;
}
