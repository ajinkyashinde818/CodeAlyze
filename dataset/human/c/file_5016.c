#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

//============================================================================
#define pred(x) ((x)-1)
#define succ(x) ((x)+1)
//============================================================================
struct Node{
    short  id;
    struct Node *parent;
    struct Node *left, *right;
};
typedef struct Node TNode;
//============================================================================
struct Chain{
    struct Chain *prev;
    TNode *node;
    struct Chain *next;
};
typedef struct Chain TChain;
TChain *RootChain;
//============================================================================
//============================================================================
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
TChain *ChainAlloc(void)
{
    TChain *ptr;
    ptr=malloc(sizeof(TChain));
    if (ptr==NULL)
        exit(1);
    memset(ptr, 0, sizeof(TChain));
    return ptr;
}
//----------------------------------------------------------------------------
void inschain(TChain *chn, TNode *node)
{
    while(chn->next!=NULL)
        chn=chn->next;
    chn->next=ChainAlloc();
    chn->next->node=node;
    chn->next->prev=chn;
}
//----------------------------------------------------------------------------
void delchain(TChain *chn)
{
    if (chn->prev){
        chn->prev->next=chn->next;
    }
    if (chn->next){
        chn->next->prev=chn->prev;
    }
    free(chn);
}
//----------------------------------------------------------------------------
TChain *searchchain(TChain *chn, short id)
{
    do{
        if (chn->node->id==id)
            return chn;
        if (chn->node->left && chn->node->left->id==id)
            return chn;
        if (chn->node->right && chn->node->right->id==id)
            return chn;
        chn=chn->next;
    }while(chn!=NULL);
    return NULL;
}
//----------------------------------------------------------------------------
void pushnode(TNode *node)
{
    if (RootChain==NULL){
        RootChain=ChainAlloc();
        RootChain->node=node;
    }else{
        inschain(RootChain, node);
    }
}
//----------------------------------------------------------------------------
TNode *popnode(short id)
{
    TChain *chn; TNode *node;

    node=NULL;
    chn=searchchain(RootChain, id);
    if (chn){
        if (chn->node->id==id)
            node=chn->node;
        else
        if (chn->node->left && chn->node->left->id==id)
            node=chn->node->left;
        else
        if (chn->node->right && chn->node->right->id==id)
            node=chn->node->right;
        if (node==chn->node)
            delchain(chn);
    }
    return node;
}
//----------------------------------------------------------------------------
TNode *nodealloc(void)
{
    TNode *node;
    node=malloc(sizeof(TNode));
    if (node==NULL){
        fprintf(stderr, "not enough memry\n");
        exit(1);
    }
    memset(node, 0, sizeof(TNode));
    return node;
}
//----------------------------------------------------------------------------
TNode *existid(TNode *node, short id)
{
    TNode *nd;

    if (node==NULL || node->id==id)
        return node;
    if ((nd=existid(node->left, id))!=NULL)
        return nd;
    nd=existid(node->right, id);
    return nd;
}
//----------------------------------------------------------------------------
void putnode(TNode **root, TNode **node, TNode *parent, short id)
{
    TNode *nd;

    if ((nd=existid(*root, id))==NULL)
        nd=popnode(id);
    if (nd==NULL){
        *node=nodealloc();
    }else{
        *node=nd;
        //nd->parent=*node;
        if (*root==nd){
            *root=parent;
            while((*root)->parent!=NULL)
                *root=(*root)->parent;
        }
    }
    (*node)->id=id;
    (*node)->parent=parent;
}
//----------------------------------------------------------------------------
TNode *rootnode(TNode *node)
{
    while(node->parent)
        node=node->parent;
    return node;
}
//----------------------------------------------------------------------------
void getnode(FILE *file, TNode **node)
{
    long id,left,right; TNode *ser;

    fscanf(file, "%ld", &id);
    fscanf(file, "%ld", &left);
    fscanf(file, "%ld", &right);
    if (*node==NULL){
        *node=nodealloc();
        ser=*node;
        pushnode(*node);
    }else
        ser=existid(*node, id);
    if (ser==NULL){
        ser=popnode(id);
        if (ser==NULL)
            ser=nodealloc();
    }
    if (*node!=rootnode(ser))
    pushnode(ser);
    ser->id=id;
    if (0<=left)
        putnode(node, &ser->left, ser, left);
    if (0<=right)
        putnode(node, &ser->right, ser, right);
}
//----------------------------------------------------------------------------
short depth(TNode *node)
{
    short n;

    for (n=0; node->parent!=NULL; n++)
        node=node->parent;
    return n;
}
//----------------------------------------------------------------------------
short height(TNode *node)
{
    short l,r;

    if (node==NULL)
        return -1;
    l=succ(height(node->left));
    r=succ(height(node->right));
    return (r<l)?l:r;
}
//----------------------------------------------------------------------------
char *root="root";
char *internalroot="internal node";
char *leaf="leaf";
char *nodetype(TNode *node)
{
    if (node->parent==NULL)
        return root;
    if (node->left!=NULL || node->right!=NULL)
        return internalroot;
    return leaf;
}
//----------------------------------------------------------------------------
void output(TNode *root, long n)
{
    short i,j,cnt,id,sib,deg; TNode *node;

    for (i=cnt=0; cnt<n; i++){
        node=existid(root, i);
        if (node!=NULL){
            cnt++;
            sib=-1;
            if (node->parent!=NULL && node->parent->left!=NULL && node->parent->right!=NULL){
                if (node->parent->left==node)
                    sib=node->parent->right->id;
                else
                    sib=node->parent->left->id;
            }
            deg=(node->left==NULL)?0:1;
            deg+=(node->right==NULL)?0:1;
            id=(node->parent==NULL)?-1:node->parent->id;
            printf("node %d: ", node->id);
            printf("parent = %d, ", id);
            printf("sibling = %d, ", sib);
            printf("degree = %d, ", deg);
            printf("depth = %d, ", depth(node));
            printf("height = %d, ", height(node));
            printf("%s\n", nodetype(node));
        }
    }
}
//----------------------------------------------------------------------------
void input(FILE *file)
{
    long i,n,m; TNode *root; char buffer[20];

    RootChain=NULL;
    fgets(buffer, sizeof(buffer)-1, file);
    sscanf(buffer, "%ld", &n);
    for (i=0, root=NULL; i<n; i++){
        getnode(file, &root);
        //printf("%08X\n", root);
    }
    while(root->parent)
        root=root->parent;
    output(root, n);
}
//============================================================================
#ifndef DESKTOP
int main()
{
    input(stdin);
    return 0;
}
#endif
