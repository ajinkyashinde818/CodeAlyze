#include <stdio.h>
#define MAX 100005
#define NIL -1

struct Node {
    int parent, left, right;
};

struct Node Tree[MAX];
int n, D[MAX], H[MAX];

void setDepth (int u, int d) {
    if (u == NIL) return;
    D[u] = d;
    setDepth(Tree[u].left, d + 1);
    setDepth(Tree[u].right, d + 1);
}

int setHeight (int u) {
    int h1 = 0, h2 = 0;
    if (Tree[u].left != NIL) h1 = setHeight(Tree[u].left) + 1;
    if (Tree[u].right != NIL) h2 = setHeight(Tree[u].right) + 1;
    return H[u] = (h1 > h2 ? h1 : h2);
}

int getSibling (int u) {
    if (Tree[u].parent == NIL) return NIL;
    if (Tree[Tree[u].parent].left != NIL && Tree[Tree[u].parent].left != u) return Tree[Tree[u].parent].left;
    if (Tree[Tree[u].parent].right != NIL && Tree[Tree[u].parent].right != u) return Tree[Tree[u].parent].right;
    return NIL;
}

void print (int u) {
    printf("node %d: ",u);
    printf("parent = %d, ",Tree[u].parent);
    printf("sibling = %d, ",getSibling(u));
    int deg = 0;
    if (Tree[u].left != NIL) deg++;
    if (Tree[u].right != NIL) deg++;
    printf("degree = %d, ",deg);
    printf("depth = %d, ",D[u]);
    printf("height = %d, ",H[u]);
    if ( Tree[u].parent == NIL) printf("root\n");
    else if ( Tree[u].left == NIL && Tree[u].right == NIL) printf("leaf\n");
    else printf ("internal node\n");
}

int main () {
    int i;
    int v,l,r, root = 0;
    scanf("%d",&n);

    for ( i = 0; i < n; i++) Tree[i].parent = Tree[i].parent = NIL;

    for ( i = 0; i < n; i++) {
        scanf("%d%d%d",&v,&l,&r);
        Tree[v].left = l;
        Tree[v].right = r;
        if (l != NIL) Tree[l].parent = v;
        if (r != NIL) Tree[r].parent = v;
    }

    for (i = 0; i < n; i++) if (Tree[i].parent == NIL) root = i;
    setDepth(root, 0);
    setHeight(root);

    for (i = 0; i < n; i++) print(i);
    return 0;
}
