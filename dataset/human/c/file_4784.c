#include <stdio.h>
#define MAX 10000
#define NIL -1

typedef struct{int parent,left,right;}Node;

Node T[MAX];
int n,D[MAX],H[MAX];

void setDepth(int,int);
int setHeight(int);
int getSibling(int);
void print(int);

int main(){
    int i,j,v,l,r,root=0;
    scanf("%d",&n);

    for(int i=0;i<n;i++) T[i].parent=NIL;

    for(i=0;i<n;i++){
        scanf("%d%d%d",&v,&l,&r);
        T[v].left=l;
        T[v].right=r;
        if(l!=NIL) T[l].parent=v;
        if(r!=NIL) T[r].parent=v;
    }
    for(i=0;i<n;i++) if(T[i].parent==NIL) root=i;

    setDepth(root,0);
    setHeight(root);

    for(i=0;i<n;i++) print(i);

    return 0;
}
void setDepth(int u,int d){
    if(u==NIL) return;
    D[u]=d;
    setDepth(T[u].left,d+1);
    setDepth(T[u].right,d+1);
}

int setHeight(int u){
    int f1=0,f2=0;
    if(T[u].left!=NIL) f1=setHeight(T[u].left)+1;
    if(T[u].right!=NIL) f2=setHeight(T[u].right)+1;

    if(f1>f2) return H[u]=f1;
    else return H[u]=f2;
}

int getSibling(int u){
    if(T[u].parent==NIL) return NIL;
    if(T[T[u].parent].left!=u && T[T[u].parent].left!=NIL) return T[T[u].parent].left;
    if(T[T[u].parent].right!=u && T[T[u].parent].right!=NIL) return T[T[u].parent].right;
    return NIL;
}

void print(int u){
    int d=0;
    printf("node %d: ",u);
    printf("parent = %d, ",T[u].parent);
    printf("sibling = %d, ",getSibling(u));
    if(T[u].left!=NIL) d++;
    if(T[u].right!=NIL) d++;
    printf("degree = %d, ",d);
    printf("depth = %d, ",D[u]);
    printf("height = %d, ",H[u]);

    if(T[u].parent==NIL){
        printf("root\n");
    }
    else if(T[u].left==NIL && T[u].right==NIL){
        printf("leaf\n");
    }
    else{
        printf("internal node\n");
    }
}
