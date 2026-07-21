#include <stdio.h>
#include <string.h>

int main(void)
{
	int i = 0;
	char s[100001] = {0};
	int slong;
	
	char d[]  = "dream";
	char dr[] = "dreamer";
	char e[]  = "erase";
	char er[] = "eraser";
	
	scanf("%s", s);
	slong = strlen(s);
	
	while (1)
	{
		int hantei = i;
		
		if (strncmp(s + i, d, 5) == 0)
		{
			if ((strncmp(s + i, dr, 7) == 0) && (strncmp(s + i + 5, e, 5) != 0))
				i += 7;
			else
				i += 5;
		}
		else if (strncmp(s + i, e, 5) == 0)
		{
			if (strncmp(s + i, er, 6) == 0)
				i += 6;
			else
				i += 5;
		}
		
		if (hantei == i)
			break;
	}
	
	if (i == slong)
		printf("YES");
	else
		printf("NO");
	
	return 0;
}
