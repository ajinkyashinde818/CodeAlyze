#include <stdio.h>

// 入力受付用の変数
#define BUF 200002
char str[BUF];

// 入力された値
#define DIV 1000000007
#define LIM_N 100001
int N, M;
int A[LIM_N];

int broken[LIM_N];
int step[LIM_N];

void receive_input() {
	fgets(str, sizeof(str), stdin);
	sscanf(str, "%d %d", &N, &M);

	for (size_t i = 0; i < M; i++) {
		scanf("%d", &A[i]);
	}
}

int get_step(int i) {
	if (N < i) {
		return 0;
	}

	if (broken[i]) {
		step[i] = 0;
	}

	if (step[i] == -1) {
		int step1 = get_step(i+1);
		int step2 = get_step(i+2);
		step[i] = step1 + step2;
		step[i] %= DIV;
	}

	return step[i];
}

void solve() {
	for (int i = 0; i < M; i++) {
		broken[A[i]] = 1;
	}

	for (int i = 0; i < N; i++) {
		step[i] = -1;
	}
	step[N] = 1;

	for (int i = N-1; 0 <= i ; i--) {
		get_step(i);
	}

	// for (size_t i = 0; i <= N; i++) {
	// 	printf("%2d ", i);
	// }
	// printf("\n");
	// for (size_t i = 0; i <= N; i++) {
	// 	printf("%2d ", step[i]);
	// }
	// printf("\n");

	printf("%d\n", step[0]);
}

int main(void) {
	receive_input();

	solve();

	return 0;
}
