#include <stdio.h>
#define N 100000
#define NIL -1
int Depth(int );
void display(int );
int getsibling(int );
int getheight(int );
struct Node {
  int parent;
  int left;
  int right;
};

struct Node T[N];
int n,D[N];

int main()
{
  int a,b,c,i,l,m;
  scanf("%d",&n);
  for(i=0;i<n;i++)
    {
      T[i].parent=NIL;
      T[i].left=NIL;
      T[i].right=NIL;
    }
  
  for(i=0;i<n;i++)
    {
      scanf("%d%d%d",&a,&b,&c);
      T[a].left=b;
      T[a].right=c;
      if(b!=NIL) T[b].parent=a;
      if(c!=NIL) T[c].parent=a;
    }
  for(i=0;i<n;i++)
    {
      D[i]=Depth(i);
    }
  for(i=0;i<n;i++)
    {
      display(i);
    }
  return 0;
}

int Depth(int a)
{
  int d=0;
  while(T[a].parent!=-1)
    {
      a=T[a].parent;
      d++;
    }
  return d;
}
int getsibling(int x)
{
  if(T[x].parent==NIL) return NIL;
  if(T[T[x].parent].left!=x&&T[T[x].parent].left!=NIL) return T[T[x].parent].left;
  if(T[T[x].parent].right!=x&&T[T[x].parent].right!=NIL) return T[T[x].parent].right;
  else return NIL;
}
int getheight(int x)
{
  int height1=0,height2=0;
  if(T[x].left!=NIL) height1=getheight(T[x].left)+1;
  if(T[x].right!=NIL) height2=getheight(T[x].right)+1;
  if(height1>=height2) return height1;
  else return height2;
}
void display(int x)
{
  int i,j,deg=0;
  if(T[x].left!=NIL) deg++;
  if(T[x].right!=NIL) deg++;
  printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ",x,T[x].parent,getsibling(x),deg,D[x],getheight(x));
  if(T[x].parent==NIL) printf("root\n");
  else if(T[x].left==NIL&&T[x].right==NIL) printf("leaf\n");
  else printf("internal node\n");  
}
