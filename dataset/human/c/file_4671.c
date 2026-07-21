#include <stdio.h>
#include <string.h>

struct node{
    int parent,left,right;
}T[30];

int H[30],D[30];

int setHeight(int u){
    int h1 = 0,h2 = 0;
    if(T[u].left != -1)
        h1 = setHeight(T[u].left)+1;
    if(T[u].right != -1)
        h2 = setHeight(T[u].right)+1;
    return H[u] = h1>h2?h1:h2;
}

void setDepth(int u,int d){
    D[u] = d;
    if(T[u].left != -1) setDepth(T[u].left,d+1);
    if(T[u].right != -1) setDepth(T[u].right,d+1);
}

void print(int u){
    int deg = 0;
    printf("node %d: parent = %d, ",u,T[u].parent);
    printf("sibling = ");
    if(T[u].parent == -1) printf("-1, "); 
    else if(T[T[u].parent].left != -1 && T[T[u].parent].left != u)
        printf("%d, ",T[T[u].parent].left);
    else if(T[T[u].parent].right != -1 && T[T[u].parent].right != u)
        printf("%d, ",T[T[u].parent].right);
    else
        printf("-1, ");
    if(T[u].left!=-1) deg++;
    if(T[u].right!=-1) deg++;
    printf("degree = %d, ",deg);
    printf("depth = %d, ",D[u]);
    printf("height = %d, ",H[u]);
    if(T[u].parent == -1) printf("root\n");
    else if(T[u].left == -1 && T[u].right == -1)printf("leaf\n");
    else printf("internal node\n");
}

int main(){
    int n,v,l,r;
    int root = 0;
    memset(T,-1,sizeof(T));
    scanf("%d",&n);
    for(int i = 0 ; i < n ; i++){
        scanf("%d%d%d",&v,&l,&r);
        if(l != -1){ T[v].left = l,T[l].parent = v;}
        if(r != -1){ T[v].right =r,T[r].parent = v;}
    }
    for(int i = 0; i < n ; i++)
        if(T[i].parent == -1){
            root = i;
            break;
        }
    setHeight(root);
    setDepth(root,0);
    for(int i = 0 ; i < n ; i++)
        print(i);
    return 0;
}
