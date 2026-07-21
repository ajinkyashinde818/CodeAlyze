#include<stdio.h>
#include<string.h>

int main() {
	char s[100010];
	int n = fgets(s, 100005, stdin);
	char* top = s;
	char* bottom = top + strlen(s) - 1;
	if (*bottom == '\n') bottom--;
	int count = 0;
	while (top < bottom) {
		if (*top == *bottom) {
			top++; bottom--; continue;
		}
		if (*top == 'x') {
			top++; count++; continue;
		}
		if (*bottom == 'x') {
			bottom--; count++; continue;
		}
		printf("-1");
		return 0;
	}
	printf("%d", count);
	return 0;
}
