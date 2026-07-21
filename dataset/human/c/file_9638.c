#include<stdio.h>

struct node{
    int parent;
    int c_left;
    int right;
    int depth;
    int rank;
};

void setDepth(node node1[], int num, int depth){
    node1[num].depth = depth;
    int n = num;
    for (int i = 0; i < node1[num].rank; i++){
        if (i == 0) n = node1[n].c_left;
        else n = node1[n].right;
        setDepth(node1, n, depth+1);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    node node1[100000];
    for (int i = 0; i < n; i++) node1[i].parent = node1[i].c_left = node1[i].right = -1;
    for (int i = 0; i < n; i++){
        int num, rank;
        scanf("%d %d", &num, &rank);
        node1[num].rank = rank;
        int c = num;
        for (int j = 0; j < rank; j++){
            int child;
            scanf("%d", &child);
            if (j == 0) node1[c].c_left = child;
            else node1[c].right = child;
            c = child;
            node1[child].parent = num;
        }
    }
    int root = -1;
    for (int i = 0; i < n; i++){
        if (node1[i].parent == -1) root = i;
    }
    setDepth(node1, root, 0);
    
    for (int i = 0; i < n; i++){
        printf("node %d: parent = %d, depth = %d, ", i, node1[i].parent, node1[i].depth);
        if (node1[i].parent == -1) printf("root, [");
        else if (node1[i].rank > 0) printf("internal node, [");
        else printf("leaf, [");
        int num = i;
        for (int j = 0; j < node1[i].rank; j++){
            if (j == 0) num = node1[num].c_left;
            else num = node1[num].right;
            printf("%d", num);
            if (j != node1[i].rank - 1) printf(", ");
        }
        printf("]\n");
    }
}
