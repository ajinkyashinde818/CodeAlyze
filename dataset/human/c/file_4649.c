#include <stdio.h>

#define MAX 25

typedef struct {
	int parent;
	int left;
	int right;
	int s;
	int deg;
	int dep;
	int h;
} node;

int dep(int);
int h(int);
int max(int, int);

node u[MAX];

int main(void)
{
	int i, n, id, left, right;
	
	scanf("%d",&n);
	for (id=0; id<n; id++) {
		u[id].parent = u[id].s = u[id].dep = u[id].h = -1;
		u[id].deg = 0;
	}
	for (i=0; i<n; i++) {
		scanf("%d %d %d", &id, &left, &right);
		u[id].left = left;
		u[id].right = right;
		if(left != -1) {
			u[left].parent = id;
			u[left].s = right;
			u[id].deg++;
		}
		if(right != -1) {
			u[right].parent = id;
			u[right].s = left;
			u[id].deg++;
		}
	}
	
	for (id=0; id<n; id++) {
		printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ",
			id, u[id].parent, u[id].s, u[id].deg, dep(id), h(id) );
		if(u[id].parent == -1) {
			printf("root\n");
		} else if(u[id].deg == 0) {
			printf("leaf\n");
		} else {
			printf("internal node\n");
		}
	}
	 
	return 0;
}

int dep(int id)
{
	if(u[id].dep!=-1) {
		return u[id].dep;
	}
	if(u[id].parent == -1) {
		u[id].dep = 0;
		return 0;
	}
	u[id].dep = dep(u[id].parent) + 1;
	return u[id].dep;
}

int h(int id)
{
	if(u[id].h!=-1) {
		return u[id].h;
	}
	if(u[id].left == -1 && u[id].right == -1) {
		u[id].h = 0;
	} else if(u[id].left == -1) {
		u[id].h = h(u[id].right) + 1;
	} else if(u[id].right == -1) {
		u[id].h = h(u[id].left) + 1;
	} else {
		u[id].h = max( h(u[id].left), h(u[id].right) ) + 1;
	}
	return u[id].h;
}

int max(int a, int b)
{
	if(a>b) return a;
	else return b;
}
