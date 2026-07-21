#include <stdio.h>

#define MAX 100005
#define NIL -1

typedef struct {
    int parent;
    int left;
    int right;
} Node;

Node T[MAX];
int n;

void printChildren(int u) {
    int c = T[u].left;
    while (c != NIL) {
        printf("%d", c);
        c = T[c].right;
        if (c != NIL) printf(", ");
    }
}

void printLocation(int u) {
    if (T[u].parent == NIL) printf("root, ");
    else if (T[u].left == NIL) printf("leaf, ");
    else printf("internal node, ");
}

void printDepth(int u) {
    int depth = 0;
    while (T[u].parent != NIL) {
        u = T[u].parent;
        depth++;
    }

    printf("depth = %d, ", depth);
}

void printParent(int u) {
    printf("parent = %d, ", T[u].parent);
}

void printNodeID(int u) {
    printf("node %d: ", u);
}

void printTree(int u) {
    printNodeID(u);
    printParent(u);
    printDepth(u);
    printLocation(u);
    printf("[");
    printChildren(u);
    printf("]\n");
}

int main() {
    /// count of nodes
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        T[i].parent = NIL;
        T[i].left = NIL;
        T[i].right = NIL;
    }

    int id, degree, c, l;
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &id, &degree);

        for (int j = 0; j < degree; j++) {
            scanf("%d", &c);

            if (j) T[l].right = c;
            else T[id].left = c;
            T[c].parent = id;

            l = c;
        }
    }

    for (int i = 0; i < n; i++) {
        printTree(i);
    }

    return 0;
}
