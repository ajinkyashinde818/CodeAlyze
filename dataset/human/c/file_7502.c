#include <stdio.h>
int main()
{
    int num[10010],i;
    for(i=1;i<10010;i++)
    {
    	scanf("%d",&num[i]);
		if(num[i]==0)
		break;
	}
	for(int i=1;i<10010;i++)
    {
     	if(num[i]==0)
    	break;
    	printf("Case %d: %d\n",i,num[i]);
	}
    return 0;
}
