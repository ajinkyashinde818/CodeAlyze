#include <stdio.h>
#include <stdlib.h>
 
typedef struct node{
    int p;
    int left;
    int right;
} Node;
 
int searchHight(int);
 
Node *tree;
 
int main(){
     
    int n,i,id,depth,tmpP,deg,nowNode,sibling;
 
    scanf("%d", &n);
 
    tree = malloc(sizeof(Node)*n);
 
    for (i = 0; i < n; ++i){
        tree[i].p = -1;
    }
 
    for (i = 0; i < n; ++i){
        scanf("%d",&id);
        scanf("%d%d",&tree[id].left,&tree[id].right);
        tree[tree[id].left].p = id;
        tree[tree[id].right].p = id;
    }
 
    nowNode = 0;
    while(1){
        if (tree[nowNode].left != -1 && tree[nowNode].right != -1)
        {
            break;
        } else if (tree[nowNode].left == -1)
        {
            nowNode = tree[nowNode].right;
        } else {
            nowNode = tree[nowNode].left;
        }
    }
 
    for (i = 0; i < n; ++i){
         
        tmpP = tree[i].p;
        if (tmpP == -1) sibling = -1;
        else if(tree[tmpP].left == i) sibling = tree[tmpP].right;
        else sibling = tree[tmpP].left;
 
        depth = 0;
        while(tmpP != -1){
            tmpP = tree[tmpP].p;
            depth++;
        }
 
        deg = 0;
        if (tree[i].left != -1) deg++;
        if (tree[i].right != -1) deg++;
 
        printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ",i,tree[i].p,sibling,deg,depth,searchHight(i));
 
        if(tree[i].p == -1) printf("root\n");
        else if(tree[i].left == -1 && tree[i].right == -1) printf("leaf\n");
        else printf("internal node\n");
    }
 
    return 0;
}
 
int searchHight(int index){
    int hLeft = 0;
    int hRight = 0;
 
    if (tree[index].left != -1){
        hLeft = searchHight(tree[index].left) +1;
    }
    if (tree[index].right != -1){
        hRight = searchHight(tree[index].right) +1;
    }
    if (hLeft < hRight) return hRight;
    else return hLeft;
}
