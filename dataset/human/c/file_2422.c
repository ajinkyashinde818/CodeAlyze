#include<stdio.h>

int main()
{	
	char a[3];
	int b=0,c=0,d=0;
	scanf("%s",&a);
	int i;
	for(i=0;a[i]!='\0';i++)
	{
		if(a[i]=='a')
			b++;	
		if(a[i]=='b')
			c++;
		if(a[i]=='c')
			d++;
	}
	if(c>1 || b>1 || d>1)
		printf("No\n");
	else
		printf("Yes\n");
	return 0;
}
