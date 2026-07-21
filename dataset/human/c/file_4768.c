#include <stdio.h>

#define MAX 10000
#define NIL -1

struct Node {
    int p, left, right;
};

struct Node T[MAX];
int n, D[MAX], H[MAX];

void depth(int, int);
int height(int);
int sibling(int);
void printree(int);

int main() {
    int i, v, l, r, root = 0;
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        T[i].p = NIL;
    }

    for (i = 0; i < n; i++) {
        scanf("%d%d%d", &v, &l, &r);
        T[v].left = l;
        T[v].right = r;
        if (l != NIL) T[l].p = v;
        if (r != NIL) T[r].p = v;
    }

    for (i = 0; i < n; i++) {
        if (T[i].p == NIL) root = i;
    }
    depth(root, 0);
    height(root);

    for (i = 0; i < n; i++) printree(i);

    return 0;
}


void depth(int u, int d) {
    if (u == NIL) return;
    D[u] = d;
    depth(T[u].left, d+1);
    depth(T[u].right, d+1);
}


int height(int u) {
    int h1 = 0, h2 = 0;
    if (T[u].left != NIL) h1 = height(T[u].left) + 1;
    if (T[u].right != NIL) h2 = height(T[u].right) +1;
    return H[u] = (h1 > h2 ? h1 : h2);
}


int sibling(int u) {
    if (T[u].p == NIL) return NIL;
    if (T[T[u].p].left != u && T[T[u].p].left != NIL) return T[T[u].p].left;
    if (T[T[u].p].right != u && T[T[u].p].right != NIL) return T[T[u].p].right;
    return NIL;
}


void printree(int u) {
    int deg = 0;

    printf("node %d: ", u);
    printf("parent = %d, ", T[u].p);
    printf("sibling = %d, ", sibling(u));

    if (T[u].left != NIL) deg++;
    if (T[u].right != NIL) deg++;

    printf("degree = %d, ", deg);
    printf("depth = %d, ", D[u]);
    printf("height = %d, ", H[u]);

    if (T[u].p == NIL) printf("root\n");
    else if (T[u].left == NIL && T[u].right == NIL) printf("leaf\n");
    else printf("internal node\n");

}
