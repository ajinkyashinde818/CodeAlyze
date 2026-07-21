#include <stdio.h>
#include <stdlib.h>
   
typedef struct node{
    int p;
    int left;
    int right;
} Node;

Node *node;

int searchHight(int index){
    int hleft = 0;
    int hright = 0;
   
    if (node[index].left != -1){
        hleft = searchHight(node[index].left) +1;
    }
    if (node[index].right != -1){
        hright = searchHight(node[index].right) +1;
    }
    if (hleft < hright) return hright;
    else return hleft;
}
   
int main(){
       
    int n,i,id,depth,tmp,deg,nownode,sibling;
   
    scanf("%d",&n);
   
    node = malloc(sizeof(Node)*n);
   
    for (i = 0; i < n; i++){
        node[i].p = -1;
    }
   
    for (i = 0; i < n; i++){
        scanf("%d",&id);
        scanf("%d%d",&node[id].left,&node[id].right);
        node[node[id].left].p = id;
        node[node[id].right].p = id;
    }
   
    nownode = 0;
    while(1){
        if(node[nownode].left != -1 && node[nownode].right != -1) break;
         else if(node[nownode].left == -1) nownode = node[nownode].right;
         else nownode = node[nownode].left;       
    }
   
    for (i = 0; i < n; i++){           
        tmp = node[i].p;
        if(tmp == -1) sibling = -1;
        else if(node[tmp].left == i) sibling = node[tmp].right;
        else sibling = node[tmp].left; 
        depth = 0;
        while(tmp != -1){
            tmp = node[tmp].p;
            depth++;
        }    
        deg = 0;
        if (node[i].left != -1) deg++;
        if (node[i].right != -1) deg++;   
        printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ",i,node[i].p,sibling,deg,depth,searchHight(i));   
        if(node[i].p == -1) printf("root\n");
        else if(node[i].left == -1 && node[i].right == -1) printf("leaf\n");
        else printf("internal node\n");
    }
    return 0;
}
