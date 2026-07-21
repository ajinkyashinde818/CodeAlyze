#include<stdio.h>
#define MAX 100005
#define NIL -1
struct Node_struct{
    int p, l, r;
}; /*p: 親(parent), l: 一番左の子(left child), r:右の兄弟(right sibling)*/
typedef struct Node_struct Node;
Node T[MAX];
int D[MAX];
int H[MAX];

void calcDepth(int u, int p){
    D[u] = p;
    if(T[u].l!=NIL) calcDepth(T[u].l,p+1);
    if(T[u].r!=NIL) calcDepth(T[u].r,p+1);
}

int calcHeight(int a,int h){
    int h1=0,h2=0;
    if(T[a].l!=NIL)h1=calcHeight(T[a].l,h)+1;
    if(T[a].r!=NIL)h2=calcHeight(T[a].r,h)+1;
    return H[a]=(h1>h2?h1:h2);
}

int getSibling(int u){
    if(T[u].p==NIL)return NIL;
    if(T[T[u].p].l!=u && T[T[u].p].l!=NIL)return T[T[u].p].l;
    if(T[T[u].p].r!=u && T[T[u].p].r!=NIL)return T[T[u].p].r;
    return NIL;
}

void print(int u){
    int i, c;
    int deg=0;
    if(T[u].l!=NIL)deg++;
    if(T[u].r!=NIL)deg++;
    printf("node %d: parent = %d, ",u,T[u].p);
    printf("sibling = %d, degree = %d, ",getSibling(u),deg);
    printf("depth = %d, height = %d, ",D[u],H[u]);
    
    if(T[u].p==NIL) printf("root\n");
    else if(T[u].l==NIL && T[u].r==NIL) printf("leaf\n");
    else printf("internal node\n");
    
}

int main(){
    int i, j, k;
    int n;
    int id, sib, child1,child2;
    int temp;
    int root = NIL;
    scanf("%d", &n);
    for(i=0; i<n; i++) T[i].p = T[i].l = T[i].r = NIL;
    
    for(i=0; i<n; i++){
        scanf("%d",&id);
        scanf("%d %d",&child1,&child2);
        T[id].l=child1;
        T[id].r=child2;
        if(child1!=NIL)T[child1].p=id;
        if(child2!=NIL)T[child2].p=id;
    }
    //根を求める (find the root)
    for(i=0; i<n; i++){
        if(T[i].p == -1) root = i;
    }
    
    //それぞれのノードの深さを求める (find depth of each node)
    calcDepth(root, 0);
    calcHeight(root,0);
    
    //出力 (output)
    for(i=0; i<n; i++) print(i);
    
    return 0;
}
