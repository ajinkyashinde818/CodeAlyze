#include<stdio.h>
#define MAX 10000

void depth(int, int);
void print(int);
int height(int);
int sibling(int);

struct node{
    int parent;
    int left;
    int right;
};
struct node data[MAX];
int n,data2[MAX],data3[MAX];

int main(){
    int i,id,left,right,root=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)data[i].parent=-1;
    for(i=0;i<n;i++){
        scanf("%d %d %d",&id,&left,&right);
        data[id].left=left;
        data[id].right=right;
        if(left!=-1)data[left].parent=id;
        if(right!=-1)data[right].parent=id;
    }
    for(i=0;i<n;i++){
        if(data[i].parent==-1) root=i;
    }
    depth(root,0);
    height(root);
    for(i=0;i<n;i++)print(i);
    return 0;
}

int height(int x){
    int h=0,h2=0;
    if(data[x].left!=-1)h=height(data[x].left)+1;
    if(data[x].right!=-1)h2=height(data[x].right)+1;
    if(h>h2)return data3[x]=h;
    else return data3[x]=h2;
}

int sibling(int x){
    if(data[x].parent==-1)return -1;
    if(data[data[x].parent].left!=x && data[data[x].parent].left!=-1){
        return data[data[x].parent].left;
    }
    if(data[data[x].parent].right!=x && data[data[x].parent].right!=-1){
        return data[data[x].parent].right;
    }
    return -1;
}

void depth(int x, int y){
    if(x==-1)return;
    data2[x]=y;
    depth(data[x].left, y+1);
    depth(data[x].right, y+1);
}

void print(int x){
    int d=0;
    printf("node %d: ",x);
    printf("parent = %d, ",data[x].parent);
    printf("sibling = %d, ",sibling(x));
    if(data[x].left!=-1)d++;
    if(data[x].right!=-1)d++;
    printf("degree = %d, ",d);
    printf("depth = %d, ",data2[x]);
    printf("height = %d, ",data3[x]);
    if(data[x].parent==-1){
        printf("root\n");
    }else if(data[x].left==-1 && data[x].right==-1){
        printf("leaf\n");
    }else{
        printf("internal node\n");
    }
}
