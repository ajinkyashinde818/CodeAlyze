#include<stdio.h>
#define MAX 10000
typedef struct{int parent,left,right;}Node;
 
Node T[MAX];
int n,D[MAX],H[MAX];
 
void setDepth(int u,int d){
  if(u == EOF)return;
  D[u] = d;
  setDepth(T[u].left,d+1);
  setDepth(T[u].right,d+1);
}
 
int setHeight(int u){
  int h1=0,h2=0;
  if(T[u].left != EOF) h1 = setHeight(T[u].left) + 1;
  if(T[u].right != EOF)h2 = setHeight(T[u].right) + 1;
  return H[u] = (h1 > h2 ? h1 : h2); 
}
 
int getSibling(int u){
  if(T[u].parent == EOF)return EOF;
  if(T[T[u].parent].left != u && T[T[u].parent].left != EOF)
    return T[T[u].parent].left;
  if(T[T[u].parent].right != u && T[T[u].parent].right != EOF)
    return T[T[u].parent].right;
  return EOF;
}
 
void print(int u){
  int deg;
   
  printf("node %d: parent = %d, sibling = %d, ",u,T[u].parent,getSibling(u));
  deg = 0;
  if(T[u].left != EOF)deg++;
  if(T[u].right != EOF)deg++;
  printf("degree = %d, depth = %d, height = %d, ",deg,D[u],H[u]);
  if(T[u].parent == EOF)printf("root\n");
  else if(T[u].left == EOF && T[u].right == EOF)printf("leaf\n");
  else printf("internal node\n");
}
 
int main(){
  int i,v,l,r,root = 0;
  scanf("%d",&n);
  for(i=0;i<n;i++) T[i].parent = EOF;
   
  for(i=0;i<n;i++){
    scanf("%d %d %d",&v,&l,&r);
    T[v].left = l;
    T[v].right = r;
    if(l != EOF)T[l].parent = v;
    if(r != EOF)T[r].parent = v;
  }
   
  for(i=0;i<n;i++) if(T[i].parent == EOF)root = i;
   
  setDepth(root,0);
  setHeight(root);
   
  for(i=0;i<n;i++) print(i);
   
  return 0;
}
