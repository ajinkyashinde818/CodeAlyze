#include<stdio.h>
void print(int);
int rec(int ,int);
#define Max 100000
#define NIL -1
int A[Max];
struct Node{
  int p;
  int l;
  int r;
    };
 
struct Node T[Max];
int n;
int main()
{ 
  int child,h,i,v,e,depth,l,r;
 
  scanf("%d",&n);
  for(i=0;i<n;i++) T[i].p=T[i].l=T[i].r=NIL;
 
  for(i=0;i<n;i++)
    {
      scanf("%d%d",&v,&depth);
       
      for(h=0;h<depth;h++)
    {
      scanf("%d",&child);
      if(h==0)T[v].l=child;
      else T[l].r=child;
      l=child;
      T[child].p=v;
    }
    }
  for(i=0;i<n;i++)
    {
      if(T[i].p==NIL) r=i;
    }
 
  rec(r,0);
 
  for(i=0;i<n;i++) print(i);
 
  return 0;
}
 
int rec(int u, int p)
{
  A[u]=p;
  if(T[u].r!=NIL) rec(T[u].r,p);
  if(T[u].l!=NIL) rec(T[u].l,p+1);
}
 
void print(int u)
{
  int i,child;
  printf("node %d: ",u);
  printf("parent = %d, ",T[u]);
  printf("depth = %d, ",A[u]);
 
  if(T[u].p==NIL) printf("root, ");
  else if(T[u].l==NIL)  printf("leaf, ");
  else printf("internal node, ");
 
  printf("[");
 
  child=T[u].l;
  for(i=0;child!=NIL;i++){
    if(i) printf(", ");
    printf("%d",child);
    child=T[child].r;
  }
  printf("]\n");
}
