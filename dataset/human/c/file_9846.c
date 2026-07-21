#include <stdio.h>

#define MAX 100001
#define NIL -1

typedef struct Node_ {
    int parent;
    int leftChild;
    int rightSibling;
} Node;

static Node Tree[MAX];
int Depth[MAX];

static void setDepth(int i, int depth)
{
    Depth[i] = depth;
    if (Tree[i].leftChild != NIL) {
        setDepth(Tree[i].leftChild, depth + 1);
    }
    if (Tree[i].rightSibling != NIL) {
        setDepth(Tree[i].rightSibling, depth);
    }
}

static void printNode(int i)
{
    printf("node %d: parent = %d, depth = %d, ", i, Tree[i].parent, Depth[i]);

    if (Tree[i].parent == NIL) {
        printf("root, ");
    } else if (Tree[i].leftChild == NIL) {
        printf("leaf, ");
    } else {
        printf("internal node, ");
    }

    printf("[");
    int child = Tree[i].leftChild;
    for (int j = 0; child != NIL; j++) {
        if (j > 0) {
            printf(", ");
        }
        printf("%d", child);
        child = Tree[child].rightSibling;
    }
    printf("]\n");
}

int main()
{
    int n;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        Tree[i].parent = Tree[i].leftChild = Tree[i].rightSibling = NIL;
    }

    for (int i = 0; i < n; i++) {
        int id, k;
        int l = 0;
        scanf("%d %d", &id, &k);
        for (int j = 0; j < k; j++) {
            int c;
            scanf("%d", &c);
            if (j == 0) {
                Tree[id].leftChild = c;
            } else {
                Tree[l].rightSibling = c;
            }
            Tree[c].parent = id;
            l = c;
        }
    }

    int root = 0;

    for (int i = 0; i < n; i++) {
        if (Tree[i].parent == NIL) {
            root = i;
            break;
        }
    }

    setDepth(root, 0);

    for (int i = 0; i < n; i++) {
        printNode(i);
    }

    return 0;
}
