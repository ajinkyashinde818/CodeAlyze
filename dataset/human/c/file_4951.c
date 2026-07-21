#include<stdio.h>
#define max 26
#define NIL -1

typedef struct{
    int parent,left,right;
}NODE;

NODE T[max];
int Max(int a,int b){
    if(a>b)return a;
    else return b;
}
int depth(int i){
    int d=0;
    while(T[i].parent!=NIL){
        i=T[i].parent;
        d++;
    }
    return d;
}
int height(int i){
    int h1=0,h2=0;
    if(T[i].left!=NIL){
        h1=height(T[i].left)+1;
    }
    if(T[i].right!=NIL){
        h2=height(T[i].right)+1;
    }
    return Max(h1,h2);
}

int main(){
    int n,i;
    scanf("%d",&n);
    for(i=0;i<=n-1;i++){
        T[i].parent=NIL;
    }
    for(i=0;i<=n-1;i++){
        int id,l,r;
        scanf("%d %d %d",&id,&l,&r);
        T[id].left=l,T[id].right=r;
        if(l!=NIL)T[l].parent=id;
        if(r!=NIL)T[r].parent=id;
    }
    
    for(i=0;i<=n-1;i++){
        printf("node %d: parent = %d, sibling = ",i,T[i].parent);
        if(T[i].parent==NIL)printf("-1");
        else if(T[T[i].parent].left==i)printf("%d",T[T[i].parent].right);
        else printf("%d",T[T[i].parent].left);
        printf(", degree = ");
        if(T[i].left==NIL && T[i].right==NIL)printf("0");
        else if (T[i].left!=NIL && T[i].right!=NIL)printf("2");
        else printf("1");
        printf(", depth = %d, height = %d, ",depth(i),height(i));
        if(T[i].parent==NIL)printf("root\n");
        else if(T[i].left==NIL && T[i].right==NIL) printf("leaf\n");
        else printf("internal node\n");
    }
    
    
    return 0;
}
