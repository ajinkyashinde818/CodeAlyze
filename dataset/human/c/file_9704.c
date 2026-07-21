#include<stdio.h>
#include<string.h>
#define MAX 100000

struct NODE {
	int parent;
	int childL;
	int siblingR;
};

struct NODE Tree[MAX];

int Dep(int id) {
	int cnt = 0;
	for (int i = id; Tree[i].parent != -1; i = Tree[i].parent) {
		cnt++;
	}
	return cnt;
}


int main() {
	int N;
	int id, deg;
	int child, childR;
	char type[30];
	for (int i = 0; i < MAX; i++) {
		Tree[i].parent = -1; Tree[i].childL = -1; Tree[i].siblingR = -1;
	}
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &id, &deg);
		for (int j = 0; j < deg; j++) {
			if (j == 0) {
				scanf("%d", &child);
				Tree[id].childL = child;
				Tree[child].parent = id;
			}
			else {
				scanf("%d", &childR);
				Tree[child].siblingR = childR;
				Tree[childR].parent = id;
				child = childR;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		if (Tree[i].parent == -1)strcpy(type, "root");
		else if (Tree[i].childL == -1)strcpy(type, "leaf");
		else strcpy(type, "internal node");
		printf("node %d: parent = %d, depth = %d, %s, [", i, Tree[i].parent, Dep(i), type);
		for (int j = Tree[i].childL; j != -1; j = Tree[j].siblingR) {
			printf("%d", j);
			if (Tree[j].siblingR != -1)printf(", ");
		}
		printf("]\n");
	}

	return 0;
}
