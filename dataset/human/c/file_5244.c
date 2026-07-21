#include <stdio.h>

#define NIL -1
#define N 25

typedef struct node {
    int p,l,r;
} Node;

Node T[N];

int getDegree(int id) {
    if (T[id].l != NIL && T[id].r != NIL) return 2;
    if (T[id].r != NIL) return 1;
	if (T[id].l != NIL) return 1;

    return 0;
}

int getSib(int id) {
    if (T[id].p == NIL) return NIL;

    if (T[T[id].p].l != id) return T[T[id].p].l;
    return T[T[id].p].r;
}

int getDepth(int id) {
    int depth = 1;

    if (T[id].p == NIL) return 0;
    depth += getDepth(T[id].p);
    return depth;
}

int getHeight(int id) {
    int height = 1;
    int r,l;

    if (T[id].l == -1 && T[id].r == -1)
        return 0;

    if (T[id].l == -1)
        height += getHeight(T[id].r);
    else if (T[id].r == -1)
        height += getHeight(T[id].l);
    else {
        r = getHeight(T[id].r);
        l = getHeight(T[id].l);
        if (r >= l) height += r;
        else height += l;
    }

    return height;
}

int main() {
    int i,j,n;
    int id,l,r;

    scanf("%d",&n);

    for (i = 0; i < n; i++)
        T[i].p = NIL;
    for (i = 0; i < n; i++) {
        scanf("%d %d %d",&id,&l,&r);
        T[id].l = l;
        T[id].r = r;
        if (l != NIL) T[l].p = id;
        if (r != NIL) T[r].p = id;
    }

    for (i = 0; i < n; i++) {
        printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d,",i,T[i].p, getSib(i), getDegree(i), getDepth(i), getHeight(i));
        if (T[i].p == NIL) printf(" root\n");
        else if (T[i].l != NIL) printf(" internal node\n");
		else if (T[i].r != NIL) printf(" internal node\n");
        else printf(" leaf\n");
    }
    return 0;
}
