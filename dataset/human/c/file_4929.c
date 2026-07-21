#include<stdio.h>
#define MAX 10000
#define NIL -1

struct node{
  int p;
  int left;
  int right;
};
struct node T[MAX];
int n,D[MAX],H[MAX];

void setD(int u,int d){
  if(u==NIL)return;
  D[u]=d;
  setD(T[u].left,d+1);
  setD(T[u].right,d+1);
}

int setH(int u){
  int h1=0,h2=0;
  if(T[u].left!=NIL)h1=setH(T[u].left)+1;
  if(T[u].right!=NIL)h2=setH(T[u].right)+1;
  return H[u]=(h1>h2 ? h1 : h2);
}

int getS(int u){
  if(T[u].p==NIL)return NIL;
  if(T[T[u].p].left != u && T[T[u].p].left!=NIL)return T[T[u].p].left;
  if(T[T[u].p].right != u && T[T[u].p].right!=NIL)return T[T[u].p].right;
  return NIL;
}

void print(int u){
  printf("node %d: ",u);
  printf("parent = %d, ",T[u].p);
  printf("sibling = %d, ",getS(u));
  int deg=0;
  if(T[u].left!=NIL)deg++;
  if(T[u].right!=NIL)deg++;
  printf("degree = %d, ",deg);
  printf("depth = %d, ",D[u]);
  printf("height = %d, ",H[u]);

if(T[u].p==NIL){
  printf("root\n");
}
else if(T[u].left==NIL && T[u].right == NIL){
  printf("leaf\n");
}
else{
  printf("internal node\n");
}
}

int main(){
  int i,v,l,r,root=0;
  scanf("%d",&n);
  for(i=0;i<n;i++)T[i].p=NIL;
  for(i=0;i<n;i++){
    scanf("%d%d%d",&v,&l,&r);
    T[v].left=l;
    T[v].right=r;
    if(l!=NIL)T[l].p=v;
    if(r!=NIL)T[r].p=v;
  }
for(i=0;i<n;i++)if(T[i].p==NIL)root=i;
setD(root,0);
setH(root);

for(i=0;i<n;i++)print(i);
return 0;
}
