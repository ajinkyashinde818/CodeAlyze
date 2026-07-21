#include<stdio.h>
main()
{
	char s[3] , i;
	int a=0, b=0, c=0;
	gets(s);
	for(i=0;s[i]!='\0';i++)
	{
		if (s[i]=='a')
a=a+1;
		if (s[i]=='c')
c=c+1;
		if (s[i]=='b')
b=b+1;
	}
	if (a==1 && b==1 && c==1)
	printf("Yes");
	else
	printf("No");
	return 0;
}
