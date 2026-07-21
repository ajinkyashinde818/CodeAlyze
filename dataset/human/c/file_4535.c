#include <stdio.h>
#include <stdlib.h>

#define NIL -1

typedef struct{
    int parent, leftChild, rightSibling;
} Node;

void getDepth(int *depth, Node *nodes, int label, int val);
int getHeight(int *height, int *degree, Node *nodes, int label, bool sameLevel);

int main(int argc, char** argv) {
    int len, root, *depth, *height, *degree;
    Node* nodes;

    scanf("%d", &len);
    nodes = (Node *) calloc(sizeof(Node), len + 1);
    depth = (int *) calloc(sizeof(int), len + 1);
    height = (int *) calloc(sizeof(int), len + 1);
    degree = (int *) calloc(sizeof(int), len + 1);
    for (int i = 0; i < len; i++) {
        nodes[i].parent = nodes[i].leftChild = nodes[i].rightSibling = NIL;
    }

    for (int i = 0; i < len; i++) {
        int label, child1, child2;

        scanf("%d %d %d", &label, &child1, &child2);

        if (child1 == NIL && child2 != NIL) {
            int tmp = child1;
            child1 = child2;
            child2 = tmp;
        }

        if (child1 != NIL) {
            nodes[child1].parent = label;
            nodes[label].leftChild = child1;
        }

        if (child2 != NIL) {
            nodes[child2].parent = label;
            nodes[child1].rightSibling = child2;
        }
    }

    for (int i = 0; i < len; i++) {
        if (nodes[i].parent == NIL) {
            root = i;
            break;
        } 
    }

    getDepth(depth, nodes, root, 0);

    getHeight(height, degree, nodes, root, false);

    for (int i = 0; i < len; i++) {
        printf("node %d: parent = %d, sibling = ", i, nodes[i].parent);
        if (i != root) {
            int ctr = 0;
            for (int j = nodes[nodes[i].parent].leftChild; j != NIL; j = nodes[j].rightSibling) {
                if (j != i) {
                    ctr++;
                    printf("%d, ", j);
                }
            }

            if (ctr == 0) {
                printf("-1, ");
            }
        } else {
            printf("-1, ");
        }

        printf("degree = %d, depth = %d, height = %d, ", degree[i], depth[i], height[i]);
        printf("%s", i == root ? "root" : (nodes[i].leftChild == NIL ? "leaf" : "internal node"));
        printf("\n");
    }

    free(nodes);
    free(depth);
    free(height);
    free(degree);
    return 0;
}

void getDepth(int *depth, Node *nodes, int label, int val) {
    depth[label] = val;

    if (nodes[label].leftChild != NIL) {
        getDepth(depth, nodes, nodes[label].leftChild, val + 1);
    }

    if (nodes[label].rightSibling != NIL) {
        getDepth(depth, nodes, nodes[label].rightSibling, val);
    }
}

int getHeight(int *height, int *degree, Node *nodes, int label, bool sameLevel) {
    int h = 0, h1 = 0, h2 = 0;

    if (sameLevel) {
        degree[nodes[label].parent]++;
    }

    if (nodes[label].leftChild != NIL) {
        degree[label]++;
        h1 = getHeight(height, degree, nodes, nodes[label].leftChild, false) + 1;
    }
    height[label] = h1;
    
    if (nodes[label].rightSibling != NIL) {
        h2 = getHeight(height, degree, nodes, nodes[label].rightSibling, true);
    }

    h = h1 > h2 ? h1 : h2;

    return h;
}
