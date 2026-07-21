#include <stdio.h>

#define MAX 100000

typedef struct node_t {
	int depth;
	int parent;
	int left;
	int right;
} node;

node u[MAX];

int d(int);

int main(void)
{
	int i, j, n, id, k, c1, c2;
	
	scanf("%d",&n);
	
	for (id=0; id<n; id++) {
		u[id].depth = u[id].parent = u[id].right = -1;
	}
	
	for (i=0; i<n; i++) {
		scanf("%d %d", &id, &k);
		if(k==0) {
			u[id].left = -1;
		} else {
			for (j=0; j<k; j++) {
				if(j==0) {
					scanf("%d", &c1);
					u[id].left = c1;
					u[c1].parent = id;
				} else {
					scanf("%d", &c2);
					u[c2].parent = id;
					u[c1].right = c2;
					c1 = c2;
				}
			}
		}
	}
	
	for (id=0; id<n; id++) {
		printf("node %d: parent = %d, depth = %d, ", id, u[id].parent, d(id));
		if(u[id].parent == -1) {
			printf("root, [");
		} else if(u[id].left == -1) {
			printf("leaf, [");
		} else {
			printf("internal node, [");
		}
		c1 = u[id].left;
		if(c1 != -1) {
			while (1) {
				c2 = u[c1].right;
				if (c2 == -1) {
					printf("%d",c1);
					break;
				} else {
					printf("%d, ",c1);
					c1 = c2;
				}
			}
		}
		printf("]\n");
	}
	
	return 0;
}

int d(int id)
{
	if(u[id].depth!=-1) {
		return u[id].depth;
	}
	if(u[id].parent == -1) {
		u[id].depth = 0;
		return 0;
	}
	u[id].depth = d(u[id].parent) + 1;
	return u[id].depth;
}
