#include <stdio.h>

int main()
{
	char S[100001];
	scanf("%s", S);
	
	int i, l;
	for (l = 0; S[l] != '\0'; l++);
	for (i = l; i > 0; ) {
		if (i >= 5 && S[i-5] == 'd' && S[i-4] == 'r' && S[i-3] == 'e' && S[i-2] == 'a' && S[i-1] == 'm') i -= 5;
		else if (i >= 7 && S[i-7] == 'd' && S[i-6] == 'r' && S[i-5] == 'e' && S[i-4] == 'a' && S[i-3] == 'm' && S[i-2] == 'e' && S[i-1] == 'r') i -= 7;
		else if (i >= 5 && S[i-5] == 'e' && S[i-4] == 'r' && S[i-3] == 'a' && S[i-2] == 's' && S[i-1] == 'e') i -= 5;
		else if (i >= 6 && S[i-6] == 'e' && S[i-5] == 'r' && S[i-4] == 'a' && S[i-3] == 's' && S[i-2] == 'e' && S[i-1] == 'r') i -= 6;
		else break;
	}
	
	if (i == 0) printf("YES\n");
	else printf("NO\n");
	fflush(stdout);
	return 0;
}
