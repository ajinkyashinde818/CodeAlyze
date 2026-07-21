#include<stdio.h>

#define NIL -1

int depth(int);
int height(int);
int sibling(int);


struct Node{
  int parent;
  int left;
  int right;
};

struct Node T[25];

int main(){

  int n,id,left,right,i,de,deg,sib,hei;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    T[i].parent=NIL;
    T[i].right=NIL;
    T[i].left=NIL;
    
  }

  for(i=0;i<n;i++){

    scanf("%d%d%d",&id,&left,&right);

    T[id].left=left;
    T[id].right=right;
    T[left].parent=id;
    T[right].parent=id;
  }

  // printf("wa-i2\n");

  for(i=0;i<n;i++){


    if(T[i].left==NIL&&T[i].right==NIL){
      deg=0;
    }
    else if(T[i].left==-1||T[i].right==-1){
      deg=1;
    }
    else{
      deg=2;
    }

    de=depth(i);

    //printf("wa-i1\n");
    
    sib=sibling(i);

    // printf("wa-i4\n");
    hei=height(i);

    // printf("hei:%d\n",hei);
    
    // printf("wa-i3\n");
    
    printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ",i,T[i].parent,sib,deg,de,hei);

    if(T[i].parent==-1) printf("root\n");
    else if(T[i].right==NIL&&T[i].left==NIL) printf("leaf\n");
    else printf("internal node\n");

   
  }
  
  return 0;
}
  
int depth(int num){

  if(T[num].parent==NIL)return 0;

  return depth(T[num].parent)+1;
  
}


int sibling(int num){

  if(T[num].parent==NIL)return -1;

  if(num==T[T[num].parent].right) return T[T[num].parent].left;
  else return T[T[num].parent].right;

}

int height(int num){
  
  // printf("wa-i10\n");
  
  
  if(T[num].right==-1&&T[num].left==-1) return 0;

  else{
    if(T[num].left==-1){
      return height(T[num].right)+1;
    }
    else if(T[num].right==-1){
      return height(T[num].left)+1;
    }
  
    else if(height(T[num].right)<=height(T[num].left)){
      return height(T[num].left)+1;
    }
    else {
      return height(T[num].right)+1;
    }
  }
  
}
