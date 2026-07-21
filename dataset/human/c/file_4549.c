#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <string>
#pragma warning(disable : 4996)

#define MAX_N 25

struct Node {
	int id;
	int parent;
	int left;
	int right;
	int depth;
	int hight;
	Node() : id(-1), parent(-1), depth(-1), left(-1), right(-1), hight(-1) {}
};

Node nodes[MAX_N];

Node *GetRoot(int n) {
	for (int i = 0; i < n; ++i) {
		if (nodes[i].parent == -1) {
			return &nodes[i];
		}
	}
	return NULL;
}
int CalcDHr(Node *n, int depth) {
	n->depth = depth;
	int md = n->depth;
	if (n->left != -1) {
		Node *l = &nodes[n->left];
		int cd = CalcDHr(l, depth+1);
		if (md < cd) md = cd;
	}
	if (n->right != -1) {
		Node *r = &nodes[n->right];
		int cd = CalcDHr(r, depth+1);
		if (md < cd) md = cd;
	}
	n->hight = md - n->depth;
	return md;
}
void CalcDH(int n) {
	Node *root = GetRoot(n);
	CalcDHr(root, 0);
}

int main(void) {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int id;
		int left;
		int right;
		scanf("%d %d %d", &id, &left, &right);
		nodes[id].id = id;
		nodes[id].left = left;
		if (left >= 0) {
			nodes[left].parent = id;
		}
		nodes[id].right = right;
		if (right >= 0) {
			nodes[right].parent = id;
		}
	}
	CalcDH(n);
	for (int i = 0; i < n; ++i) {
		Node n = nodes[i];
		int s = -1;
		int dig = 0;
		if (n.parent != -1) {
			Node p = nodes[n.parent];
			if ((p.left != -1) && (p.left != n.id)) s = p.left;
			if ((p.right != -1) && (p.right != n.id)) s = p.right;
		}
		if (n.left != -1) ++dig;
		if (n.right != -1) ++dig;
		const char *type = "internal node";
		if (n.parent == -1) type = "root";
		else if (dig == 0) type = "leaf";
		printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, %s\n", n.id, n.parent, s, dig, n.depth, n.hight, type);
	}
	return 0;
}
