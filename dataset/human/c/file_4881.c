#include<stdio.h>
#define MAX 100005
#define NIL -1

struct Node_struct{int p,l,r;};
typedef struct Node_struct Node;
Node T[MAX];
int D[MAX],G[MAX],Y[MAX];


void print(int u){
  int c;
  printf("node %d: parent = %d, ",u,T[u].p);

  c = siblingserch(u);
  printf("sibling = %d, ",c);
  
  printf("degree = %d, ",G[u]);
  
  printf("depth = %d, ",D[u]);

  printf("height = %d, ",Y[u]);
  
  if(T[u].p == -1) printf("root\n");
  else if(T[u].l == NIL && T[u].r == NIL) printf("leaf\n");
  else printf("internal node\n");

}

int siblingserch(int u)
{
  if(T[u].p == NIL)
    {
      return -1;
    }
  if(T[T[u].p].l != NIL && T[T[u].p].l != u)
    {
      return T[T[u].p].l;
    }
  if(T[T[u].p].r != NIL && T[T[u].p].r != u)
    {
      return T[T[u].p].r;
    }
  else
    {
      return -1;
    }
}

int calcheight(int u)
{
  int count1 = 0,count2 = 0;
  if(T[u].l != NIL)
    {
      count1 = calcheight(T[u].l) + 1;
    }
  if(T[u].r != NIL)
    {
      count2 = calcheight(T[u].r) + 1;
    }
  if(count1 > count2)
    {
      Y[u] = count1;
      return Y[u];
    }
  else
    {
      Y[u] = count2;
      return Y[u];
    }
  
}

void calcdegree(int u)
{
  if(T[u].l == NIL && T[u].r == NIL)
    {
      G[u] = 0;
    }
  else if(T[u].r != NIL && T[u].l == NIL)
    {
      G[u] = 1;
    }
  else if(T[u].r == NIL && T[u].l != NIL)
    {
      G[u] = 1;
    }
  else
    {
      G[u] = 2;
    }
}

void calcDepth(int u,int p){
  D[u] = p;
  if(T[u].l != NIL)calcDepth(T[u].l,p+1);
  if(T[u].r != NIL)calcDepth(T[u].r,p+1);
}


int main(){
  int i,l,r;
  int n;
  int id;
  int root = NIL;
  scanf("%d",&n);
  for(i = 0;i < n;i++)
    {
      T[i].p = T[i].l = T[i].r = NIL;
    }

  for(i = 0;i < n;i++)
    {
      scanf("%d",&id);
      scanf("%d %d",&l,&r);
      T[id].l = l;
      if(l != -1)
	{
	  T[l].p = id;
	}
      T[id].r = r;
      if(r != -1)
	{
	  T[r].p = id;
	}
    }

  for(i = 0;i < n;i++)
    {
      if(T[i].p == -1) root = i;
    }

  calcDepth(root,0);

  for(i = 0;i < n;i++)  calcdegree(i);

  for(i = 0;i < n;i++)  calcheight(i);


  for(i = 0;i < n;i++) print(i);

  return 0;
}
