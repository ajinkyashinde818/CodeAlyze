#include<stdio.h>

#define MAX 25
struct node{
	int parent, left, right;
};

node T[MAX];
int D[MAX], H[MAX];

void setDepth(const int t, const int d){
	if (t == -1) return;
	D[t] = d;
	setDepth(T[t].right, d + 1);
	setDepth(T[t].left, d + 1);
}

int setHeight(const int t){
	int h1 = 0, h2 = 0;
	if (T[t].right != -1){
		h1 = setHeight(T[t].right) + 1;
	}
	if (T[t].left != -1){
		h2 = setHeight(T[t].left) + 1;
	}
	return H[t] = (h1 > h2 ? h1 : h2);
}

void output(const int t){
	int deg = 0;
	if (T[t].right != -1) deg++;
	if (T[t].left != -1) deg++;
	int sib = -1;
	int p = T[t].parent;
	if (p != -1){
		if (T[p].right != t) sib = T[p].right;
		else sib = T[p].left;
	}
	printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ",
				t, p, sib, deg, D[t], H[t]);
	if (p == -1) printf("root\n");
	else if (H[t] == 0) printf("leaf\n");
	else printf("internal node\n");
}

int main(){
	int n;
	scanf("%d", &n);
	for (int i = 0; i< n; i++) {
		T[i].left = -1;
		T[i].right = -1;
		T[i].parent = -1;
	}
	for (int i = 0; i < n; i++){
		int t, l, r;
		scanf("%d %d %d", &t, &l, &r);
		T[t].left = l;
		T[t].right = r;
		if (l != -1) T[l].parent = t;
		if (r != -1) T[r].parent = t;
	}
	int root = 0;
	for (int i = 0; i < n; i++){
		if (T[i].parent == -1) {
		    root = i;
		    break;
		}
	}
	setDepth(root, 0);
	setHeight(root);

	for (int i = 0; i < n; i++) output(i);
}
