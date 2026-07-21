#include<stdio.h>
#define N 100000
#define NIL -1
void depth(int,int);
int height(int);
int info_sibling(int);
void print(int);

typedef struct{
    int parent;
    int left;
    int right;
} Node;

Node node_all[N];
int n;
int node_depth[N],node_height[N];

int main(){
    int i,id,l,r,root;

    scanf("%d",&n);
    for(i=0;i<n;i++){
        node_all[i].parent = NIL;
    }
    for(i=0;i<n;i++){
        scanf("%d%d%d",&id,&l,&r);
        node_all[id].left = l;
        node_all[id].right = r;
        if(l != NIL) node_all[l].parent = id;
        if(r != NIL) node_all[r].parent = id;
    }
    for(i=0;i<n;i++){
        if(node_all[i].parent == NIL){
            root = i;
        }
    }
    depth(root,0);
    height(root);
    for(i=0;i<n;i++){
        print(i);
    }
    return 0;
}

void depth(int k,int dn){
    if(k == NIL) return;
    node_depth[k] = dn;
    depth(node_all[k].left,dn+1);
    depth(node_all[k].right,dn+1);
}

int height(int k){
    int a = 0,b = 0,max;

    if(node_all[k].left != NIL){
        a = height(node_all[k].left) + 1;
    }
    if(node_all[k].right != NIL){
        b = height(node_all[k].right) + 1;
    }
    max = a;
    if(b > max){
        max = b;
    }
    node_height[k] = max;
    return node_height[k];
}

int info_sibling(int k){
    if(node_all[k].parent == NIL){
        return NIL;
    }
    if(node_all[node_all[k].parent].left != k && node_all[node_all[k].parent].left != NIL){
        return node_all[node_all[k].parent].left;
    }
    if(node_all[node_all[k].parent].right != k && node_all[node_all[k].parent].right != NIL){
        return node_all[node_all[k].parent].right;
    }
    return NIL;
}

void print(int k){
    int count = 0;
    
    printf("node %d: ",k);
    printf("parent = %d, ",node_all[k].parent);
    printf("sibling = %d, ",info_sibling(k));
    if(node_all[k].left != NIL){
        count++;
    }
    if(node_all[k].right != NIL){
        count++;
    }
    printf("degree = %d, ",count);
    printf("depth = %d, ",node_depth[k]);
    printf("height = %d, ",node_height[k]);

    if(node_all[k].parent == NIL){
        printf("root\n");
    }
    else if(node_all[k].left == NIL && node_all[k].right == NIL){
        printf("leaf\n");
    }
    else printf("internal node\n");
}
