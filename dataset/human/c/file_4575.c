#include <stdio.h>
#define MAX 100005
#define NIL -1

typedef struct{
	int p, lc, rc;
}node;

node T[MAX];
int i,j,n, deg;

void degree(int id){
	deg = 0;
	if (T[id].lc != NIL || T[id].rc != NIL){
		if (T[id].lc != NIL && T[id].rc != NIL)
			deg = 2;
		else deg = 1;
	}
}

int height(int u){
	int hl = 0, hr = 0;
	if(T[u].lc != NIL)
		hl = height(T[u].lc) + 1;
	if(T[u].rc != NIL)
		hr = height(T[u].rc) + 1;
	if (hr>hl)
		return hr;
	else return hl;
}

int main(void) {
	int id, l, r, dep=0, count;
	
	scanf("%d", &n);
	//initialize
	for (i=0; i<n; i++){
		T[i].p = T[i].lc = T[i].rc = NIL;
	}
	
	for(i=0; i<n; i++){
		scanf("%d", &id);
		scanf("%d %d", &l, &r);
		T[id].lc = l;
		T[id].rc = r;
		T[l].p = T[r].p = id;
	}

	for(i=0; i<n; i++){
		printf("node %d: parent = %d, ", i, T[i].p);
		count = i;
		
		if (T[T[i].p].lc != NIL && T[T[i].p].lc != i){
			if (T[T[i].p].lc == 0 && T[T[0].p].rc == i)
				printf("sibling = %d, ", T[T[i].p].lc);
			else if  (T[T[i].p].lc != 0)
				printf("sibling = %d, ", T[T[i].p].lc);
			else printf("sibling = -1, ");
		}
		else if (T[T[i].p].rc != NIL && T[T[i].p].rc != i){
			if (T[T[i].p].rc == 0 && T[T[0].p].lc == i)
				printf("sibling = %d, ", T[T[i].p].rc);
			else if  (T[T[i].p].rc != 0)
				printf("sibling = %d, ", T[T[i].p].rc);
			else printf("sibling = -1, ");
		}
		else printf("sibling = -1, ");
		
		degree(i);
		printf("degree = %d, ", deg);

		while(T[count].p != NIL){
			dep++;
			count = T[count].p;
		}
		printf("depth = %d, height = %d, ", dep, height(i));
		dep=0;
		
		if (T[i].p == NIL)
			printf("root\n");
		else if (T[i].lc == NIL && T[i].rc == NIL)
			printf("leaf\n");
		else printf("internal node\n");
	
	}
	
	return 0;
}
