#include <stdio.h>
#include <string.h>

int main(void) {
	char s[100000];
	int last;

	scanf("%s", s);
	last = (int)strlen(s) - 1;
	while (last > -1)
	{
		// dream
		if (s[last] == 'm' && s[last - 1] == 'a' && s[last - 2] == 'e' && s[last - 3] == 'r' && s[last - 4] == 'd')
		{
			last -= 5;
		}
		// dreamer
		else if (s[last] == 'r' && s[last - 1] == 'e' && s[last - 2] == 'm' && s[last - 3] == 'a' && s[last - 4] == 'e' &&
			s[last - 5] == 'r' && s[last - 6] == 'd')
		{
			last -= 7;
		}
		// erase
		else if (s[last] == 'e' && s[last - 1] == 's' && s[last - 2] == 'a' && s[last - 3] == 'r' && s[last - 4] == 'e')
		{
			last -= 5;
		}
		// eraser
		else if (s[last] == 'r' && s[last - 1] == 'e' && s[last - 2] == 's' && s[last - 3] == 'a' && s[last - 4] == 'r' &&
			s[last - 5] == 'e')
		{
			last -= 6;
		}
		else
		{
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	return 0;
}
