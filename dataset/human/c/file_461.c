#include <stdio.h>

typedef struct {
	int key, id, rest, flag;
} data;

typedef struct {
	data obj[200001];
	int size;
} max_heap;

void push(data x, max_heap* h)
{
	int i = ++(h->size), j = i >> 1;
	data tmp;
	h->obj[i] = x;
	while (j > 0) {
		if (h->obj[i].key > h->obj[j].key) {
			tmp = h->obj[j];
			h->obj[j] = h->obj[i];
			h->obj[i] = tmp;
			i = j;
			j >>= 1;
		} else break;
	}
}

data pop(max_heap* h)
{
	int i = 1, j = 2;
	data output = h->obj[1], tmp;
	h->obj[1] = h->obj[(h->size)--];
	while (j <= h->size) {
		if (j < h->size && h->obj[j^1].key > h->obj[j].key) j ^= 1;
		if (h->obj[j].key > h->obj[i].key) {
			tmp = h->obj[j];
			h->obj[j] = h->obj[i];
			h->obj[i] = tmp;
			i = j;
			j <<= 1;
		} else break;
	}
	return output;
}

int main()
{
	int i, N, A[200001], B[200001];
	scanf("%d", &N);
	for (i = 1; i <= N; i++) scanf("%d", &(A[i]));
	for (i = 1; i <= N; i++) scanf("%d", &(B[i]));
	
	int count[3][200001] = {};
	for (i = 1; i <= N; i++) {
		count[0][A[i]]++;
		count[1][B[i]]++;
	}
	
	int C[200001];
	data d, e;
	max_heap h;
	h.size = 0;
	for (i = 1; i <= N; i++) {
		if (count[1][i] > 0) {
			d.key = count[0][i] + count[1][i];
			d.id = i;
			d.rest = count[1][i];
			d.flag = 0;
			push(d, &h);
		}
	}
	for (i = 1; i <= N; i++) {
		if (h.size == 0) break;
		while (1) {
			d = pop(&h);
			if (d.flag == 0 && A[i] > d.id) {
				d.flag = 1;
				d.key -= count[0][d.id];
				push(d, &h);
			} else break;
		}
		if (A[i] != d.id) {
			C[i] = d.id;
			d.key--;
			d.rest--;
			if (d.rest > 0) push(d, &h);
		} else {
			if (h.size == 0) break;
			e = pop(&h);
			C[i] = e.id;
			e.key--;
			e.rest--;
			if (e.rest > 0) push(e, &h);
			push(d, &h);
		}
	}
	if (i <= N) {
		printf("No\n");
		fflush(stdout);
		return 0;
	}
	
	for (i = 1; i <= N; i++) count[2][C[i]]++;
	for (i = 1; i <= N; i++) if (count[1][i] != count[2][i]) break;
	if (i <= N) {
		printf("No\n");
		fflush(stdout);
		return 0;
	} else printf("Yes\n");
	for (i = 1; i < N; i++) printf("%d ", C[i]);
	printf("%d\n", C[N]);
	fflush(stdout);
	return 0;
}
