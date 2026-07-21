#include <stdio.h>
#include <stdlib.h>

typedef struct List {
	struct List *next;
	int v;
} list;

typedef struct {
	int *par, *size, *height;
} UF_forest;

void UF_initialize(UF_forest *F, int n)
{
	int i;
	F->par = (int*)malloc(sizeof(int) * (n + 1));
	F->size = (int*)malloc(sizeof(int) * (n + 1));
	F->height = (int*)malloc(sizeof(int) * (n + 1));
	for (i = 1; i <= n; i++) {
		F->par[i] = i;
		F->size[i] = 1;
		F->height[i] = 1;
	}
}

void UF_merge(UF_forest *F, int u, int v)
{
	for (; F->par[u] != u; u = F->par[u]);
	for (; F->par[v] != v; v = F->par[v]);
	if (u == v) return;
	else if (F->height[u] > F->height[v]) {
		F->par[v] = u;
		F->size[u] += F->size[v];
	} else {
		F->par[u] = v;
		F->size[v] += F->size[u];
		if (F->height[u] == F->height[v]) F->height[v]++;
	}
}

int UF_size(UF_forest *F, int v)
{
	for (; F->par[v] != v; v = F->par[v]);
	return F->size[v];
}

int main()
{
	int i, N, K, L, u, w;
	list *adj[2][200001] = {}, e[2][200001];
	scanf("%d %d %d", &N, &K, &L);
	for (i = 0; i < K; i++) {
		scanf("%d %d", &u, &w);
		e[0][i*2].v = w;
		e[0][i*2+1].v = u;
		e[0][i*2].next = adj[0][u];
		e[0][i*2+1].next = adj[0][w];
		adj[0][u] = &(e[0][i*2]);
		adj[0][w] = &(e[0][i*2+1]);
	}
	for (i = 0; i < L; i++) {
		scanf("%d %d", &u, &w);
		e[1][i*2].v = w;
		e[1][i*2+1].v = u;
		e[1][i*2].next = adj[1][u];
		e[1][i*2+1].next = adj[1][w];
		adj[1][u] = &(e[1][i*2]);
		adj[1][w] = &(e[1][i*2+1]);
	}
	
	int flag[2][200001] = {}, q[200001], head, tail;
	list *p;
	for (i = 1; i <= N; i++) {
		if (flag[0][i] != 0) continue;
		flag[0][i] = i;
		q[0] = i;
		for (head = 0, tail = 1; head < tail; head++) {
			u = q[head];
			for (p = adj[0][u]; p != NULL; p = p->next) {
				w = p->v;
				if (flag[0][w] == 0) {
					flag[0][w] = flag[0][u];
					q[tail++] = w;
				}
			}
		}
	}
	
	int j, k, comp[200001] = {}, appear[200001];
	UF_forest F;
	UF_initialize(&F, N);
	for (i = 1; i <= N; i++) {
		if (flag[1][i] != 0) continue;
		flag[1][i] = 1;
		q[0] = i;
		comp[flag[0][i]] = i;
		appear[0] = flag[0][i];
		k = 1;
		for (head = 0, tail = 1; head < tail; head++) {
			u = q[head];
			for (p = adj[1][u]; p != NULL; p = p->next) {
				w = p->v;
				if (flag[1][w] == 0) {
					flag[1][w] = 1;
					q[tail++] = w;
					if (comp[flag[0][w]] == 0) {
						comp[flag[0][w]] = w;
						appear[k++] = flag[0][w];
					} else UF_merge(&F, w, comp[flag[0][w]]);
				}
			}
		}
		for (j = 0; j < k; j++) comp[appear[j]] = 0;
	}
	
	for (i = 1; i < N; i++) printf("%d ", UF_size(&F, i));
	printf("%d\n", UF_size(&F, N));
	fflush(stdout);
	return 0;
}
