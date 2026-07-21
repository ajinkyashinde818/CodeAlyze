#include <stdio.h>
#define MAX 100000
#define NIL -1

struct Node{
    int parent,right,left;
    int sibling,deg;
};

int getDepth(struct Node *,int);
int getHeight(struct Node *,int);

int main(){
    int n,m;
    int id,c,tmp;
    int right,left;
    int depth[MAX];
    int height[MAX];

    struct Node TREE[MAX];

    scanf("%d",&n);
    for(int i = 0;i < n;i++){
        TREE[i].parent = TREE[i].left = TREE[i].right = TREE[i].sibling = NIL;
        TREE[i].deg = 0;
    }

    for(int i = 0;i < n;i++){
        scanf("%d",&id);
        scanf("%d%d",&right,&left);
        //j == 0の時は、子供ではなく親となるノードなので
        if(right != NIL && left != NIL){
            TREE[id].deg = 2;
            TREE[id].right = right;
            TREE[id].left = left;
            TREE[right].parent = id;
            TREE[left].parent = id;                
            TREE[right].sibling = left;
            TREE[left].sibling = right;
        }
        else if(right != NIL && left == NIL){
            TREE[id].deg = 1;
            TREE[id].right = right;
            TREE[right].parent = id;
            TREE[right].sibling = NIL;
        }
        else if(right == NIL && left != NIL){
            TREE[id].deg = 1;
            TREE[id].left = left;
            TREE[left].parent = id;
            TREE[left].sibling = NIL;
        }
    }
    for(int i = 0;i < n;i++){
        depth[i] = getDepth(TREE,i);
        height[i] = getHeight(TREE,i);
    }

    for(int i = 0; i < n; i++){
        printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ", i, TREE[i].parent,TREE[i].sibling,TREE[i].deg, depth[i],height[i]);
        //親がいなかったら
        if(TREE[i].parent == NIL){
            printf("root");
        }
        // 子供がいなかったら
        else if(TREE[i].left == NIL && TREE[i].right == NIL){
            printf("leaf");
        }
        // どちらでもない時
        else{
            printf("internal node");
        }
        printf("\n");  
    }

    return 0;
}

int getDepth(struct Node *TREE,int i){
    if(TREE[i].parent == NIL)return 0;
    return getDepth(TREE,TREE[i].parent) + 1;
}

int getHeight(struct Node *TREE,int i){
    int count1 = 0,count2 = 0;

    if(TREE[i].left != NIL)count1 = getHeight(TREE,TREE[i].left) + 1;
    if(TREE[i].right != NIL)count2 = getHeight(TREE,TREE[i].right) + 1;

    return ((count1 >= count2)? count1:count2);
}
