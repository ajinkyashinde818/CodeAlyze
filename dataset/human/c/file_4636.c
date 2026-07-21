#include<stdio.h>
  
#define MAX 10000
#define NIL -1
  
typedef struct{
  int parent,left,right;
}Node;
  
Node Ans[MAX];
int Depth[MAX],Height[MAX],n;
  
void calcDepth(int,int);
int calcHeight(int);
int getSibling(int);
void print(int);

void calcDepth(int u, int d){
  
  if(u == NIL)return;
  Depth[u] = d;
  calcDepth(Ans[u].left,d+1);
  calcDepth(Ans[u].right,d+1);
}
  
int calcHeight(int u){
  int h1,h2;
  
  h1 = h2 = 0;
  if(Ans[u].left != NIL)h1 = calcHeight(Ans[u].left) + 1;
  if(Ans[u].right != NIL)h2 = calcHeight(Ans[u].right) + 1;
  return Height[u] = (h1 > h2 ? h1 : h2); 
}
  
int getSibling(int u){
  
  if(Ans[u].parent == NIL)return NIL;

  if(Ans[Ans[u].parent].left != u && Ans[Ans[u].parent].left != NIL)
    return Ans[Ans[u].parent].left;

  if(Ans[Ans[u].parent].right != u && Ans[Ans[u].parent].right != NIL)
    return Ans[Ans[u].parent].right;

  return NIL;
}
  
void print(int u){
  int deg = 0;
  
  printf("node %d: parent = %d, sibling = %d, ",u,Ans[u].parent,getSibling(u));
  
  deg = 0;
  
  if(Ans[u].left != NIL)deg++;
  if(Ans[u].right != NIL)deg++;
  
  printf("degree = %d, depth = %d, height = %d, ",deg,Depth[u],Height[u]);
  
  if(Ans[u].parent == NIL)printf("root\n");
  else if(Ans[u].left == NIL && Ans[u].right == NIL)printf("leaf\n");
  else printf("internal node\n");
}

int main(){
  int i,node,left,right,root = 0;
  
  scanf("%d",&n);
   
  for(i=0;i<n;i++){
    Ans[i].parent = NIL;
  }
  for(i=0;i<n;i++){
    scanf("%d %d %d",&node,&left,&right);
    Ans[node].left = left;
    Ans[node].right = right;
    if(left != NIL)Ans[left].parent = node;
    if(right != NIL)Ans[right].parent = node;
  }
  
  for(i=0;i<n;i++){
    if(Ans[i].parent == NIL)root = i;
  }
   
  calcDepth(root,0);
  calcHeight(root);
  
  for(i=0;i<n;i++){
    print(i);
  }
  return 0;
}
