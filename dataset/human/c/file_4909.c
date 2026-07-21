#include<stdio.h>
#define MAX 100000
#define NIL -1

struct Node_struct{int p, l, r, s;}; 
typedef struct Node_struct Node;

void print(int );
void calcDepth(int ,int );
int Height(int );
int sib(int );

Node T[MAX];
int D[MAX],H[MAX];

int main()
{
  int i,l,r,n,id,root = NIL;
  scanf("%d",&n);
  for(i = 0;i < n;i++) T[i].p = T[i].l = T[i].r = NIL;
  for(i = 0;i < n;i++)
    {
      scanf("%d %d %d",&id,&l,&r);
      T[r].p = T[l].p = id;
      T[id].l = l;
      T[id].r = r;
    }
  for(i=0; i<n; i++)
    {
      if(T[i].p == -1) root = i;
    }
  calcDepth(root, 0);
  Height(root);

  for(i = 0;i < n;i++) print(i);
  
  return 0;
}
void calcDepth(int u, int p)
{
  if(u == NIL) return;
  D[u] = p;
  calcDepth(T[u].r,p + 1);
  calcDepth(T[u].l,p + 1);
}
void print(int u)
{
  int deg = 0;
  printf("node %d: parent = %d, sibling = %d, ", u, T[u].p,sib(u));
  if( T[u].l != NIL)deg++;
  if( T[u].r != NIL)deg++;
  printf("degree = %d, ",deg);
  printf("depth = %d, height = %d, ",D[u],H[u]);
  if(T[u].p == NIL) printf("root");
  else if(T[u].l == NIL && T[u].r == NIL) printf("leaf");
  else printf("internal node");
  printf("\n");
}
int Height(int u)
{
  int a = 0,b = 0;
  if(T[u].l != NIL)
    {
      a = Height(T[u].l) + 1;
    }
  if(T[u].r != NIL)
    {
      b = Height(T[u].r) + 1;
    }
  if(a > b) return H[u] = a;
  else return H[u] = b;
}
int sib(int u)
{
  if(T[u].p == NIL) return NIL;
  if(T[T[u].p].l != u && T[T[u].p].l != NIL) return T[T[u].p].l;
  if(T[T[u].p].r != u && T[T[u].p].r != NIL) return T[T[u].p].r;
  return NIL;
}
