#include<stdio.h>
#include<cstdlib>
#include<cstring>

typedef struct tree{
    struct tree *parent;
    struct tree *child;
    struct tree *next; // element next to child
    int order;
    int depth;
    char kind[14];
} TREE;

int CulcDepth(TREE*);

int main(){
    int i, j, n, NOFchild, curorder, order, nextorder;
    TREE *T , Nil, *tmp;
    
    scanf("%d", &n);
    T = (TREE *)malloc(sizeof(TREE) * n);
    
    // input
    for (i = 0; i < n; i++) {
        scanf("%d %d", &curorder, &NOFchild);
        T[curorder].order = curorder;
        strcpy(T[curorder].kind, "leaf");
        T[curorder].child = NULL;
        T[curorder].depth = -1;
        if (NOFchild == 0) {
            continue;
        }
        
        strcpy(T[curorder].kind, "internal node");
        // 一つ目の子nodeを接続
        scanf("%d", &order);
        T[curorder].child = &T[order];
        T[order].parent = &T[curorder];
        if (NOFchild == 1) {
            T[curorder].child->next = NULL;
            continue;
        }
        // 二つ目
        scanf("%d", &nextorder);
        T[curorder].child->next = &T[nextorder];
        T[nextorder].parent = &T[curorder];
        if (NOFchild == 2) {
            T[curorder].child->next->next = NULL;
            continue;
        }
        
        // 三つ目以降
        order = nextorder;
        for (j = 0; j < NOFchild-2; j++) {
            scanf("%d", &nextorder);
            T[order].next = &T[nextorder];
            T[nextorder].parent = &T[curorder];
            order = nextorder;
        }
        T[nextorder].next = NULL;
        
    }
    
    Nil.order = -1;
    // rootnodeとNilnodeを接続
    // parent == NULLのnodeはroot node
    for (i = 0; i < n; i++) {
        if (T[i].parent == NULL) {
            strcpy(T[i].kind, "root");
            Nil.child = &T[i];
            T[i].parent = &Nil;
            break;
        }
    }
    
    // depth求める
    T[i].depth = 0; // root node
    CulcDepth(T[i].child);
    
    
    
    // output
    for (i = 0; i < n; i++) {
        printf("node %d: ", i);
        
        printf("parent = %d, ", T[i].parent->order);
        
        printf("depth = %d, ",T[i].depth);
        
        printf("%s, ", T[i].kind);
        
        printf("[");
        if (T[i].child != NULL) {
            for (tmp = T[i].child; tmp != NULL; tmp = tmp->next) {
                printf("%d", tmp->order);
                //printf(" /test/ ");
                if(tmp->next == NULL){
                    break;
                }
                printf(", ");
            }
        }
        printf("]");
        
        printf("\n");
    }
    
    
    free(T);
    return 0;
}

int CulcDepth(TREE *T){
    if (T == NULL) {
        return 0;
    }
    T->depth = T->parent->depth + 1;
    CulcDepth(T->child);
    CulcDepth(T->next);
    
    return 0;
}
