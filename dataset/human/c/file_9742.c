#include<stdio.h>

#define N 100000
#define NIL -1

int depth(int);
void degree(int);

struct Node{
    int parent;
    int left;
    int right;
};

struct Node T[N];
int count=0;

int main(){

    int n,i,j,id,k,child,tmp;

    scanf("%d",&n);

    for(i=0;i<n;i++) T[i].parent=T[i].left=T[i].right=NIL;
    
    for(i=0;i<n;i++){

        scanf("%d%d",&id,&k);

        for(j=0;j<k;j++){

            scanf("%d",&child);

            T[child].parent=id;

            if(j==0) T[id].left=child;

            else T[tmp].right=child;

            tmp=child;

        }

    }

    for(i=0;i<n;i++){

        count=0;

        printf("node %d: parent = %d, depth = %d, ",i,T[i].parent,depth(i));

        if(T[i].parent==NIL) printf("root, [");

        else if(T[i].left==NIL) printf("leaf, [");

        else printf("internal node, [");

        count=0;

        degree(T[i].left);

        printf("]\n");

    }

    return 0;

}

int depth(int x){

    if(T[x].parent==NIL) return count;

    else{

    count++;

    return depth(T[x].parent);

    }

}

void degree(int x){

    if(x != NIL){

        if(count != 0) printf(", ");

        printf("%d",x);

        count++;

        degree(T[x].right);

    }

}
