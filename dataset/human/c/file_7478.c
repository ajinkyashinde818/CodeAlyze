#include<stdio.h>

int main()
{
	int input[10000];
	int i=0,count=0;
	
	while(1)
	{
		scanf("%d",&input[i]);
		if(input[i]==0) break;
		i++;
		count++;
	}
	
	for(i=0;i<count;i++)
		printf("Case %d: %d\n",i+1,input[i]);
	
	return 0;
}
