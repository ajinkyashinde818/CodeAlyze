#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void) {
	int i;
	int K, S;
	int remaining;
	int x, y, z;
	int patterns;
	char buf[128], *ch;

	fgets(buf, sizeof(buf), stdin);
	ch = strtok(buf, " ");
	K = atoi(ch);
	ch = strtok(NULL, " ");
	S = atoi(ch);

	patterns = 0;
	for(x = 0; x <= K; x += 1) {
		remaining = S - x;
		if(remaining < 0) {
			break;
		}
		for(y = 0; y <= K; y += 1) {
			remaining = S - x - y;
			if(remaining < 0) {
				break;
			}
			if(remaining <= K) {
				patterns += 1;
			}
		}
	}

	printf("%d\n", patterns);

	return 0;
}
