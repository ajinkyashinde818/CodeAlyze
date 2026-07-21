#include<stdio.h>

#define N 100000
#define NIL -1

int depth(int);
int height(int);

struct Node{
    int parent;
    int left;
    int right;
};

struct Node T[N];

int main(){

    int n,i,id;

    scanf("%d",&n);

    for(i=0;i<n;i++) T[i].parent=T[i].left=T[i].right=NIL;
    
    for(i=0;i<n;i++){

        scanf("%d",&id);

        scanf("%d%d",&T[id].left,&T[id].right);

        if(T[id].left!=NIL) T[T[id].left].parent=id;

        if(T[id].right!=NIL) T[T[id].right].parent=id;

    }

    for(i=0;i<n;i++){

        printf("node %d: parent = %d, sibling = ",i,T[i].parent);

        if(T[i].parent==NIL) printf("-1, ");

        else{

            if(T[T[i].parent].left==i) printf("%d, ",T[T[i].parent].right);

            else printf("%d, ",T[T[i].parent].left);

        }

        printf("degree = ");

        if(T[i].left==NIL && T[i].right==NIL) printf("0, ");

        else{

            if(T[i].left!=NIL && T[i].right!=NIL) printf("2, ");

            else printf("1, ");

        }

        printf("depth = %d, height = %d, ",depth(i),height(i));

        if(T[i].parent==NIL) printf("root");

        else{

            if(T[i].left==NIL && T[i].right==NIL) printf("leaf");

            else printf("internal node");
        }

        printf("\n");

    }

    return 0;

}

int depth(int x){

    if(T[x].parent==NIL) return 0;

    return depth(T[x].parent)+1;

}

int height(int x){

    int left=0,right=0;

    if(T[x].left==NIL && T[x].right==NIL) return 0;

    if(T[x].left!=NIL) left=height(T[x].left)+1;

    if(T[x].right!=NIL) right=height(T[x].right)+1;

    if(left>right) return left;

    else return right;

}
