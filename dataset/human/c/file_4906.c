#include <stdio.h>
#define NIL -1
#define MAX_N 30
typedef struct node_ {
    int parent;
    int left;
    int right;
} Node;
 
Node T[MAX_N];
int D[MAX_N], H[MAX_N];
 
void setDepth(int u, int d) {
    if (u == NIL) return;
    D[u] = d;
    setDepth(T[u].left, d+1);
    setDepth(T[u].right, d+1);
}
 
int setHeight(int u) {
    int h1 = 0, h2 = 0;
    if (T[u].left != NIL) {
        h1 = setHeight(T[u].left) + 1;
    }
    if (T[u].right != NIL) {
        h2 = setHeight(T[u].right) + 1;
    }
 
    if (h1 >= h2) {
        return H[u] = h1;
    } else {
        return H[u] = h2;
    }
}
 
int getSibling(int u) {
    if (T[u].parent == NIL) return NIL;
    if (T[T[u].parent].left != u && T[T[u].parent].left != NIL) {
        return T[T[u].parent].left;
    }
    if (T[T[u].parent].right != u && T[T[u].parent].right != NIL) {
        return T[T[u].parent].right;
    }
    return NIL;
}
 
void print(int u) {
    printf("node %d: ", u);
    printf("parent = %d, ", T[u].parent);
    printf("sibling = %d, ", getSibling(u));
 
    int deg = 0;
    if (T[u].left != NIL) deg++;
    if (T[u].right != NIL) deg++;
    printf("degree = %d, ", deg);
 
    printf("depth = %d, ", D[u]);
    printf("height = %d, ", H[u]);
 
    if (T[u].parent == NIL) {
        printf("root\n");
    } else if (T[u].left == NIL && T[u].right == NIL) {
        printf("leaf\n");
    } else {
        printf("internal node\n");
    }
}
 
int main(void) {
    int i, n;
    scanf("%d", &n);
    for (i = 0; i < MAX_N; i++) {
        T[i].parent = NIL;
        T[i].left = NIL;
        T[i].right = NIL;
    }
 
    for (i = 0; i < n; i++) {
        int id, left, right;
        scanf("%d %d %d", &id, &left, &right);
        T[id].left = left;
        T[id].right = right;
        if (left != NIL) T[left].parent = id;
        if (right != NIL) T[right].parent = id;
    }
 
    int r;
    for (i = 0; i < n; i++) {
        if (T[i].parent == NIL) r = i;
    }
 
    setDepth(r, 0);
    setHeight(r);
 
    for (i = 0; i < n; i++) {
        print(i);
    }
 
    return 0;
}
