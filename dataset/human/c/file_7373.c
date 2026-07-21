#include <stdio.h>

int main(void)
{
	int number[20000];
	int i;
	int howmany;
	
	for(i=0;i<20000;i++)
	{
		scanf("%d",&number[i]);
		if(number[i] == 0)
		{
			howmany = i;
			
			goto next;
		}
	}
	
	next:
	
	for(i=0;i<howmany;i++)
	{
		printf("Case %d: %d\n",i+1,number[i]);
	}
	
	return 0;
}
