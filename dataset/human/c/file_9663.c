#include<stdio.h>
#include<stdlib.h>
const int NIL = -1;
const int MAXSIZE = 100000 + 2;
struct Node {
	int parent, left, right;
};
Node Tree[MAXSIZE];
int Depth[MAXSIZE];
void Get_depth(int node_id, int depth) {
	Depth[node_id] = depth;
	if (Tree[node_id].right != NIL)	Get_depth(Tree[node_id].right, depth);
	if (Tree[node_id].left != NIL)	Get_depth( Tree[node_id].left, depth + 1);
}
void Print(int node_id) {
	printf("node %d: ", node_id);
	printf("parent = %d, ", Tree[node_id].parent);
	printf("depth = %d, ", Depth[node_id]);
	if (Tree[node_id].parent == NIL)	printf("root, ");
	else if (Tree[node_id].left == NIL)	printf("leaf, ");
	else printf("internal node, ");

	printf("[");
	for (int i = 0, c = Tree[node_id].left; c != NIL; c = Tree[c].right, i++) {
		if (i) printf(", ");
		printf("%d", c);
	}
	printf("]\n");
}
int main() {
	int num_node = 0;
	int parent_id= 0, out_connect = 0;
	scanf("%d", &num_node);
	for (int i = 0; i < num_node; i++) {
		Tree[i].right = Tree[i].left = Tree[i].parent = NIL;
	}
	for (int i = 0; i < num_node; i++) {
		int c = 0;
		int son_tree;
		scanf("%d %d", &parent_id, &out_connect);
		for (int j = 0; j < out_connect; j++) {
			scanf("%d", &c);
			if (j == 0) Tree[parent_id].left = c;
			else 	Tree[son_tree].right = c;
			son_tree = c;
			Tree[c].parent = parent_id;
		}
	}
	int root_id = -1;
	for (int i = 0; i < num_node; i++) {
		if (Tree[i].parent == NIL) {
			root_id = i;
		}
	}
	Get_depth(root_id, 0);
	for (int i = 0; i < num_node; i++) {
		Print(i);
	}

	return 0;
}
