#include<stdio.h>

int main(void)
{
	int a,b;
	
	while(1){
	scanf("%d%d",&a,&b);
	
	if(a == 0 && b == 0) break;
	
	int i,j;
	for(i = 0;i < a;i++)
	{
	for(j = 0;j < b;j++)
		if ((i + j) % 2 == 0) printf("#");
		else printf(".");
	puts("");
	}
	
	puts("");}
	return 0;
	
}
