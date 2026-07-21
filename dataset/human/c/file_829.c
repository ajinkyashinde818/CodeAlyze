// AOJ 0294 Catch a Thief
// 2018.2.14 
// Lengauer-Tarjan algorithm? 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX   100002
#define QSIZE 150000
#define MAGIC 150

int rank[MAX], m[MAX];
int parent[MAX], vertex[MAX];
int semi[MAX], dom[MAX];
int **b_to, b_hi[MAX];
int *g_to[MAX], g_hi[MAX], _g_hi[MAX];
int *r_to[MAX], r_hi[MAX], _r_hi[MAX];
int *q, top;

int find(int v) { int r;		// union set
	if (rank[v] == v) return v;
	r = find(rank[v]);
	if (semi[m[v]] > semi[m[rank[v]]]) m[v] = m[rank[v]];
	return rank[v] = r;
}
int eval(int v) { find(v); return m[v]; }
void link(int x, int y) { rank[y] = x; }

void tree(int n)
{
	int i, j, k, w, u, v;
	
	for (i = 1; i <= n; i++) rank[i] = m[i] = i;

	k = 1, q[0] = 1, top = 1;
	while (top) {
		v = q[--top];
		if (semi[v]) continue;
		semi[v] = k;
		vertex[k++] = v;
		i = g_hi[v]; while (i--) {
			u = g_to[v][i];
			if (!semi[u]) parent[u] = v, q[top++] = u;
		}
	}
	free(q);

	b_to = malloc(n * sizeof(int *));
	b_to[1] = malloc(25000 << 2), b_to[1][0] = 0, u = 25000;
	for (i = 2; i <= n; i++) {
		b_to[i] = malloc(MAGIC << 2);
		b_to[i][0] = u, u += MAGIC;
	}

	for (i = n; i > 1; i--) {
		w = vertex[i];
		for (j = 0; j < r_hi[w]; j++) {
			v = r_to[w][j], u = eval(v);
			if (semi[u] < semi[w]) semi[w] = semi[u];
		}
		v = vertex[semi[w]];
		b_to[v][b_hi[v]++] = w;
		u = parent[w], link(u, w);
		for (j = 0; j < b_hi[u]; j++) {
			v = b_to[u][j];
			k = eval(v);
			dom[v] = (semi[k] < semi[v])? k: u;
		}
	}
//	free(b_to);

	for (i = 2; i <= n; i++) {
		w = vertex[i];
		if (dom[w] != vertex[semi[w]]) dom[w] = dom[dom[w]];
	}
}

//#define getchar_unlocked()  getchar()
int in()
{
	int n = 0;
	int c = getchar_unlocked();
	do n = (n<<3)+(n<<1) + (c & 0xf), c = getchar_unlocked();
	while (c >= '0');
	return n;
}

int main()
{
	int n, m, i, s, t, Q, r;
	
	n = in(), m = in();

	i = m << 2; if (i < QSIZE) i = QSIZE;
	q = malloc(i << 2);
	top = 0; for (i = 0; i < m; i++) {
		s = in(), t = in();
		q[top++] = s, q[top++] = t;
		_g_hi[s]++, _r_hi[t]++;
	}
	for (i = 1; i <= n; i++) {
		g_to[i] = malloc(_g_hi[i] << 2);
		r_to[i] = malloc(_r_hi[i] << 2);
	}
	top = 0; for (i = 0; i < m; i++) {
		s = q[top++], t = q[top++];
		g_to[s][g_hi[s]++] = t;
		r_to[t][r_hi[t]++] = s;
	}

	tree(n);

	Q = in();
	while (Q--) {
		r = in();
		if (dom[r] == 1) printf("%d\n", r);
		else             printf("%d\n", dom[r]);
	}
	return 0;
}
