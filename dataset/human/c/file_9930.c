#include<stdio.h>
#define MAX 100005
#define NIL -1
struct Node{
    int parent;
    int left;
    int right;
};
struct Node T[MAX];

int n,D[MAX];
int setDepth(int u,int p){
    D[u] = p;
    if (T[u].right != NIL){
        setDepth(T[u].right,p);
    }
    if(T[u].left != NIL){
        setDepth(T[u].left,p + 1);
    }
}
void printChildren(int u){
    int c;
    c = T[u].left;
    printf("node %d: parent = %d, depth = %d, ",u,T[u].parent,D[u]);
    if(D[u] == 0){
    printf("root, [");
    }
    else if(c != NIL){
        printf("internal node, [");
    }
    else if(c == NIL){
        printf("leaf, [");
    }
    while(c != NIL){
        printf("%d",c);
        if(T[c].right != -1){
            printf(", ");
        }
        c = T[c].right;
    }
    printf("]\n");
}

int main(){
    int i,v,d,j,c,l,r,u;
    scanf("%d",&n);
    for(i = 0;i < n;i++){
        T[i].parent = NIL;
        T[i].left = NIL;
        T[i].right = NIL;
    }
    for(i = 0;i < n;i++){
        scanf("%d %d",&v,&d);
        for(j = 0;j < d;j++){
            scanf("%d",&c);
            if(j == 0) T[v].left = c;
            else T[l].right = c;
            l = c;
            T[c].parent = v;
            }
    }


for(i = 0;i < n;i++){
    if(T[i].parent == NIL) r = i;
}

setDepth(r,0);

for(u = 0;u < n;u++){
printChildren(u);
}
return 0;
}
