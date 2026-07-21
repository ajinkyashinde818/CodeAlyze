#include<stdio.h>
#define N 100000
#define NIL -1

typedef struct {
  int p;
  int left;
  int right;
}Node;

Node T[N];
int depth[N],height[N];

void Depth(int u,int d){
  if(u==NIL)return;
  depth[u]=d;
  Depth(T[u].left,d+1);
  Depth(T[u].right,d+1);
}

int Sibling(int u){
  if(T[u].p==NIL)return NIL;
  if(T[T[u].p].left!=u && T[T[u].p].left!=NIL)
    return T[T[u].p].left;
  if(T[T[u].p].right!=u && T[T[u].p].right!=NIL)
    return T[T[u].p].right;
  return NIL;
}

int Height(int u){
  int h1,h2;
  h1=h2=0;
  if(T[u].left!=NIL)
    h1=Height(T[u].left)+1;
  if(T[u].right!=NIL)
    h2=Height(T[u].right)+1;
  return height[u]=(h1>h2) ? h1 : h2;
}

void print(int id){
  int deg;
  printf("node %d: parent = %d, sibling = %d, ",id,T[id].p,Sibling(id));
  if(T[id].left!=NIL)deg++;
  if(T[id].right!=NIL)deg++;
  printf("degree = %d, depth = %d, height = %d, ",deg,depth[id],height[id]);
  if(T[id].p==NIL) printf("root\n");
  else if(T[id].left==NIL && T[id].right==NIL)
    printf("leaf\n");
  else printf("internal node\n");
}

int main(){
  int left,right,v,n,root=0,i;
  scanf("%d",&n);
  for(i=0;i<n;i++)
    T[i].p=T[i].left=T[i].right=NIL;
  
  for(i=0;i<n;i++){
    scanf("%d%d%d",&v,&left,&right);
    T[v].left=left;
    T[v].right=right;
    if(left!=NIL) T[left].p=v;
    if(right!=NIL) T[right].p=v;
  }
  
  for(i=0;i<n;i++)
    if(T[i].p==NIL)
      root=i;
  

  Depth(root,0);
  Height(root);

  for(i=0;i<n;i++)
    print(i);
  
  return 0;
}
