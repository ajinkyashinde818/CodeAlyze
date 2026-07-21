#include <stdio.h>
#include <stdio.h>

typedef struct _element {
	int p;
	int l;
	int r;
} element;

#define MAX 100005
#define NIL -1

element A[MAX];
int cache[MAX];

const char mes[3][20] = {
	"root",
	"internal node",
	"leaf"
};

int get_height(int i) {
	if(cache[i] != NIL) return cache[i];

	if(A[i].r == NIL && A[i].l == NIL) return cache[i] = 0;
	
	if(A[i].r != NIL) {
		cache[A[i].r] = get_height(A[i].r);
		if(A[i].l == NIL) {
			return cache[i] = cache[A[i].r] + 1;
		}
	}
	if(A[i].l != NIL) {
		cache[A[i].l] = get_height(A[i].l);
		if(A[i].r == NIL) {
			return cache[i] = cache[A[i].l] + 1;
		}
	}
	
	if(cache[A[i].r] > cache[A[i].l]) {
		return cache[i] = cache[A[i].r] + 1;
	} else {
		return cache[i] = cache[A[i].l] + 1;
	}
}

void print(int i) {
	int parent = A[i].p;	// parent
	int sibling = NIL; // sibling -> A[A[i].p].r or A[A[i].p].l
	int degree = 0;	// exists A[i].l, A[i].r
	int depth = 0;	// while A[A[i].p] == NIL depth ++
	int height = 0;	// f(n)
	int type = 2;	// 0:root 1:internal node 2:leaf
	int t = A[i].p;
	
	if(parent != NIL)
		if(A[parent].l == i)
			sibling = A[parent].r;
		else
			sibling = A[parent].l;
	
	if(A[i].l != NIL) degree++;
	if(A[i].r != NIL) degree++;
	
	while(t!=NIL) {
		depth ++;
		t = A[t].p;
	}
	
	height = get_height(i);
	
	if(A[i].p == NIL) {
		type = 0;
	} else if(height > 0) {
		type = 1;
	}
	
	printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, %s\n", i, parent, sibling, degree, depth, height, mes[type]);
}

int main(void) {
	int n,r,l,i,m;
	
	scanf("%d\n", &n);
	for(i=0;i<n;i++) {
		A[i].p = NIL;
	}	
	
	for(i=0;i<n;i++) {
		scanf("%d %d %d\n", &m, &l, &r);
		A[m].l = l;
		A[m].r = r;
		if(l != NIL) A[l].p = m;
		if(r != NIL) A[r].p = m;
		cache[m] = NIL;
	}
	
	for(i=0;i<n;i++)
		if(A[i].p == NIL) 
			get_height(i);

	for(i=0;i<n;i++) print(i);
	
	return 0;
}
