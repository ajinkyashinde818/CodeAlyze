#include <stdio.h>

typedef struct _node{
    int parent;
    int depth;
    int height;
    int l,r;
}NODE;

void getDepth(NODE node[],int id,int d){
    node[id].depth=d;
    
    if(node[id].l!=-1)getDepth(node,node[id].l,d+1);
    if(node[id].r!=-1)getDepth(node,node[id].r,d+1);
    return;
}
void getHeight(NODE node[],int id,int h){
    if(node[id].height<h)node[id].height=h;
    
    if(node[id].parent!=-1)getHeight(node,node[id].parent,h+1);
    return;
}
int getSibling(NODE node[],int id){
    int p=node[id].parent;
    if(p==-1)return -1;
    
    int l=node[p].l;
    int r=node[p].r;
    
    if(l==id&&r!=-1)return r;
    else if(r==id&&l!=-1)return l;
    else return -1;
}
int getDegree(NODE node[],int id){
    int l=node[id].l;
    int r=node[id].r;
    
    if(l!=-1&&r!=-1)return 2;
    else if(l!=-1||r!=-1)return 1;
    else return 0;
}
void printNode(NODE node[],int n){
    int i;
    for(i=0;i<n;i++){
        printf("node %d: parent = %d,",i,node[i].parent);
        printf(" sibling = %d, degree = %d,",getSibling(node,i),getDegree(node,i));
        printf(" depth = %d, height = %d, ",node[i].depth,node[i].height);
        if(node[i].parent==-1)printf("root\n");
        else if(node[i].height==0)printf("leaf\n");
        else printf("internal node\n");
    }
    return;
}
int main(void){
    int i;
    
    int n;
    scanf("%d\n",&n);
    
    NODE node[n];
    for(i=0;i<n;i++){
        node[i].parent=-1;
        node[i].depth=-1;
        node[i].height=-1;
        node[i].l=-1;
        node[i].r=-1;
    }
    
    int id,l,r;
    for(i=0;i<n;i++){
        scanf("%d %d %d\n",&id,&l,&r);
        node[id].l=l;
        node[id].r=r;
        if(l!=-1)node[l].parent=id;
        if(r!=-1)node[r].parent=id;
    }
    
    int root;
    for(root=0;root<n;root++)if(node[root].parent==-1)break;
    node[root].depth=0;
    
    getDepth(node,root,0);
    
    for(i=0;i<n;i++){
        if(node[i].l==-1&&node[i].r==-1)getHeight(node,i,0);
    }
    
    printNode(node,n);
    
    return 0;
}
