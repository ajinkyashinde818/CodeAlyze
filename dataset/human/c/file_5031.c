#include <stdio.h>

#define MAX 10000
#define nil -1

typedef struct{
    int p;
    int left;
    int right;
}Node;

Node Tree[MAX];
int n, Depth[MAX], Height[MAX];

void setDepth(int u, int d){
    if(u == nil) return;
    Depth[u] = d;
    setDepth(Tree[u].left, d+1);
    setDepth(Tree[u].right, d+1);
}

int setHeight(int u){
    int h1=0, h2=0;
    if(Tree[u].left != nil) h1 = setHeight(Tree[u].left) + 1;
    if(Tree[u].right != nil) h2 = setHeight(Tree[u].right) + 1;
    return Height[u] = (h1 > h2 ? h1 : h2);
}

int getSibling(int u){
    if(Tree[u].p == nil) return nil;
    if(Tree[Tree[u].p].left != u && Tree[Tree[u].p].left != nil) return Tree[Tree[u].p].left;
    if(Tree[Tree[u].p].right != u && Tree[Tree[u].p].right != nil) return Tree[Tree[u].p].right;
    return nil;
}

void print(int u){
    printf("node %d: ",u);
    printf("parent = %d, ",Tree[u].p);
    printf("sibling = %d, ",getSibling(u));
    int deg=0;
    if(Tree[u].left != nil) deg++;
    if(Tree[u].right != nil) deg++;
    printf("degree = %d, ",deg);
    printf("depth = %d, ",Depth[u]);
    printf("height = %d, ",Height[u]);

    if(Tree[u].p == nil) printf("root\n");
    else if(Tree[u].left == nil && Tree[u].right == nil) printf("leaf\n");
    else printf("internal node\n");
}

int main(){
    int a, v, l, r, root=0;
    
    scanf("%d",&n);
    for(a = 0; a < n; a++) Tree[a].p = nil;
    for(a = 0; a < n; a++){
        scanf("%d%d%d",&v,&l,&r);
        Tree[v].left = l;
        Tree[v].right = r;
        if(l != nil) Tree[l].p = v;
        if(r != nil) Tree[r].p = v;
    }
    for(a = 0; a < n; a++) if(Tree[a].p == nil) root = a;

    setDepth(root, 0);
    setHeight(root);

    for(a = 0; a < n; a++) print(a);

    return 0;
}
