#include <stdio.h>
#define NIL -1
void dep(int u,int k);
int high(int u);
int sib(int u);
void print(int u);

typedef struct Node{
  int p;
  int l;
  int r;
} node;
  
node T[10005];
int n,Dp[10005],H[10005];

int main(){
  int i,j;
  int v,root=0,left,right;

  scanf("%d",&n);
  //ini
  for(i=0;i<n;i++) T[i].p=-1;
  
  //input
  for(i=0;i<n;i++){
    scanf("%d%d%d",&v,&left,&right); 
    T[v].l=left;
    T[v].r=right;
    if(left!=NIL) T[left].p=v;
    if(right!=NIL) T[right].p=v;
  }

  for(i=0;i<n;i++){
    if(T[i].p==NIL) root=i;
  }

  dep(root,0);
  high(root);

  for(i=0;i<n;i++) print(i);

  return 0;
}

void dep(int u,int k){  
  //calc depth
  if(u==NIL) return;  
  Dp[u]=k;
  dep(T[u].r,k+1);
  dep(T[u].l,k+1);
}

int high(int u){
  int h,x=0,y=0;

  //calc height(left,right)
  if(T[u].l!=NIL) x=high(T[u].l)+1;
  if(T[u].r!=NIL) y=high(T[u].r)+1;

  //get bigger value(left,right)
  if(x<y) H[u]=y; 
  else H[u]=x;

  return H[u];
}

int sib(int u){
  if(T[u].p==NIL) return NIL;
  if(T[T[u].p].l!=u && T[T[u].p].l!=NIL) return T[T[u].p].l;
  if(T[T[u].p].r!=u && T[T[u].p].r!=NIL) return T[T[u].p].r;
  return NIL;
}

void print(int u){
  int dg=0;

  printf("node %d: ",u);
  printf("parent = %d, ",T[u].p);
  printf("sibling = %d, ",sib(u));

  if(T[u].l!=NIL) dg++;
  if(T[u].r!=NIL) dg++;
  printf("degree = %d, ",dg);
  printf("depth = %d, ",Dp[u]);
  printf("height = %d, ",H[u]);

  if(T[u].p==NIL) printf("root\n");
  else if(T[u].l==NIL && T[u].r==NIL) printf("leaf\n");
  else printf("internal node\n");
}
