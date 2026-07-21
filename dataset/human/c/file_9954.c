#include<stdio.h> 
#define MAXN 100005
#define NULL -1
typedef struct  {
	int p, l, r;
}Node;

Node T[MAXN];
int n, D[MAXN];

void print(int u)
{
	printf("node %d: ", u);
	printf("parent = %d, ", T[u].p);
	printf("depth = %d, ", D[u]);

	if (T[u].p == NULL)
		printf("root, ");
	else if (T[u].l == NULL)
		printf("leaf, ");
	else
		printf("internal node, ");

	printf("[");
	for (int i = 0, c = T[u].l; c != NULL; i++, c = T[c].r)
	{
		if (i)
			printf(", ");
		printf("%d", c);
	}
	printf("]\n");
}
int rec(int u, int p)
{
	D[u] = p;
	if (T[u].r != NULL)
		rec(T[u].r, p);
	if (T[u].l != NULL)
		rec(T[u].l, p + 1);
}
int main()
{
	int d, v, c, l, r;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		T[i].p = T[i].l = T[i].r = NULL;
	}

	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &v, &d);
		for (int j = 0; j < d; j++)
		{
			scanf("%d", &c);
			if (j == 0)
				T[v].l = c;
			else
				T[l].r = c;
			l = c;
			T[c].p = v;
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (T[i].p == NULL)
			r = i;
	}
	rec(r, 0);
	for (int i = 0; i < n; i++)
		print(i);
	return 0;
}
