#include<stdio.h>
#define NIL -1
struct Node{
    int left;
    int right;
    int parent;
};
 
int sibling(int);
int children(int);
int depth(int);
int height(int);
void judge(int);

struct Node inputNodedata[10000];
 
int main(){
 
    int sumNode,Nodeid,i,j,leftdata,rightdata;
 
    scanf("%d",&sumNode);
    for(i = 0; i < sumNode; i++){
        inputNodedata[i].left = NIL;
        inputNodedata[i].right = NIL;
        inputNodedata[i].parent = NIL;
  }
  
    for(i = 0; i < sumNode; i++){
        scanf("%d",&Nodeid);
        scanf("%d",&leftdata);
        scanf("%d",&rightdata);
 
        inputNodedata[Nodeid].left = leftdata;
        inputNodedata[Nodeid].right = rightdata;
 
        if(leftdata != NIL) {
            inputNodedata[leftdata].parent = Nodeid; 
        }
 
        if(rightdata != NIL){
            inputNodedata[rightdata].parent = Nodeid;
 
        }
    }
 
    for(i = 0; i < sumNode; i++){
        printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ",i,inputNodedata[i].parent,sibling(i),children(i),depth(i),height(i));
        judge(i);
    }
 
    return 0;
 
}
 
 
int sibling(int Nodeid){ 
    if(inputNodedata[Nodeid].parent == NIL){
        return NIL;
    }

    else  if(inputNodedata[inputNodedata[Nodeid].parent].left != Nodeid && inputNodedata[inputNodedata[Nodeid].parent].left != NIL){
        return inputNodedata[inputNodedata[Nodeid].parent].left;
    }
 
    else if(inputNodedata[inputNodedata[Nodeid].parent].right != Nodeid && inputNodedata[inputNodedata[Nodeid].parent].right != NIL){
        return inputNodedata[inputNodedata[Nodeid].parent].right;
    }
 
    else {
        return NIL; 
    }
}
 
int children(int Nodeid){    
    int sumchild ;
    sumchild = 0;
    
    if(inputNodedata[Nodeid].left != NIL){
        sumchild = sumchild + 1;
    }
    
    if(inputNodedata[Nodeid].right != NIL){
        sumchild = sumchild + 1;
    }

    return sumchild;    
}
 
int depth(int Nodeid){
    int depth = 0;
    int id = inputNodedata[Nodeid].parent;

    while(id != NIL){
        id = inputNodedata[id].parent;
        depth = depth + 1;
    }

    return depth;
}
 
int height(int Nodeid){
    int leftheight=0,rightheight=0;
    
    if(inputNodedata[Nodeid].left != NIL){
        leftheight = height(inputNodedata[Nodeid].left) + 1;
    }
    
    if(inputNodedata[Nodeid].right != NIL){
        rightheight = height(inputNodedata[Nodeid].right) + 1;
    
    }
    
    if(leftheight > rightheight){
        return leftheight;    
    }
    
    else{
        return rightheight;
    }
    
}
    
    
void judge(int i){    
    if(inputNodedata[i].parent == NIL){
        printf("root\n");
    }
    
    else if(inputNodedata[i].left ==NIL && inputNodedata[i].right == NIL){
        printf("leaf\n");
    }
    
    else{
        printf("internal node\n");
    }
}
