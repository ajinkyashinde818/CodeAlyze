#include <stdio.h>

int lex_smaller(char* s1, char* s2)
{
	int i;
	for (i = 0; s1[i] != 0 && s2[i] != 0; i++) {
		if (s1[i] < s2[i]) return 1;
		else if (s1[i] > s2[i]) return -1;
	}
	if (s1[i] == s2[i]) return 0;
	else if (s1[i] == 0) return 1;
	else return -1;
}

int main()
{
	char s[101], t[101];
	scanf("%s", s);
	scanf("%s", t);

	int i, j, count[2][26] = {};
	for (i = 0; s[i] != 0; i++) count[0][s[i] - 'a']++;
	for (i = 0; t[i] != 0; i++) count[1][t[i] - 'a']++;
	for (i = 0, j = 0; s[i] != 0; i++) {
		for (; count[0][j] == 0; j++);
		s[i] = 'a' + j;
		count[0][j]--;
	}
	for (i = 0, j = 25; t[i] != 0; i++) {
		for (; count[1][j] == 0; j--);
		t[i] = 'a' + j;
		count[1][j]--;
	}
	
	if (lex_smaller(s, t) == 1) printf("Yes\n");
	else printf("No\n");
	fflush(stdout);
	return 0;
}
