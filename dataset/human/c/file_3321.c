#include <stdio.h>

int main(void)
{
	int x=0,y,z;
	char a[] = {"dream"},b[] = {"erase"}, c[] = {"er"};
	char s[100001];
	scanf("%s",s);
	while (s[x] != '\0')
	{
		if (s[x] == 'd')
		{
			x++;
			for(y=1;y<5;y++,x++)
			{
				if (s[x] != a[y])
				{
					printf("NO");
					return 0;
				}
			}
			if ((s[x] == 'e' && s[x+1] == 'r') && s[x+2] != 'a') x+=2;
		} else if (s[x] == 'e')
		{
			x++;
			for(y=1;y<5;y++,x++)
			{
				if (s[x] != b[y])
				{
					printf("NO");
					return 0;
				}
			}
			if (s[x] == 'r') x++;
		} else
		{
			printf("NO");
			return 0;
		}
	}
	printf("YES");
	return 0;
}
