#include<stdio.h>
#define NIL -1
#define MAX 10000
typedef struct{
  int p;
  int l;
  int r;
}Node;
Node T[MAX];
int n,D[MAX],H[MAX];
void setD(int,int);
int setH(int);
int getS(int);
void print(int);

void setD(int u,int d)
{
  if(u==NIL)return;
  D[u]=d;
  setD(T[u].l,d+1);
  setD(T[u].r,d+1);
}
int setH(int u)
{
  int h1=0,h2=0;
  if(T[u].l != NIL) h1 = setH(T[u].l)+1;
  if(T[u].r != NIL) h2 = setH(T[u].r)+1;
  if(h1>h2)H[u]=h1;
  else H[u]=h2;
  return H[u];
}
int getS(int u)
{
  if(T[u].p==NIL)return NIL;
  if(T[T[u].p].l != u && T[T[u].p].l != NIL)
    return T[T[u].p].l;
  if(T[T[u].p].r != u && T[T[u].p].r != NIL)
    return T[T[u].p].r;
  return NIL;
}
void print(int u)
{
  printf("node %d: ",u);
  printf("parent = %d, ",T[u].p);
  printf("sibling = %d, ",getS(u));
  int deg=0;
  if(T[u].l !=NIL)deg++;
  if(T[u].r != NIL)deg++;
  printf("degree = %d, ",deg);
  printf("depth = %d, ",D[u]);
  printf("height = %d, ",H[u]);

  if(T[u].p ==NIL){
    printf("root\n");
  }
  else if(T[u].l==NIL && T[u].r==NIL){
    printf("leaf\n");
  }
  else{
    printf("internal node\n");
  }
}
int main()
{
  int V,L,R,root=0,i;
  scanf("%d",&n);
  for(i=0;i<n;i++) T[i].p=NIL;

  for(i=0;i<n;i++){
    scanf("%d %d %d",&V,&L,&R);
    T[V].l=L;
    T[V].r=R;
    if(L != NIL)T[L].p=V;
    if(R != NIL)T[R].p=V;
  }
  for(i=0;i<n;i++){
    if(T[i].p==NIL)root=i;
  }
  setD(root, 0);
  setH(root);

  for(i=0;i<n;i++)print(i);

  return 0;
}
