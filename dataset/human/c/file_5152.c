#include <stdio.h>
#define MAX 25
struct Node{
  int parent;
  int right;
  int left;
  int degree;
};
int n;
struct Node u[MAX];
int s(int);
int d(int);
int h(int);

int s(int x){
  if(u[x].right!=-1) return u[x].right;
  else if(u[u[x].parent].left!=x) return u[u[x].parent].left;
  else return -1;
}
 
int d(int x){
  int d=0,p;
  p=u[x].parent;
 
  while(p!=-1){
    p=u[p].parent;
    d++;
  }
 
  return d;
}
int h(int x) {
  int i,a=0,y;
  
  for(i=0;i<n;i++) {
    if(u[i].parent==x) {
      y=h(i)+1;
      if(y>a) a=y;
    }
  }
  return a;
}

int main(){
  int i,id,r,l;
 
  scanf("%d",&n);
 
  for(i=0;i<n;i++){
    u[i].parent=-1;
    u[i].right=-1;
    u[i].left=-1;
    u[i].degree=0;
  }
 
  for(i=0;i<n;i++){
    scanf("%d%d%d",&id,&l,&r);
    u[id].left=l;
    u[u[id].left].right=r;
    if(u[id].left!=-1){
      u[u[id].left].parent=id;
      u[id].degree++;
    }
    if(u[u[id].left].right!=-1){
      u[u[u[id].left].right].parent=id;
      u[id].degree++;
    }
  }
 
  for(i=0;i<n;i++){
    if(u[i].parent==-1)
      printf("node %d: parent = -1, sibling = -1, degree = %d, depth = 0, height = %d, root\n",i,u[i].degree,h(i));
 
    else if(u[i].degree==0)
      printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, leaf\n",i,u[i].parent,s(i),u[i].degree,d(i),h(i));
 
    else printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, internal node\n",i,u[i].parent,s(i),u[i].degree,d(i),h(i));
  }
 
  return 0;
}
