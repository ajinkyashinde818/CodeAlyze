#include <stdio.h>
#include <stdlib.h>
#define NUM 100000

typedef struct kk{
    struct kk *child;
    struct kk *sibling;
    struct kk *parent;
    int node;
} P;

P x[NUM];

int depth(P );

int main()
{
    int n,id,k,depth1,parent = 0;
    int i,j;
    int node1,node2;
    
    struct kk *N,*L = NULL;
    
    scanf("%d",&n);
    
    for(i = 0;i < n;i++){
        scanf("%d",&id);
        x[id].node = id;
        
        scanf("%d",&k);
        if(k == 0) continue;
        for(j = 0;j < k;j++){
            if(j == 0){
                scanf("%d",&node1);
                x[node1].node = node1;
                x[id].child = &x[node1];
                x[node1].parent = &x[id];
                L = x[id].child;
            }
            else{
                scanf("%d",&node2);
                x[node2].node = node2;
                L->sibling = &x[node2];
                L->sibling->parent = &x[id];
                L = L->sibling;
            }
        }
    }
    
    for(i = 0;i < n;i++){
        printf("node %d: ",i);
        if(x[i].parent == NULL){
            parent = -1;
            printf("parent = %d, ",parent);
        }
        else printf("parent = %d, ",x[i].parent->node);
        
        depth1 = depth(x[i]);
        printf("depth = %d, ",depth1);
        
        if(x[i].parent == NULL) printf("root, ");
        else if(x[i].child != NULL) printf("internal node, ");
        else printf("leaf, ");
        
        if(x[i].child == NULL) printf("[]\n");
        else{
            printf("[%d",x[i].child->node);
            N = x[i].child->sibling;
            while(N != NULL){
                printf(", %d",N->node);
                N = N->sibling;
            }
            printf("]\n");
        }
    }
    
    return 0;
}

int depth(P a)
{
    int i = 0;
    struct kk *M;
    M = a.parent;
    
    while(M != NULL){
        i++;
        M = M->parent;
    }
    
    return i;
}
