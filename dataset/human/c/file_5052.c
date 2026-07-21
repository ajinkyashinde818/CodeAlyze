/* ALDS1_7_B: Binary Tree */
/* 20181124 AOJ */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define N 25
#define NIL -1

typedef struct {
	int parent;
	int left;
	int right;
	int sibling;
	int childNum;
	int depth;
	int height;
} Tree;

void depthCal(Tree *node, int id, int depth);
int heightCal(Tree *node, int id);
void printTree(Tree *node, int n);

int main(void) {
	Tree *node = (Tree *)malloc(sizeof(Tree) * N);
	int i, n, id, left, right, root;

	scanf("%d", &n);

	for(i = 0; i < n; i++) {
		node[i].parent = NIL;
		node[i].sibling = NIL;
		node[i].childNum = 0;
	}

	for(i = 0; i < n; i++) {
		scanf("%d %d %d", &id, &left, &right);
		node[id].left = left;
		node[id].right = right;
		if(left != NIL) {
			node[left].parent = id;
			node[left].sibling = right;
			node[id].childNum++;
		}
		if(right != NIL) {
			node[right].parent = id;
			node[right].sibling = left;
			node[id].childNum++;
		}
	}

	for(i = 0; i < n; i++) {
		if(node[i].parent == NIL) {
			root = i;
			break;
		} 
	}

	depthCal(node, root, 0);
	heightCal(node, root);
	printTree(node, n);

	return 0;
}

void depthCal(Tree *node, int id, int depth) {
	if(id == NIL) return;
	node[id].depth = depth;
	depthCal(node, node[id].left, depth + 1);
	depthCal(node, node[id].right, depth + 1);
}

int heightCal(Tree *node, int id) {
	int h1 = 0, h2 = 0;

	if(node[id].left != NIL)
		h1 = heightCal(node, node[id].left) + 1;
	if(node[id].right != NIL)
		h2 = heightCal(node, node[id].right) + 1;

	node[id].height = h1 > h2 ? h1 : h2;

	return node[id].height;
}

void printTree(Tree *node, int n) {
	int id = 0, i = 0, child;
	
	while(id < n) {
		printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ", 
			id, node[id].parent, node[id].sibling, node[id].childNum, node[id].depth, node[id].height);

		if(node[id].parent == NIL) {
			printf("root\n");
		} else if(node[id].childNum == 0) { /* node[id].left == NIL*/
			printf("leaf\n");
		} else {
			printf("internal node\n");
		}

		id++;
	}

}
