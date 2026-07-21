#include <stdio.h>

#define KI_MAX (1 << 18) /* 262144 */

typedef struct ki_t {
	int ki[KI_MAX * 2 - 1], all[KI_MAX * 2 - 1];
} ki_t;

int tnh(int a, int b) { /* 小さくない方 */
	return a >= b ? a : b;
}

void add_i(ki_t* ki, int idx, int qmin, int qmax, int smin, int smax, int v) {
	if (qmax <= smin || smax <= qmin) { /* セグメントがクエリから完全に外れている */
		/* nop */
	} else if (qmin <= smin && smax <= qmax) { /* セグメントがクエリに完全に含まれる */
		ki->all[idx] = tnh(ki->all[idx], v);
	} else {
		int smid = smin + (smax - smin) / 2;
		int lidx = idx * 2 + 1, ridx = idx * 2 + 2;
		ki->all[lidx] = tnh(ki->all[lidx], ki->all[idx]);
		ki->all[ridx] = tnh(ki->all[ridx], ki->all[idx]);
		ki->all[idx] = 0;
		add_i(ki, lidx, qmin, qmax, smin, smid, v);
		add_i(ki, ridx, qmin, qmax, smid, smax, v);
		ki->ki[idx] = tnh(tnh(ki->ki[lidx], ki->all[lidx]), tnh(ki->ki[ridx], ki->all[ridx]));
	}
}

void add(ki_t* ki, int min, int max, int v) {
	if (ki != NULL && min < max) add_i(ki, 0, min, max, 0, KI_MAX, v);
}

int get_i(ki_t* ki, int idx, int qmin, int qmax, int smin, int smax) {
	if (qmax <= smin || smax <= qmin) { /* セグメントがクエリから完全に外れている */
		return 0;
	} else if (qmin <= smin && smax <= qmax) { /* セグメントがクエリに完全に含まれる */
		return tnh(ki->ki[idx], ki->all[idx]);
	} else {
		int smid = smin + (smax - smin) / 2;
		int lidx = idx * 2 + 1, ridx = idx * 2 + 2;
		int left = get_i(ki, lidx, qmin, qmax, smin, smid);
		int right = get_i(ki, ridx, qmin, qmax, smid, smax);
		return tnh(tnh(left, right), ki->all[idx]);
	}
}

int get(ki_t* ki, int min, int max) {
	return ki != NULL && min < max ? get_i(ki, 0, min, max, 0, KI_MAX) : 0;
}

int N, K, C;
char S[271828];

ki_t k1, k2, k3;

#define INFU 222222

int main(void) {
	int i;
	if (scanf("%d%d%d", &N, &K, &C) != 3) return 1;
	if (scanf("%271827s", S) != 1) return 1;

	/* クールダウン含めそこまでで何日 */
	for (i = 0; i < N; i++) {
		int cur = get(&k1, i, i + 1);
		if (S[i] != 'x') add(&k1, i + C + 1, INFU, cur + 1);
	}
	/* そこから何日 */
	for (i = N - 1; i >= 0; i--) {
		int a = get(&k2, i + 1, INFU);
		int b = S[i] != 'x' ? get(&k2, i + C + 1, INFU) + 1 : 0;
		add(&k2, i, i + 1, tnh(a, b));
	}

	for (i = 0; i <= N + C; i++) add(&k3, i, i + 1, get(&k1, i, i + 1) + get(&k2, i, i + 1));

#if 0
	for (i = 0; i < N; i++) {
		printf("  %c", S[i]);
	}
	puts("");
	for (i = 0; i <= N + C; i++) {
		printf("%3d", get(&k1, i, i + 1));
	}
	puts("");
	for (i = 0; i < N; i++) {
		printf("%3d", get(&k2, i, i + 1));
	}
	puts("");
#endif
	if (C == 0) {
		int count = 0;
		for (i = 0; i < N; i++) {
			if (S[i] == 'o') count++;
		}
		if (count == K) {
			for (i = 0; i < N; i++) {
				if (S[i] == 'o') printf("%d\n", i + 1);
			}
		}
	} else {
		for (i = 0; i < N; i++) {
			if (S[i] == 'o' && get(&k3, i + 1, i + C + 1) < K) printf("%d\n", i + 1);
		}
	}

	return 0;
}

/*

働く→C日後以降のoへ
働かない→明日以降のoへ

「そこを外したとき、何日働けるか」

クールダウン含めそこまでで何日
そこから何日

*/
