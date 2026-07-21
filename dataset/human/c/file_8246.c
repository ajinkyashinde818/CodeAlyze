#include<stdio.h>
int main()
{
	char s[10];
	int n,k,i;
	scanf("%d",&n);
	scanf("%s",&s);
	scanf("%d",&k);
	for(i=0;i<n;i++)
	{
		if(s[i]!=s[k-1])
			s[i]='*';
	}
	printf("%s\n",s);
	return 0;
}
