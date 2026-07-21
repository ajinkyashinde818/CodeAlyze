#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int x,y,z,a=0,b,c;
	char s[4],t[4] = "abc";
	scanf("%s",s);
	for(x =0;x<3;x++)
	{
		for(y=0;y<3;y++) if (s[y] == t[x]) break;
		if (y==3)
		{
			printf("No");
			return 0;
		}
	}
	printf("Yes");
	return 0;
}
