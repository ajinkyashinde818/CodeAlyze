#include<stdio.h>
#include<string.h>

int main(void) {
	char S[100001];
	int i, a[100001], n;
	scanf("%s", S);
	n = strlen(S);
	a[0] = 1;
	for (i = 1; i < n + 1; i++) {
		a[i] = 0;
		if (i >= 5) {
			if(a[i - 5] == 1&&S[i - 5] == 'd'&&S[i - 4] == 'r'&&S[i - 3] == 'e'&&S[i - 2] == 'a'&&S[i - 1] == 'm'){
				a[i] = 1;
			}
			if (a[i - 5] == 1 && S[i - 5] == 'e'&&S[i - 4] == 'r'&&S[i - 3] == 'a'&&S[i - 2] == 's'&&S[i - 1] == 'e') {
				a[i] = 1;
			}
		}
		if (i >= 6) {
			if (a[i - 6] == 1 && S[i - 6] == 'e'&&S[i - 5] == 'r'&&S[i - 4] == 'a'&&S[i - 3] == 's'&&S[i - 2] == 'e'&&S[i - 1] == 'r') {
				a[i] = 1;
			}
		}
		if (i >= 7) {
			if (a[i - 7] == 1 && S[i - 7] == 'd'&&S[i - 6] == 'r'&&S[i - 5] == 'e'&&S[i - 4] == 'a'&&S[i - 3] == 'm'&&S[i - 2] == 'e'&&S[i - 1] == 'r') {
				a[i] = 1;
			}
		}
	}
	if (a[n] == 1) { printf("YES\n"); }
	else { printf("NO\n"); }
	return 0;
}
