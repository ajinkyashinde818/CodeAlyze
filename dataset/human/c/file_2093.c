#include <stdio.h>

char N[1234567];
int size;

#if 0
int rleft[1234567], rright[1234567];
#else
int memo[1234567][2];

int search(int pos, int nyan) {
	int answer = 1111111111, candidate;
	if (pos < 0) return nyan * 2;
	if (memo[pos][nyan]) return ~memo[pos][nyan];

	/* 必要分だけ支払う */
	candidate = search(pos - 1, 0) + (N[pos] - '0') + nyan * 2;
	if (candidate < answer) answer = candidate;
	/* 繰り上げる */
	candidate = search(pos - 1, 1) + (9 - (N[pos] - '0'));
	if (candidate < answer) answer = candidate;

	return ~(memo[pos][nyan] = ~answer);
}

#endif

int main(void) {
#if 0
	int i;
#endif
	int kotae = 1111111111;
	if (scanf("%1234565s", N + 1) != 1) return 1;
	N[0] = '0';
	for (size = 0; N[size] != '\0'; size++);
	while (size > 0 && N[size - 1] == '\0') size--;

#if 0
	rleft[0] = N[0] - '0';
	for (i = 1; i < size; i++) {
		rleft[i] = rleft[i - 1] + (N[i] - '0');
	}
	rright[size - 1] = 9 - (N[size - 1] - '0');
	for (i = size - 1 - 1; i >= 0; i--) {
		rright[i] = rright[i + 1] + (9 - (N[i] - '0'));
	}
#else
	kotae = search(size - 1, 0);
#endif

	printf("%d\n", kotae);
	return 0;
}
