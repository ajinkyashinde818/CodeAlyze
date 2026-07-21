#include <stdio.h>
#include <stdlib.h>

typedef struct List {
	struct List *next;
	int data, dist;
} Queue;

int main()
{
	int i, N, a[100001];
	scanf("%d", &N);
	for (i = 1; i <= N; i++) scanf("%d", &(a[i]));
	
	int flag[100001] = {0, 1};
	Queue q[100001], *p, *tail = &(q[1]);
	tail->next = NULL;
	tail->data = a[1];
	tail->dist = 0;
	for (p = tail; p != NULL; p = p->next) {
		if (flag[p->data] == 0) {
			flag[p->data] = 1;
			q[p->data].next = NULL;
			q[p->data].data = a[p->data];
			q[p->data].dist = p->dist + 1;
			tail->next = &(q[p->data]);
			tail = tail->next;
			if (p->data == 2) break;
		}
	}
		
	if (p != NULL) printf("%d\n", tail->dist);
	else printf("-1\n");
	fflush(stdout);
	return 0;
}
