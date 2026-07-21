#include <stdio.h>
#pragma warning (disable:4996)

typedef struct { int D1; int D2; }DICE;


int main() {
	//input
	int N;
	(void)scanf("%d", &N);
	DICE dice[3] = {};
	for (int i = 0; i < 3; i++) {
		(void)scanf("%d%d", &dice[i].D1, &dice[i].D2);
	}

	//judge
	bool ans = false;
	if ((dice[0].D1 == dice[0].D2) && (dice[1].D1 == dice[1].D2) && (dice[2].D1 == dice[2].D2)) {
		ans = true;
	}
	for (int i = 0; i < N - 3; i++) {
		if ((dice[0].D1 == dice[0].D2) && (dice[1].D1 == dice[1].D2) && (dice[2].D1 == dice[2].D2)) {
			ans = true;
			break;
		}
		else {
			dice[0] = dice[1];
			dice[1] = dice[2];
			(void)scanf("%d%d", &dice[2].D1, &dice[2].D2);
		}
	}

	//output
	if (ans)printf("Yes"); else printf("No");
}
