#include <stdio.h>
#include <string.h>

char S[114514];

char Sriv[114514];

int main(void) {
	int i, l;
	if (scanf("%114513s", S) != 1) return 1;
	l = (int)strlen(S);
	for (i = 0; i < l; i++) {
		Sriv[l - 1 - i] = S[i];
	}
	Sriv[l] = '\0';
	for (i = 0; Sriv[i] != '\0';) {
		if (strncmp(Sriv + i, "maerd", 5) == 0) i += 5;
		else if (strncmp(Sriv + i, "remaerd", 7) == 0) i += 7;
		else if (strncmp(Sriv + i, "esare", 5) == 0) i += 5;
		else if (strncmp(Sriv + i, "resare", 6) == 0) i += 6;
		else {
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	return 0;
}

/*
maerd
remaerd
esare
resare

こうすると多分いい
*/
