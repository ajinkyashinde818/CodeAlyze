#include<stdio.h>
#include<string.h>
#include<math.h>
int main(void)
{
	int a,s,d,f,g,h,i,j;
	scanf("%d",&a);
	for(i=0;i<a;i++){
		scanf("%d %d",&s,&d);
		f=s%d;
		if(f==0) f=d;
		printf("%d\n",f);
	}
	return 0;
}
