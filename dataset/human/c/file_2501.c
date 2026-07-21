#include <stdio.h>
#include <string.h>

int main (int argc,char **argv)
{
	char s[4];
	char work;
	int b = 0;
	int i = 0,j = 0;
	scanf("%s",s);

	
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3 ; j++)
		{
			b = strcmp(&s[i],&s[j]);

			if (b < 0)
			{
				work = s[i];
				s[i] = s[j];
				s[j] = work;
			}

		}
	}

	


	if (s[0]=='a' && s[1]=='b' && s[2] == 'c')
	{
		printf("Yes\n");
	}
	else 
	{
		printf("No\n");
	}
	return 0;

}
