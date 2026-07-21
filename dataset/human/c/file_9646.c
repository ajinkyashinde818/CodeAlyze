#include <stdio.h>

#define debug  
#define NMAX 100010
#define NIL -1

int left[NMAX];
int right[NMAX];
int parent[NMAX];
int depth[NMAX];

void setDepth(int i, int d) {
    debug("setDepth %d %d\n", i, d);
    if (i == NIL) {
        return;
    }
    depth[i] = d;
    setDepth(left[i], d + 1);
    setDepth(right[i], d);
}

int main() {
    int n, k, id, prev, x;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        parent[i] = NIL;
        left[i] = NIL;
        right[i] = NIL;
    }
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &id, &k);
        for (int j = 0; j < k; j++) {
            scanf("%d", &x);
            parent[x] = id;
            if (j == 0) {
                left[id] = x;
            } else {
                right[prev] = x;
            }
            prev = x;
        }
    }
    int root = 0;
    for (int i = 0; i < n; i++) {
        if (parent[i] == NIL) {
            root = i;
            break;
        }
    }
    setDepth(root, 0);
    for (int i = 0; i < n; i++) {
        printf("node %d: ", i);
        printf("parent = %d, ", parent[i]);
        printf("depth = %d, ", depth[i]);
        if (parent[i] == NIL) {
            printf("root, ");
        } else if (left[i] == NIL) {
            printf("leaf, ");
        } else {
            printf("internal node, ");
        }
        printf("[");
        k = left[i];
        while (k!=NIL) {
            printf("%d", k);
            if (right[k] != NIL) {
                printf(", ");
            }
            k = right[k];
        }
        printf("]\n");
    }

    return 0;
}
