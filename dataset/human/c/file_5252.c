#include <stdio.h>
#include <stdlib.h>

typedef struct P{
    int parent;
    int left;
    int right;
}Node;

int depth(Node node[],int n){
    if(node[n].parent==-1){
        return 0;
    }
    return depth(node,node[n].parent)+1;
}

int height(Node node[],int n){
    int a,b;
    if(n==-1){return -1;}
    a = height(node,node[n].left);
    b = height(node,node[n].right);
    return a>b ? a+1 : b+1;
}

int sibling(Node node[],int n){
    if(node[n].parent==-1){return -1;}
    if(node[node[n].parent].left==n){
        return node[node[n].parent].right;
    }else{
        return node[node[n].parent].left;
    }
}

int degree(Node node[],int n){
    int count = 0;
    if(node[n].left!=-1){count++;}
    if(node[n].right!=-1){count++;}
    return count;
}

int main(void){
    int n,i,j,k,l,m;
    Node *node;
    scanf("%d",&n);
    node = (Node*)malloc(sizeof(Node)*n);
    for(i=0;i<n;i++){
        node[i].parent = -1;
        node[i].left = -1;
        node[i].right = -1;
    }
    for(i=0;i<n;i++){
        scanf("%d",&k);
        scanf("%d",&l);
        node[k].left = l;
        node[l].parent = k;
        scanf("%d",&l);
        node[k].right = l;
        node[l].parent = k;
    }
    
    for(i=0;i<n;i++){
        printf("node %d: ",i);
        printf("parent = %d, ",node[i].parent);
        printf("sibling = %d, ",sibling(node,i));
        printf("degree = %d, ",degree(node,i));
        printf("depth = %d, ",depth(node,i));
        printf("height = %d, ",height(node,i));
        if(node[i].parent==-1){  printf("root");  }
        else if(node[i].left==-1&&node[i].right==-1){  printf("leaf");  }
        else{  printf("internal node");  }
        printf("\n");
    }
}
