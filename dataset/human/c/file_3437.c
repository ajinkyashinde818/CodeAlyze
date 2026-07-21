#include <stdbool.h>
#include <stdio.h>
#include <string.h>
int main() {
	char s[100001], tmp;
	char dream[6] = "maerd";
	char dreamer[8] = "remaerd";
	char erase[6] = "esare";
	char eraser[7] = "resare";
	bool isDream, isDreamer, isErase, isEraser;
	scanf("%s", s);
	int len = strlen(s);
	for (int i = 0; i < len / 2; i++) {
		tmp = s[i];
		s[i] = s[len - i - 1];
		s[len - i - 1] = tmp;
	}
	for (int i = 0; i < len;) {
		isDream = isDreamer = isErase = isEraser = true;
		for (int j = 0; j < 5; j++) {
			if (s[i + j] != dream[j]) {
				isDream = false;
				break;
			}
		}
		for (int j = 0; j < 7; j++) {
			if (s[i + j] != dreamer[j]) {
				isDreamer = false;
				break;
			}
		}
		for (int j = 0; j < 5; j++) {
			if (s[i + j] != erase[j]) {
				isErase = false;
				break;
			}
		}
		for (int j = 0; j < 6; j++) {
			if (s[i + j] != eraser[j]) {
				isEraser = false;
				break;
			}
		}
		if (isDream || isErase) {
			i += 5;
		} else if (isEraser) {
			i += 6;
		} else if (isDreamer) {
			i += 7;
		} else {
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	return 0;
}
