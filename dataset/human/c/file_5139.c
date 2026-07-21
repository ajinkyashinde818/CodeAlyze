#include <stdio.h>
#include <stdlib.h>
  
typedef struct node{
    int p;
    int left;
    int right;
} Node;
  
int searchHight(int);
  
Node *trees;
  
int main(){
      
    int n,i,id,depth,tmpP,deg,nowNode,sibling;
  
    scanf("%d", &n);
  
    trees = malloc(sizeof(Node)*n);
  
    for (i = 0; i < n; ++i){
        trees[i].p = -1;
    }
  
    for (i = 0; i < n; ++i){
        scanf("%d",&id);
        scanf("%d%d",&trees[id].left,&trees[id].right);
	trees[trees[id].left].p = id;
	trees[trees[id].right].p = id;
    }
  
    nowNode = 0;
    while(1){
        if (trees[nowNode].left != -1 && trees[nowNode].right != -1)
        {
            break;
        } else if (trees[nowNode].left == -1)
        {
            nowNode = trees[nowNode].right;
        } else {
            nowNode = trees[nowNode].left;
        }
    }
  
    for (i = 0; i < n; ++i){
          
        tmpP = trees[i].p;
        if (tmpP == -1) sibling = -1;
        else if(trees[tmpP].left == i) sibling = trees[tmpP].right;
        else sibling = trees[tmpP].left;

        depth = 0;
        while(tmpP != -1){
            tmpP = trees[tmpP].p;
            depth++;
        }
  

        deg = 0;
        if (trees[i].left != -1) deg++;
        if (trees[i].right != -1) deg++;
  
        printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, "
            ,i,trees[i].p,sibling,deg,depth,searchHight(i));
  
        if(trees[i].p == -1) printf("root\n");
        else if(trees[i].left == -1 && trees[i].right == -1) printf("leaf\n");
        else printf("internal node\n");
    }
  
    return 0;
}
  
int searchHight(int index){
    int hLeft = 0;
    int hRight = 0;
  
    if (trees[index].left != -1){
        hLeft = searchHight(trees[index].left) +1;
    }
    if (trees[index].right != -1){
        hRight = searchHight(trees[index].right) +1;
    }
    if (hLeft < hRight) return hRight;
    else return hLeft;
}
