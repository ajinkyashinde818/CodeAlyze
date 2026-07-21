#include <stdio.h>
#include <stdlib.h>

typedef struct List {
	struct List *prev, *next;
	char c;
} list;

int main()
{
	int i, Q, T[200001], F[200001];
	char S[100001] = {}, C[200001] = {};
	scanf("%s", S);
	scanf("%d", &Q);
	for (i = 1; i <= Q; i++) {
		scanf("%d", &(T[i]));
		if (T[i] == 2) scanf("%d %c", &(F[i]), &(C[i]));
	}
	
	int l, flip = 0;
	list data[300001] = {}, *head = &(data[0]), *tail, *p;
	data[0].prev = NULL;
	data[0].c = S[0];
	for (l = 1; S[l] != 0; l++) {
		data[l].prev = &(data[l-1]);
		data[l-1].next = &(data[l]);
		data[l].c = S[l];
	}
	data[l-1].next = NULL;
	data[l-1].c = S[l-1];
	tail = &(data[l-1]);
	
	for (i = 1; i <= Q; i++) {
		if (T[i] == 1) flip ^= 1;
		else {
			data[l+i].c = C[i];
			if ((F[i] + flip) % 2 == 1) {
				data[l+i].prev = NULL;
				data[l+i].next = head;
				head->prev = &(data[l+i]);
				head = &(data[l+i]);
			} else {
				data[l+i].prev = tail;
				data[l+i].next = NULL;
				tail->next = &(data[l+i]);
				tail = &(data[l+i]);
			}
		}
	}
	
	if (flip == 0) {
		for (p = head; p != NULL; p = p->next) printf("%c", p->c);
	} else {
		for (p = tail; p != NULL; p = p->prev) printf("%c", p->c);
	}
	printf("\n");
	fflush(stdout);
	return 0;
}
