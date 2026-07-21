#include<stdio.h>

#define M 100005

 

int n;
  int A[M];
int B[M];
int C[M];
int DG[M];
 struct Node{ int p, l, r;};
struct Node 
Tree[M];

int getHeight(int u,int left,int right){
 
  if(Tree[u].l == -1 && Tree[u].r == -1) return 0;
   
  if(Tree[u].l != -1){ 
    left = getHeight(Tree[u].l,left,0)+1;
  }
  if(Tree[u].r != -1){
 right = getHeight(Tree[u].r,0,right)+1;
  } 
  if(left > right) {
    return left;
  }
  else{
    return right;
  }
}
 
int getDepth(int u){
  int d = 0;
  int i = 0;
  while(1){
    if(Tree[u].p == -1) break;
    d++;
    u = Tree[u].p;
  }
  return d;
}
 

 
void print(int u){
   
  printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, "

,u,Tree[u].p, C[u],DG[u], B[u], A[u]);
   
  if( Tree[u].p == -1) printf("root\n");
  else if(Tree[u].l == -1 && Tree[u].r == -1) {
    printf("leaf\n");
  }
  else{
    printf("internal node\n");
  }
}
 
 
main(){
  int i=0, j=0;
  int v, l;
  
   
  scanf("%d", &n);
   
  while(i < n){
    Tree[i].p =-1;
      Tree[i].l =-1;
 Tree[i].r = -1;

    i++;
  }


  i = 0;   
  while(i < n){
    scanf("%d",&v);
    scanf("%d %d",&Tree[v].l,&Tree[v].r);
    Tree[Tree[v].l].p = v;
    Tree[Tree[v].r].p = v;
    i++;
  }

  i=0;


  while(i < n){
    C[i] = getSibling(i);
    DG[i] = getDegree(i);
    B[i] = getDepth(i);
    A[i] = getHeight(i,0,0);
    i++;
  }  
     
  for ( i = 0; i < n; i++ ){

 print(i);

  }
  return 0;
}


int getDegree(int u){
  if((Tree[u].l == -1) && (Tree[u].r == -1)) return 0;
  else if((Tree[u].l == -1) || (Tree[u].r == -1)) return 1;
  else return 2;
}
 
int getSibling(int u){
   
   
  if(Tree[u].p == -1) return -1;
   
  else if(Tree[Tree[u].p].l != u){ 
    return Tree[Tree[u].p].l;  
  }
   
  else { 
    return Tree[Tree[u].p].r;  
  }
}
