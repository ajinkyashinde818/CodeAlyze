#include <stdio.h>
#define MAX 25

typedef struct node {
    int parent;
    int left;
    int right;
} Node;

Node nodes[MAX];
int depth[MAX];

int max(int a, int b) {
    if(a > b) return a;
    else return b;
}

int getHeight(int u){
    int v1=0, v2 = 0;
    if(nodes[u].left == -1 && nodes[u].right == -1) return 0;
    
    if(nodes[u].left != -1) {
        v1 = getHeight(nodes[u].left);
    }
    if(nodes[u].right != -1) {
        v2 = getHeight(nodes[u].right);
    }
    
    return 1 + max(v1, v2);
}

void setDepth(int u, int p) {
    depth[u] = p;
    if(nodes[u].left != -1) setDepth(nodes[u].left, p+1);
    if(nodes[u].right != -1) setDepth(nodes[u].right, p+1);
}

int getDegree(int u){
    if(nodes[u].left == -1 && nodes[u].right == -1) return 0;
    if(nodes[u].left != -1 && nodes[u].right != -1) return 2;
    
    return 1;
}

int getSibling(int u){
    if(nodes[u].parent == -1) return -1;
    
    if(nodes[nodes[u].parent].left == u) {
        return nodes[nodes[u].parent].right;
    } else{
        return nodes[nodes[u].parent].left;
    }
}

int main(void){
    // Your code here!
    int n;
    scanf("%d", &n);
    int u, l, r;
    
    for(int i = 0; i < n; i++) {
        nodes[i].parent = nodes[i].left = nodes[i].right = -1;
    }

    for(int i = 0; i < n; i++){
        scanf("%d %d %d", &u, &l, &r);
        nodes[u].left = l;
        nodes[u].right = r;
        nodes[l].parent = nodes[r].parent = u;
    }
    
    int root = -1;
    for(int i = 0; i < n; i++) {
        if(nodes[i].parent == -1) {
            root = i;
            break;
        }
    }
    
    setDepth(root, 0);
    for(int i = 0; i < n; i++) {
        int h = getHeight(i);
        int degree = getDegree(i);
        if(i == root) {
            printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, %s\n", i, nodes[i].parent, getSibling(i), degree, depth[i], h, "root");
        } else if(degree != 0) {
            printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, %s\n", i,  nodes[i].parent, getSibling(i), degree, depth[i], h, "internal node");
        } else {
            printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, %s\n", i,  nodes[i].parent, getSibling(i), degree, depth[i], h, "leaf");
        }
    }
    
}
