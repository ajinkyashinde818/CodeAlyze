#include<stdio.h>
int main()
{
	char i,j=3,a[3],k=3;
	scanf("%s",a);
	for(i=0;i<3;i++)
	{
		if(a[i]=='a')
		{
			j--;
			break;
		}
	}
	for(i=0;i<3;i++)
	{
		if(a[i]=='b')
		{
			j--;
			break;
		}
	}
	for(i=0;i<3;i++)
	{
		if(a[i]=='c')
		{
			j--;
			break;
		}
	}
	if(j==0)printf("Yes");
	else printf("No");
	return 0;
}
