#include<stdio.h>
#include<string.h>
#define MAX 30

struct NODE { int parent, left, right; };
struct NODE BTree[MAX];

int Degree(int id) {
	if (BTree[id].left != -1 && BTree[id].right != -1)
		return 2;
	else if (BTree[id].left == -1 && BTree[id].right != -1)
		return 1;
	else if (BTree[id].left != -1 && BTree[id].right == -1)
		return 1;
	else return 0;
}

int Sibling(int id) {
	if (BTree[id].parent == -1) {
		return -1;
	}
	else if (BTree[BTree[id].parent].left == id) {
		return BTree[BTree[id].parent].right;
	}
	else return BTree[BTree[id].parent].left;
}


int Dep(int id) {
	int cnt = -1;
	while (id != -1) {
		id = BTree[id].parent;
		cnt++;
	}
	return cnt;
}

int Height(int id) {
	if (BTree[id].left == -1 && BTree[id].right == -1)
		return 0;
	else if (BTree[id].left == -1 && BTree[id].right != -1)
		return Height(BTree[id].right) + 1;
	else if (BTree[id].left != -1 && BTree[id].right == -1)
		return Height(BTree[id].left) + 1;
	else if (BTree[id].left != -1 && BTree[id].right != -1) {
		if (Height(BTree[id].right) >= Height(BTree[id].left))
			return Height(BTree[id].right) + 1;
		else return Height(BTree[id].left) + 1;
	}
}


int main() {
	int N;
	int num, l, r;
	char type[30];
	for (int i = 0; i < MAX; i++) {
		BTree[i].parent = -1;
		BTree[i].left = -1;
		BTree[i].right = -1;
	}
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d %d", &num, &l, &r);
		if (l != -1) {
			BTree[num].left = l;
			BTree[l].parent = num;
		}
		if (r != -1) {
			BTree[num].right = r;
			BTree[r].parent = num;
		}
	}

	for (int i = 0; i < N; i++) {
		if (BTree[i].parent == -1)strcpy(type,"root");
		else if (BTree[i].left == -1 && BTree[i].right == -1)strcpy(type, "leaf");
		else strcpy(type, "internal node");
		printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, %s\n", i, BTree[i].parent, Sibling(i), Degree(i), Dep(i), Height(i),type);
	}

	return 0;
}
