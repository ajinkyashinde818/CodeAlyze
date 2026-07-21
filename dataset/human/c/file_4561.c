#include <stdio.h>

#define MAX 25
#define NIL -1

typedef struct Node_
{
    int parent;
    int left;
    int right;
} Node;

static Node Tree[MAX];
static int Depth[MAX];
static int Height[MAX];

static void setDepth(int i, int depth)
{
    if (i == NIL)
        return;
    Depth[i] = depth;
    setDepth(Tree[i].left, depth + 1);
    setDepth(Tree[i].right, depth + 1);
}

static int setHeight(int i)
{
    int h1 = 0;
    int h2 = 0;

    if (Tree[i].left != NIL)
        h1 = setHeight(Tree[i].left) + 1;
    if (Tree[i].right != NIL)
        h2 = setHeight(Tree[i].right) + 1;

    Height[i] = (h1 > h2) ? h1 : h2;
    return Height[i];
}

static int getSibling(int i)
{
    if (Tree[i].parent == NIL)
        return NIL;

    int left = Tree[Tree[i].parent].left;
    if (left != i && left != NIL)
        return left;

    int right = Tree[Tree[i].parent].right;
    if (right != i && right != NIL)
        return right;

    return NIL;
}

static void printNode(int i)
{
    int degree = 0;
    if (Tree[i].left != NIL)
        degree++;
    if (Tree[i].right != NIL)
        degree++;

    printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ", i, Tree[i].parent, getSibling(i), degree, Depth[i], Height[i]);

    if (Tree[i].parent == NIL) {
        printf("root\n");
    } else if (Tree[i].left == NIL && Tree[i].right == NIL) {
        printf("leaf\n");
    } else {
        printf("internal node\n");
    }
}

int main()
{
    int n;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        Tree[i].parent = NIL;
    }

    for (int i = 0; i < n; i++) {
        int id, left, right;
        scanf("%d %d %d", &id, &left, &right);
        Tree[id].left = left;
        Tree[id].right = right;
        if (left != NIL) {
            Tree[left].parent = id;
        }
        if (right != NIL) {
            Tree[right].parent = id;
        }
    }

    int root = NIL;

    for (int i = 0; i < n; i++) {
        if (Tree[i].parent == NIL) {
            root = i;
            break;
        }
    }

    if (root >= 0) {
        setDepth(root, 0);
        setHeight(root);
    }

    for (int i = 0; i < n; i++) {
        printNode(i);
    }

    return 0;
}
