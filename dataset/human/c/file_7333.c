#include <stdio.h>
#include <inttypes.h>

int64_t zettaiti(int64_t x) {
	return x < 0 ? -x : x;
}

/* x以下の最大を求める(ない場合は最小) */
int asumisu(const int64_t data[], int n, int64_t x) {
	int yes = 0, no = n - 1;
	if (data[yes] > x) return 0;
	if (data[no] <= x) return no;
	while (yes + 1 < no) {
		int mid = yes + (no - yes) / 2;
		if (data[mid] <= x) yes = mid; else no = mid;
	}
	return yes;
}

/* x以上の最小を求める(ない場合は最大) */
int mizuhasu(const int64_t data[], int n, int64_t x) {
	int no = 0, yes = n - 1;
	if (data[yes] < x) return n - 1;
	if (data[no] >= x) return no;
	while (no + 1 < yes) {
		int mid = no + (yes - no) / 2;
		if (data[mid] >= x) yes = mid; else no = mid;
	}
	return yes;
}

int A, B;
int Q;
int64_t s[114514];
int64_t t[114514];
int64_t x[114514];

int main(void) {
	int i;
	if (scanf("%d%d%d", &A, &B, &Q) != 3) return 1;
	for (i = 0; i < A; i++) {
		if (scanf("%" SCNd64, &s[i]) != 1) return 1;
	}
	for (i = 0; i < B; i++) {
		if (scanf("%" SCNd64, &t[i]) != 1) return 1;
	}
	for (i = 0; i < Q; i++) {
		if (scanf("%" SCNd64, &x[i]) != 1) return 1;
	}

	for (i = 0; i < Q; i++) {
		int64_t gourikiayame = INT64_C(99999999999999999);
		int64_t zinzya[2], tera[2];
		int j, k;
		zinzya[0] = s[asumisu(s, A, x[i])];
		zinzya[1] = s[mizuhasu(s, A, x[i])];
		tera[0] = t[asumisu(t, B, x[i])];
		tera[1] = t[mizuhasu(t, B, x[i])];
		for (j = 0; j < 2; j++) {
			for (k = 0; k < 2; k++) {
				int64_t sumipe;
				sumipe = zettaiti(zinzya[j] - x[i]) + zettaiti(tera[k] - zinzya[j]);
				if (sumipe < gourikiayame) gourikiayame = sumipe;
				sumipe = zettaiti(tera[k] - x[i]) + zettaiti(zinzya[j] - tera[k]);
				if (sumipe < gourikiayame) gourikiayame = sumipe;
			}
		}
		printf("%" PRId64 "\n", gourikiayame);
	}
	return 0;
}
