#include <stdio.h>

int N;
int A[114514];

int pos_cnt = 0;
int pos[114514];
int neg_cnt = 0;
int neg[114514];
int zero_cnt = 0;

int ptr = 0;
int kotae_list[114514][2];

int main(void) {
	int i;
	int kotae;
	if (scanf("%d", &N) != 1) return 1;
	for (i = 0; i < N; i++) {
		if (scanf("%d", &A[i]) != 1) return 1;
		if (A[i] > 0) pos[pos_cnt++] = A[i];
		else if (A[i] < 0) neg[neg_cnt++] = A[i];
		else zero_cnt++;
	}

	if (zero_cnt > 0) {
		if (neg_cnt == 0) {
			neg_cnt = zero_cnt;
			for (i = 0; i < zero_cnt; i++) neg[i] = 0;
		} else {
			for (i = 0; i < zero_cnt; i++) pos[pos_cnt++] = 0;
		}
	}

	if (neg_cnt == 0) {
		int best = 0;
		int first = 0;
		int first_valid = 0;
		for (i = 1; i < pos_cnt; i++) {
			if (pos[i] < pos[best]) best = i;
		}
		kotae = pos[best];
		for (i = 0; i < pos_cnt; i++) {
			if (i == best) continue;
			if (!first_valid) {
				first = pos[i];
				first_valid = 1;
			} else {
				kotae_list[ptr][0] = kotae;
				kotae_list[ptr][1] = pos[i];
				kotae = kotae - pos[i];
				ptr++;
			}
		}
		kotae_list[ptr][0] = first;
		kotae_list[ptr][1] = kotae;
		kotae = first - kotae;
		ptr++;
	} else if (pos_cnt == 0) {
		int best = 0;
		for (i = 1; i < neg_cnt; i++) {
			if (neg[i] > neg[best]) best = i;
		}
		kotae = neg[best];
		for(i = 0; i < neg_cnt; i++) {
			if (i == best) continue;
			kotae_list[ptr][0] = kotae;
			kotae_list[ptr][1] = neg[i];
			kotae = kotae - neg[i];
			ptr++;
		}
	} else {
		kotae = neg[0];
		for (i = 1; i < pos_cnt; i++) {
			kotae_list[ptr][0] = kotae;
			kotae_list[ptr][1] = pos[i];
			kotae = kotae - pos[i];
			ptr++;
		}
		kotae_list[ptr][0] = pos[0];
		kotae_list[ptr][1] = kotae;
		kotae = pos[0] - kotae;
		ptr++;
		for (i = 1; i < neg_cnt; i++) {
			kotae_list[ptr][0] = kotae;
			kotae_list[ptr][1] = neg[i];
			kotae = kotae - neg[i];
			ptr++;
		}
	}

	printf("%d\n", kotae);
	for (i = 0; i < ptr; i++) {
		printf("%d %d\n", kotae_list[i][0], kotae_list[i][1]);
	}
	return 0;
}

/*

((((x- (((a-b)-c)-d) )-y)-z)-w)

y, z, w : 負の数
x       : 正の数
a       : 負の数
b, c, d : 正の数

負の数しかない場合

(((x-y)-z)-w)

xに一番絶対値が小さい数を持ってくる

正の数しかない場合

(x- (((a-b)-c)-d) )

aに一番絶対値が小さい数を持ってくる

*/
