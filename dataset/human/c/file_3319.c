#include <stdio.h>
#include <string.h>

char S[112345];
int rec = 0;
bool ans = true;

int main(void) {
	scanf("%s", &S);

	rec = strlen(S) - 1;
	while (true) {
		if (rec <= 0) { break; }
		if (S[rec - 4] == 'd'&&
			S[rec - 3] == 'r'&&
			S[rec - 2] == 'e'&&
			S[rec - 1] == 'a'&&
			S[rec] == 'm') {
			rec -= 5;
		}
		else if (S[rec - 6] == 'd'&&
			S[rec - 5] == 'r'&&
			S[rec - 4] == 'e'&&
			S[rec - 3] == 'a'&&
			S[rec - 2] == 'm'&&
			S[rec - 1] == 'e'&&
			S[rec] == 'r') {
			rec -= 7;
		}
		else if (S[rec - 4] == 'e'&&
			S[rec - 3] == 'r'&&
			S[rec - 2] == 'a'&&
			S[rec - 1] == 's'&&
			S[rec] == 'e') {
			rec -= 5;
		}
		else if (S[rec - 5] == 'e'&&
			S[rec - 4] == 'r'&&
			S[rec - 3] == 'a'&&
			S[rec - 2] == 's'&&
			S[rec - 1] == 'e'&&
			S[rec] == 'r') {
			rec -= 6;
		}
		else {
			ans = false;
			break;
		}
	}

	if (ans == true) { printf("YES\n"); }
	else { printf("NO\n"); }
	return 0;
}
