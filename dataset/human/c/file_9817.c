#include <stdio.h>
#define NIL -1

typedef struct node{
  int pa;
  int l;
  int r;
}Tree;

Tree T[100000];
int t[100000];
int n;

void dep(int,int);
void print(int);

int main()
{
  int i,j,k,v,c,l,r;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    T[i].pa = NIL;
    T[i].l = NIL;
    T[i].r = NIL;
  }

  for(i=0;i<n;i++){
    scanf("%d%d",&v,&k);
    for(j=0;j<k;j++){
      scanf("%d",&c);
      if(j==0) T[v].l = c;
      else T[l].r = c;
      l = c;
      T[c].pa = v;
    }
  }

  for(i=0;i<n;i++){
    if(T[i].pa==NIL){
      r = i;
    }
  }

  dep(r,0);

  for(i=0;i<n;i++){
    print(i);
  }

  return 0;
}

void dep(int u,int p){
  t[u] = p;
  if(T[u].r!=NIL) dep(T[u].r,p);
  if(T[u].l!=NIL) dep(T[u].l,p+1);
}

void print(int u)
{
  int j,c;

  printf("node %d: parent = %d, depth = %d, ",u,T[u].pa,t[u]);
  if(T[u].pa==NIL) printf("root, ");
  else if(T[u].l==NIL) printf("leaf, ");
  else printf("internal node, ");
  printf("[");
  c = T[u].l;
  while(c!=NIL){
    printf("%d",c);
    if(T[c].r!=NIL) printf(", ");
    c = T[c].r;
  }
  printf("]\n");
}
