#include<stdio.h>
#include<cstdlib>
#include<cstring>

typedef struct bittree{
    int data;
    int degree;
    int depth;
    int height;
    char kind[14];
    struct bittree *left;
    struct bittree *right;
    struct bittree *parent;
}BIT_TREE;

int SearchRootNode(BIT_TREE *, int);
int GetSiblingData(BIT_TREE);
int CulcDepth(BIT_TREE *);
int CulcHeight(BIT_TREE *);

void P();

BIT_TREE Nil;

int main(){
    int i, n, d, l, r;
    BIT_TREE *T;
    
    scanf("%d", &n);
    T = (BIT_TREE *)malloc(sizeof(BIT_TREE) * n);
    Nil.data = -1;
    Nil.depth = -1;
    strcpy(Nil.kind, "leaf");
    
    // initialize
    for(i = 0; i < n; i++){
        // make all parent nodes Nil node
        T[i].parent = &Nil;
        T[i].left = &Nil;
        T[i].right = &Nil;
        T[i].degree = 0;
        strcpy(T[i].kind, "leaf");
    }
    
    
    for(i = 0; i < n; i++){
        scanf(" %d %d %d", &d, &l, &r);
        T[d].data = d;
        if(l != -1){
            T[d].left = &T[l];
            T[l].parent = &T[d];
            T[d].degree += 1;
            strcpy(T[d].kind, "internal node");
        }else{
            T[d].left = &Nil;
        }
        if(r != -1){
            T[d].right = &T[r];
            T[r].parent = &T[d];
            T[d].degree += 1;
            strcpy(T[d].kind, "internal node");
        }else{
            T[d].right = &Nil;
        }
    }
    
    
    r = SearchRootNode(T, n);
    
    CulcDepth(&T[r]);
    
    CulcHeight(&T[r]);
    
    for(i = 0; i < n; i++){
        printf("node %d: ", i);
        
        printf("parent = %d, ", T[i].parent->data);
        
        printf("sibling = %d, ", GetSiblingData(T[i]));
        
        printf("degree = %d, ", T[i].degree);
        
        printf("depth = %d, ",T[i].depth);
        
        printf("height = %d, ", T[i].height);
        
        printf("%s", T[i].kind);
        
        printf("\n");
    }
    
    return 0;
}


// put value 0 into root.depth and return root node matrix
int SearchRootNode(BIT_TREE *T, int n){
    int i;
    for(i = 0; i < n; i++){
        if(T[i].parent->data == -1){
            T[i].depth = 0;
            strcpy(T[i].kind, "root");
            return i;
        }
    }
}


int GetSiblingData(BIT_TREE T){
    // when T is rootnode
    if(T.parent->data == -1){
        return -1;
    }
    if(T.parent->right->data == T.data){
        return T.parent->left->data;
    }else{
        return T.parent->right->data;
    }
}

int CulcDepth(BIT_TREE *T){
    if(T->data == -1){
        return 0;
    }
    T->depth = T->parent->depth + 1;
    CulcDepth(T->left);
    CulcDepth(T->right);
    
    return 0;
}


int CulcHeight(BIT_TREE *T){
    if(T->degree == 0){ // leafNode
        T->height = 0;
    }else if(T->left == &Nil){ // T.left == NULL
        CulcHeight(T->right);
        T->height = T->right->height + 1;
    }else if(T->right == &Nil){ // T.right == NULL
        CulcHeight(T->left);
        T->height = T->left->height + 1;
    }else{
        /*if(CulcHeight(T->left) > CulcHeight(T->right)){
            T->height = T->left->height + 1;
        }else{
            T->height = T->right->height + 1;
        }*/
        CulcHeight(T->left);
        CulcHeight(T->right);
        T->height = T->left->height > T->right->height ? T->left->height + 1 : T->right->height + 1;
    }
    
    return 1;
}


void P(){
    static int i = 0;
    i++;
    printf("\n[%d]\n",i);
}
