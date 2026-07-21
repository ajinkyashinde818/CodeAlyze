#include <stdio.h>
#define MAX 25
#define N 100000
#define NIL -1
struct Node {
  int parent;
  int left;
  int right;
};
struct Node T[MAX];
int D[MAX];
int H[MAX];

void getDepth(int x,int y){
  if(x==NIL)return;
  D[x]=y;

  getDepth(T[x].right,y+1);

  getDepth(T[x].left,y+1);
}

int getHeight(int x){
  int a=0,b=0;
  if(T[x].right!=NIL)
    a=getHeight(T[x].right)+1;
  if(T[x].left!=NIL)
    b=getHeight(T[x].left)+1;
  if(a>b)
    H[x]=a;
  else
    H[x]=b;
  return H[x];
}

int getSibling(int x){
  int y;
  y=T[x].parent;
  if(T[x].parent==NIL)
    return NIL;
  if(T[y].right != x && T[y].right != NIL)
    return T[y].right;
  if(T[y].left != x && T[y].left != NIL)
    return T[y].left;
  return NIL;
}
  


int main(){
  int a,n,i,j,x;
  int id,left,right,y,root;
  int deg=0;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    T[i].parent=NIL;  
  }
    
  for(i=0;i<n;i++){
    scanf("%d%d%d",&id,&left,&right);
    T[id].left=left;
    T[id].right=right;
    if(left != NIL)
      T[left].parent=id;
    if(right != NIL)
      T[right].parent=id;
  }
  
  for(i=0;i<n;i++){
    if(T[i].parent==NIL)
      root=i;
  }
  
  getDepth(root,0);
  getHeight(root);

  
  
  for(i=0;i<n;i++){
    printf("node %d: parent = %d, sibling = %d, ",i,T[i].parent,getSibling(i));
    if(T[i].left!=NIL)
      deg++;
    if(T[i].right!=NIL)    
      deg++;
    printf("degree = %d, depth = %d, height = %d, ",deg,D[i],H[i]);
    deg=0;
    if(T[i].parent==NIL)
      printf("root\n");
    else if(T[i].left==NIL && T[i].right==NIL)
      printf("leaf\n");
    else
      printf("internal node\n");

  }

  return 0;
}
