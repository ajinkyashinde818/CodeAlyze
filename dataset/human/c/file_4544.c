#include <stdio.h>
#define NIL -1
#define MAX 30

struct Node {
    int oya, left, right;
};
typedef struct Node t_node;
t_node T[MAX];
int D[MAX];
int H[MAX];
int N;

void setDepth(int id, int depth)
{
    D[id] = depth;
    if (T[id].left != NIL) {
        setDepth(T[id].left, depth + 1);        
    }
    if (T[id].right != NIL) {
        setDepth(T[id].right, depth + 1);
    }
}

int setHeight(int id)
{
    int h1 = 0, h2 = 0;
    if (T[id].left != NIL) {
        h1 = setHeight(T[id].left) + 1;
    }
    if (T[id].right != NIL) {
        h2 = setHeight(T[id].right) + 1;
    }    
    return H[id] = h1 > h2 ? h1 : h2;
}

int getoya(int id)
{
    return T[id].oya;
}

int getkyoudai(int id)
{
    int i;
    for (i = 0; i < N; i++) {
        if (id != i && D[id] == D[i] && T[id].oya == T[i].oya) {
            break;
        }
    }
    return i != N ? i : NIL;
}

int getDegree(int id)
{
    int i, d = 0;
    for (i = 0; i < N; i++) {
        if (T[i].oya == id) {
            d++;
        }
    }
    return d;
}

void printTree()
{
    int root;
    int id;
    for (id = 0; id < N; id++) {
        if (T[id].oya == NIL) root = id;
    }
    
    setDepth(root, 0);
    setHeight(root);

    int p, s, d;
    for (id = 0; id < N; id++) {
        p = getoya(id);
        s = getkyoudai(id);
        d = getDegree(id);
        printf("node %d: ", id);
        printf("parent = %d, ", p);
        printf("sibling = %d, ", s);
        printf("degree = %d, ", d);
        printf("depth = %d, ", D[id]);
        printf("height = %d, ", H[id]);
        if (p == NIL) {
            puts("root"); 
            continue;
        }
        switch (d) {
            case 0: puts("leaf"); break;
            default : puts("internal node"); break;
        }
    }
}

int main()
{
    int i, j;
    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        T[i].oya = T[i].left = T[i].right = NIL;
    }    
    int id;
    for (i = 0; i < N; i++) {
        scanf("%d", &id);
        scanf("%d %d", &T[id].left, &T[id].right);
        T[T[id].left].oya = id;
        T[T[id].right].oya = id;
    }
 
    printTree();
    
    return 0;
}
