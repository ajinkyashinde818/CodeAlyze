#include<stdio.h>
#include<stdlib.h>
typedef struct {
	int b;
	int j;
}button;
int main()
{
	int n;
	scanf("%d",&n);
	button *b;
	b = (button*)malloc(sizeof(button)*(n+1));
	for(int t=1;t<=n;t++)
	{
		scanf("%d",&b[t].b);
		b[t].j = 0;
	}
	int s=0,t=1;
	
	do
	{
		b[t].j = 1;
		t = b[t].b;
		s++;
		if(b[t].j == 1)
		{
			printf("-1\n");
			return 0;
		}
	}while(t != 2);
	printf("%d\n",s);
	return 0;
}
