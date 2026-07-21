#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
	int i, mojisu = 0;
	char s[100000];
	char t[100000];
	char dream[6] = { "dream" };
	char dreamer[8] = { "dreamer" };
	char erase[6] = { "erase" };
	char eraser[7] = { "eraser" };
	bool flag = true;

	scanf("%s", s);

	while (s[mojisu] != '\0'){
		mojisu++;
	}

	while (mojisu >= 0 && flag == true) {
		flag = false;
		while (1) {
			for (i = 7; i > 0; i--) t[7 - i] = s[mojisu - i];
			t[7] = '\0';
			if (strcmp(t, dreamer) == 0) {
				flag = true;
				mojisu -= 7;
				break;
			}

			for (i = 6; i > 0; i--) t[6 - i] = s[mojisu - i];
			t[6] = '\0';
			if (strcmp(t, eraser) == 0) {
				flag = true;
				mojisu -= 6;
				break;
			}

			for (i = 5; i > 0; i--) t[5 - i] = s[mojisu - i];
			t[5] = '\0';
			if (strcmp(t, dream) == 0) {
				flag = true;
				mojisu -= 5;
				break;
			}

			for (i = 5; i > 0; i--) t[5 - i] = s[mojisu - i];
			t[5] = '\0';
			if (strcmp(t, erase) == 0) {
				flag = true;
				mojisu -= 5;
			}
			break;
		}
	}

	printf(mojisu <= 0 ? "YES\n" : "NO\n");

	return 0;
}
