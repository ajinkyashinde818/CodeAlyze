#include<stdio.h>

int len(char* str);

int cmp(char* s, char* t);

void sort(char* str, int rev);

int main() {
	char s[100], t[100];
	scanf("%s", &s);
	scanf("%s", &t);
	sort(s, 1);
	sort(t, -1);
	printf(cmp(s, t) == 1 ? "Yes" : "No");

	
}

void sort(char* str, int rev) {
	int i, j;
	for (i = 0; i < len(str); i++) {
		for (j = 0; j < len(str) - 1 - i; j++) {
			if (rev * (str[j] - str[j + 1]) > 0) {
				char temp = str[j];
				str[j] = str[j + 1];
				str[j + 1] = temp;
			}
		}
	}
}

int len(char *str){
	int i = 0;
	while (str[i] != '\0') i++;
	return i;
}

int cmp(char* s, char* t) {
	int i;
	for (i = 0; i <= len(t); i++) {
		if (s[i] < t[i]) return 1;
		else if (t[i] < s[i]) return -1;
	}
	return 0;
}
