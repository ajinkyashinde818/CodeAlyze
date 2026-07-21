#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define MAX 100005
#define NIL -1

/*
p: parent
l: left-child
r: right sibling
*/
struct Node{ int p, l, r; };
struct Node T[MAX]; // Tree

int depth(int u){
	int d = 0;
	if (T[u].p == -1){ return 0; }
	return 1 + depth(T[u].p);
}

int height(int u){
	int l = 0, r = 0;
	if (T[u].l != -1){
		l += height(T[u].l);
		l++;
	}
	if (T[u].r != -1){
		r += height(T[u].r);
		r++;
	}
	return l <= r ? r:l;
}

void print(int u){
	printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, %s\n"
		, u
		, T[u].p
		, T[u].p == -1 || T[T[u].p].l == -1 || T[T[u].p].r == -1 ? -1 : (T[T[u].p].l != -1 && T[T[u].p].l != u ? T[T[u].p].l : T[T[u].p].r)
		, T[u].l == -1 && T[u].r == -1 ? 0 : (T[u].l != -1 && T[u].r != -1 ? 2 : 1)
		, depth(u)
		, height(u)
		, T[u].p == -1 ? "root" : (T[u].l == -1 && T[u].r == -1 ? "leaf" : "internal node")
		);
}

main(){
	int i, d, v, c, n;

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		T[i].p = T[i].l = T[i].r = NIL;
	}

	for (i = 0; i < n; i++){
		scanf("%d %d %d", &v, &d, &c);
		T[v].l = d;
		T[v].r = c;
		T[d].p = T[c].p = v;
	}
	for (i = 0; i < n; i++) print(i);
	return 0;
}
