#include <stdio.h>
#include <string.h>
int main() {
	int i;
	char s[100010];
	scanf("%s", s);
	i = strlen(s) - 1;
	while (i >= 0)
	{
		if (s[i - 4] == 'd' && s[i - 3] == 'r' && s[i - 2] == 'e' && s[i - 1] == 'a' && s[i] == 'm') {
			i -= 5;
		}
		else if (s[i - 6] == 'd' && s[i - 5] == 'r' && s[i - 4] == 'e' && s[i -3] == 'a' && s[i- 2] == 'm' && s[i - 1] == 'e' && s[i] == 'r') {
			i -= 7;
		}
		else if (s[i - 4] == 'e' && s[i - 3] == 'r' && s[i - 2] == 'a' && s[i - 1] == 's' && s[i] == 'e') {
			i -= 5;
		}
		else if(s[i - 5] == 'e' && s[i - 4] == 'r' && s[i - 3] == 'a' && s[i - 2] == 's' && s[i - 1] == 'e' && s[i] == 'r'){
			i -= 6;
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
