#include <stdio.h>
#include <stdlib.h>
#include<math.h>
 
typedef struct node{
    int p;
    int left;
    int right;
} Node;
 
int searchHight(int);
 
Node *node;
 
int main(){
     
    int n,i,id,depth,tmp,deg,sibling;
    int now;
    scanf("%d", &n);
 
    node = (int *)malloc(sizeof(Node)*n);
 
    for (i = 0; i < n; ++i){
        node[i].p = -1;
    }
 
    for (i = 0; i < n; i++){
        scanf("%d",&id);
        scanf("%d%d",&node[id].left,&node[id].right);
        node[node[id].left].p = id;
        node[node[id].right].p = id;
    }
 
    now = 0;
    while(1){
        if (node[now].left != -1 && node[now].right != -1)
        {
            break;
        } else if (node[now].left == -1)
        {
            now = node[now].right;
        } else {
            now = node[now].left;
        }
    }
 
    //Search
    for (i = 0; i < n; ++i){
         
        //sibling
        tmp = node[i].p;
        if (tmp == -1) sibling = -1;
        else if(node[tmp].left == i) sibling = node[tmp].right;
        else sibling = node[tmp].left;
 
        //depth
        depth = 0;
        while(tmp != -1){
            tmp = node[tmp].p;
            depth++;
        }
 
        //degree
        deg = 0;
        if (node[i].left != -1) deg++;
        if (node[i].right != -1) deg++;
 
        printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, "
            ,i,node[i].p,sibling,deg,depth,searchHight(i));
 
        if(node[i].p == -1) printf("root\n");
        else if(node[i].left == -1 && node[i].right == -1) printf("leaf\n");
        else printf("internal node\n");
    }
 
    return 0;
}
 
int searchHight(int index){
    int hLeft = 0;
    int hRight = 0;
 
    if (node[index].left != -1){
        hLeft = searchHight(node[index].left) +1;
    }
    if (node[index].right != -1){
        hRight = searchHight(node[index].right) +1;
    }
    if (hLeft < hRight) return hRight;
    else return hLeft;
}
