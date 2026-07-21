#include<stdio.h>
#define MAX 25
#define NIL -1
struct tree {
        int parent;
        int left;
        int right;
};

void depth(int, int, struct tree*, int*);
int height(int, struct tree*, int*);
void disp(int, struct tree*, int*, int*);
main()
{
        struct tree t[MAX];
        int i, j, n, id, l, r, prec, root, d[MAX], h[MAX];
        scanf("%d", &n);
        for (i = 0; i < n; i++) {
                t[i].parent = NIL;
        }
    for(i = 0; i < n; i++) {
        scanf("%d %d %d", &id, &l, &r);
        t[id].left = l;
                t[id].right = r;
                if (l != -1) {
                        t[l].parent = id;
                }
                if (r != -1) {
                        t[r].parent = id;
                }
    }
    for (i = 0; i < n; i++) {
        if(t[i].parent == NIL) {
                        root = i;
                        break;
                }
        }
        depth(root, 0, t, d);
        height(root, t, h);
        for (i = 0; i < n ; i++) {
                disp(i, t, d, h);
        }
}
void depth(int u, int p, struct tree *t, int *d)
{
        d[u] = p;
        if (t[u].right != NIL) {
                depth(t[u].right, p + 1, t, d);
        }
        if (t[u].left != NIL) {
        depth(t[u].left, p + 1, t, d);
    }
}
int height(int u, struct tree *t, int *h)
{
        int h1 = 0, h2 = 0;
        if (t[u].right != NIL) {
        h1 = height(t[u].right, t, h) + 1;
    }
    if (t[u].left != NIL) {
        h2 = height(t[u].left, t, h) + 1;
    }
        return h[u] = (h1 > h2 ? h1 : h2);
}
void disp(int u, struct tree *t, int *d, int *h)
{
        int deg = 0;
        printf("node %d: parent = %d, ", u, t[u].parent);
        if (t[u].parent == NIL) {
                printf("sibling = -1, ");
        } else if (t[t[u].parent].left == u) {
                printf("sibling = %d, ", t[t[u].parent].right);
        } else {
                printf("sibling = %d, ", t[t[u].parent].left);
        }
        if (t[u].left != NIL) {
                deg++;
        }
        if (t[u].right != NIL) {
        deg++;
    }
        printf("degree = %d, depth = %d, height = %d, ", deg, d[u], h[u]);
        if (t[u].parent == NIL) {
                printf("root\n");
        } else if (t[u].left != NIL || t[u].right != NIL) {
                printf("internal node\n");
        } else {
                printf("leaf\n");
        }
}
