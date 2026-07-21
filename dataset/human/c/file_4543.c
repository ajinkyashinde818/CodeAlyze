#include<stdio.h>

#define N 10000
#define NIL -1

struct Node {int parent,left,right;};

struct Node T[N];
void Depth(int , int );
int Height(int );
int Sibling(int );
void print(int );
int n,D[N],H[N];
int main(){
  int v,left,right,root=0;
  scanf("%d",&n);
  for(int i=0;i<n;i++)T[i].parent=NIL;

  for(int i;i<n;i++){
    scanf("%d%d%d",&v,&left,&right);
    T[v].left=left;
    T[v].right=right;
    if(left!=NIL)T[left].parent=v;
    if(right!=NIL)T[right].parent=v;}

  for(int i=0;i<n;i++)
    if(T[i].parent==NIL)root=i;

  Depth(root,0);
  Height(root);

  for(int i=0;i<n;i++)print(i);
  return 0;}

void Depth(int u, int d){
  if(u==NIL)return;
  D[u]=d;
  Depth(T[u].left,d+1);
  Depth(T[u].right,d+1);
}

int Height(int u){
  int h1=0,h2=0;
  if(T[u].left!=NIL)
    h1=Height(T[u].left)+1;
  if(T[u].right!=NIL)
  h2=Height(T[u].right)+1;
  return H[u]=(h1>h2?h1:h2);}

int Sibling(int u){
  if(T[u].parent==NIL)return NIL;
  if(T[T[u].parent].left!=u&&T[T[u].parent].left!=NIL)
    return T[T[u].parent].left;
  if(T[T[u].parent].right!=u&&T[T[u].parent].right!=NIL)
    return T[T[u].parent].right;
  return NIL;}

void print(int u){
  printf("node %d: ",u);
  printf("parent = %d, ",T[u].parent);
  printf("sibling = %d, ",Sibling(u));
  int deg=0;
  if(T[u].left!=NIL)deg++;
  if(T[u].right!=NIL)deg++;
  printf("degree = %d, ",deg);
  printf("depth = %d, ",D[u]);
  printf("height = %d, ",H[u]);

  if(T[u].parent==NIL){
    printf("root\n");
  }else if (T[u].left==NIL&&T[u].right==NIL){
    printf("leaf\n");
  }else{
    printf("internal node\n");
  }}
