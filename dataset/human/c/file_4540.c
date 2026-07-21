#include <stdio.h>

#define debug
#define NMAX 100010
#define NIL -1

int L[NMAX];
int R[NMAX];
int P[NMAX];
int D[NMAX];
int H[NMAX];

void setDepth(int i, int d) {
    if (i == NIL) {
        return;
    }
    D[i] = d;
    setDepth(L[i], d + 1);
    setDepth(R[i], d + 1);
}

int setHeight(int i) {
    int h1 = 0, h2 = 0;
    if (L[i] != NIL) {
        h1 = 1 + setHeight(L[i]);
    }
    if (R[i] != NIL) {
        h2 = 1 + setHeight(R[i]);
    }
    H[i] = (h1 > h2 ? h1 : h2);
    return H[i];
}

int main() {
    int n, id, left, right;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        P[i] = NIL;
        L[i] = NIL;
        R[i] = NIL;
    }
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &id, &left, &right);
        if (left != NIL) {
            L[id] = left;
            P[left] = id;
        }
        if (right != NIL) {
            R[id] = right;
            P[right] = id;
        }
    }
    int root = 0;
    for (int i = 0; i < n; i++) {
        if (P[i] == NIL) {
            root = i;
            break;
        }
    }
    setDepth(root, 0);
    setHeight(root);
    for (int i = 0; i < n; i++) {
        printf("node %d: ", i);
        printf("parent = %d, ", P[i]);
        if (P[i] != NIL) {
            printf("sibling = %d, ", R[P[i]] == i ? L[P[i]] : R[P[i]]);
        } else {
            printf("sibling = -1, ");
        }
        int cnt = 0;
        if (L[i] != NIL)
            cnt++;
        if (R[i] != NIL)
            cnt++;
        printf("degree = %d, ", cnt);
        printf("depth = %d, ", D[i]);
        printf("height = %d, ", H[i]);
        if (P[i] == NIL) {
            printf("root");
        } else if (L[i] == NIL && R[i] == NIL) {
            printf("leaf");
        } else {
            printf("internal node");
        }
        printf("\n");
    }

    return 0;
}
