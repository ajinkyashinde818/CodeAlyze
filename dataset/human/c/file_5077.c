#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int id;
    int parent;
    int left;
    int right;
    int depth;
    int height;
};

#define MAX(x, y) ((x) > (y) ? (x) : (y))

static int FindRoot(const struct Node nodes[], int n) {
    int i;

    for ( i = 0; i < n; i++ ) {
        if ( nodes[i].parent == -1 ) {
            return nodes[i].id;
        }
    }

    assert( 0 );

    return -1;
}

static int UpdateDepthAndHeight(int root, struct Node nodes[], int n) {
    int height_l = 0;
    int height_r = 0;

      /* left */
    if ( (nodes[root].left == -1) && (nodes[root].right == -1) ) {
        nodes[root].height = 0;        
        return 0;
    }

    if ( nodes[root].left != -1 ) {
        int left = nodes[root].left;

        nodes[left].depth = nodes[root].depth + 1;

        height_l = UpdateDepthAndHeight(left, nodes, n) + 1;        
    }

    if ( nodes[root].right != -1 ) {
        int right = nodes[root].right;

        nodes[right].depth = nodes[root].depth + 1;

        height_r = UpdateDepthAndHeight(right, nodes, n) + 1;
    }
    
    nodes[root].height = MAX(height_l, height_r);

    return nodes[root].height;
}


static const char* GetType(const struct Node* p_node) {
    if ( p_node->parent == -1 ) {
        return "root";
    }

    if ( (p_node->left == -1) && (p_node->right == -1) ) {
        return "leaf";
    }

    return "internal node";
}

int main(void) {
    int i;
    int n;
    int id, left, right;
    struct Node* nodes;

    scanf("%d\n", &n);

    nodes = malloc(sizeof(struct Node) * n);

      /* init */
    for ( i = 0; i < n; i++ ){
        nodes[i].id = -1;
        nodes[i].parent = nodes[i].left = nodes[i].right = -1;
        nodes[i].depth = nodes[i].height = 0;
    }

    for ( i = 0; i < n; i++ ) {
        scanf("%d %d %d\n", &id, &left, &right);

        nodes[id].id = id;

        nodes[id].left  = left;
        if ( left != -1 ) {
            nodes[left].parent = id;
        }
        
        nodes[id].right = right;
        if ( right != -1 ) {
            nodes[right].parent = id;
        }
    }

    int root = FindRoot(nodes, n);

    UpdateDepthAndHeight(root, nodes, n);

    for ( i = 0; i < n; i++ ) {
        int id = nodes[i].id;
        int parent = nodes[i].parent;
        int sibling = parent == -1 ?
            -1 : 
            nodes[parent].left == id ? nodes[parent].right : nodes[parent].left;
        int degree = (nodes[i].left != -1) + (nodes[i].right != -1);
        int depth = nodes[i].depth;
        int height = nodes[i].height;
        const char* type = GetType(&nodes[i]);
        
        printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, %s\n",
               id, parent, sibling, degree, depth, height, type);
    }

    free(nodes);

    return 0;
}
