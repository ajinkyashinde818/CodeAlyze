#include <stdio.h>
#include <stdlib.h>

int parent[100000];
int degree[100000];
int *children[100000];

int depth(int node){
    if(parent[node] == -1)
        return 0;
    else
        return depth(parent[node]) + 1;
}

int main(void){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        parent[i] = -1;
    for(int j=0; j<n; j++){
        int id, k;
        scanf("%d%d", &id, &k);
        degree[id] = k;
        children[id] = (int*)malloc(sizeof(int)*k);
        for(int i=0; i<k; i++){
            scanf("%d", &children[id][i]);
            parent[children[id][i]] = id;
        }
    }
    for(int i=0; i<n; i++){
        printf("node %d: parent = %d, depth = %d, ", i, parent[i], depth(i));
        if(parent[i] == -1)
            printf("root, ");
        else if(degree[i] == 0)
            printf("leaf, ");
        else
            printf("internal node, ");
        printf("[");
        for(int j=0; j<degree[i]; j++){
            printf("%d", children[i][j]);
            if(j < degree[i] - 1)
                printf(", ");
        }
        printf("]\n");
    }
}
