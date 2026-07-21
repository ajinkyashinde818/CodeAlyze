#include <stdio.h>

#define N_MAX 500

int list[N_MAX][N_MAX];
int isinvited[N_MAX];

int n, m;

int answer(){
	int i, a = 0;
	for (i = 1; i < n; i++) {
		if (isinvited[i]) a++;
	}

	return printf("%d\n", a);
}

int solve(){
	int i, j;
	int result[N_MAX] = {0};

	for (i = 0; i < n; i++) {
		if (isinvited[i]) {
			for (j = 0; j < n; j++) {
				if (list[i][j]) result[j] = 1;
			}
		}
	}

	for (i = 0; i < n; i++) {
		isinvited[i] = result[i];
		// fprintf(stderr, "[%d] %d ", i, isinvited[i]);
	}
	// fprintf(stderr, "\n");

	return 0;
}

int mn(void){
	int i, j;

	// scanf("%d%d", &n, &m);

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			list[i][j] = ((i == j) ? 1 : 0);
		}
		isinvited[i] = 0;
	}


	while (m--) {
		int l, r;
		scanf("%d%d", &l, &r);
		l--;
		r--;
		list[l][r] = list[r][l] = 1;
	}

	// fprintf(stderr, "Line %d\n", __LINE__);

	isinvited[0] = 1;

	solve();
	solve();

	answer();

	return 0;
}


int main(void){
	while (scanf("%d%d", &n, &m), (n || m)) {
		mn();
	}

	return 0;
}
