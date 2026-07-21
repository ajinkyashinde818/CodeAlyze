#include<stdio.h>
#define N 100000
#define nil -1

typedef struct{
    int p;
    int left;
    int right;
}Tree;

Tree tree[N];

int depth(int);

int main(){
    int i,j,n,num,deg,c,k=0;

    scanf("%d",&n);

    for(i=0;i<n;i++){
        tree[i].p=nil;
        tree[i].left=nil;
        tree[i].right=nil;
    }

    for(i=0;i<n;i++){
        scanf("%d%d",&num,&deg);
        for(j=0;j<deg;j++){
            scanf("%d",&c);
            if(j==0)tree[num].left=c;
            else tree[k].right=c;
            k=c;
            tree[c].p=num;
        }
    }

    for(i=0;i<n;i++){
        printf("node %d: parent = %d, depth = %d, ",i,tree[i].p,depth(i));
        if(depth(i)==0) printf("root, [");
        else if(tree[i].left==nil) printf("leaf, [");
        else printf("internal node, [");
        j=tree[i].left;
        while(j!=nil){
            printf("%d",j);
            j=tree[j].right;
            if(j!=nil){
                printf(", ");
            }
        }
        printf("]\n");
    }
    return 0;
}

int depth(int num){
    int dep=0;
    while(tree[num].p!=nil){
        num=tree[num].p;
        dep++;
    }
    return dep;
}
