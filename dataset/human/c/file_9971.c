#include<stdio.h>
#define N 100000
#define NIL -1
void depth(int,int);
void print(int);

typedef struct{
    int parent;
    int left;
    int right;
} Node;
Node node_all[N];
int n;
int depth_node[N];

int main(){
    int i,j,n_num,degree,data,n_child,flag;

    scanf("%d",&n);
    for(i=0;i<n;i++){
        node_all[i].parent = node_all[i].left = node_all[i].right = NIL;
    }
    for(i=0;i<n;i++){
        scanf("%d%d",&n_num,&degree);
        for(j=0;j<degree;j++){
            scanf("%d",&data);
            if(j==0){
                node_all[n_num].left = data;
            }
            else{
                node_all[n_child].right = data;
            }
            n_child = data;
            node_all[data].parent = n_num;
        }
    }
    for(i=0;i<n;i++){
        if(node_all[i].parent == NIL) flag = i;
    }
    depth(flag,0);
    for(i=0;i<n;i++){
        print(i);
    }
    return 0;
}

void depth(int first,int count){
    depth_node[first] = count;
    if(node_all[first].right != NIL){
        depth(node_all[first].right,count);
    }
    if(node_all[first].left != NIL){
        depth(node_all[first].left,count+1);
    }
}

void print(int k){
    int i,data;
    
    printf("node %d: ",k);
    printf("parent = %d, ",node_all[k].parent);
    printf("depth = %d, ",depth_node[k]);
    if(node_all[k].parent == NIL){
        printf("root, ");
    }
    else if(node_all[k].left == NIL){
        printf("leaf, ");
    }
    else printf("internal node, ");

    printf("[");
    for(i=0,data=node_all[k].left;data!=NIL;i++){
        printf("%d",data);
        data=node_all[data].right;
        if(data!=NIL){
            printf(", ");
        }
    }
    printf("]\n");
}
