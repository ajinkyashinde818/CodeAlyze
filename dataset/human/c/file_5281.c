#include <stdio.h>
#define MAX 25
struct Node{
  int parent;
  int right;
  int left;
  int degree;
};
int n;
struct Node U[MAX];
int sib(int);
int dep(int);
int hei(int);
 
int sib(int x){
  if(U[x].right!=-1) return U[x].right;
  else if(U[U[x].parent].left!=x) return U[U[x].parent].left;
  else return -1;
}
int hei(int x) {
  int i,a=0,y;
   
  for(i=0;i<n;i++) {
    if(U[i].parent==x) {
      y=hei(i)+1;
      if(y>a) a=y;
    }
  }
  return a;
}  
int dep(int x){
  int d=0,p;
  p=U[x].parent;
  
  while(p!=-1){
    p=U[p].parent;
    d++;
  }
  
  return d;
}

 
int main(){
  int i,id,r,l;
  
  scanf("%d",&n);
  
  for(i=0;i<n;i++){
    U[i].parent=-1;
    U[i].right=-1;
    U[i].left=-1;
    U[i].degree=0;
  }
  
  for(i=0;i<n;i++){
    scanf("%d%d%d",&id,&l,&r);
    U[id].left=l;
    U[U[id].left].right=r;
    if(U[id].left!=-1){
      U[U[id].left].parent=id;
      U[id].degree++;
    }
    if(U[U[id].left].right!=-1){
      U[U[U[id].left].right].parent=id;
      U[id].degree++;
    }
  }
  
  for(i=0;i<n;i++){
    if(U[i].parent==-1)
      printf("node %d: parent = -1, sibling = -1, degree = %d, depth = 0, height = %d, root\n",i,U[i].degree,hei(i));
  
    else if(U[i].degree==0)
      printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, leaf\n",i,U[i].parent,sib(i),U[i].degree,dep(i),hei(i));
  
    else printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, internal node\n",i,U[i].parent,sib(i),U[i].degree,dep(i),hei(i));
  }
  
  return 0;
}
