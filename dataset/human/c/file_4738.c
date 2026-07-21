#include<stdio.h>

#define MAX 10000
#define NIL -1

typedef struct node_{
  int p,l,r;
}node;

struct node_ T[MAX];
int n,D[MAX],H[MAX];

void setDepth(int, int);
int setHeight(int);
int getSibling(int);
void print(int);

int main() {
  int i,v,l,r,root=0;
  scanf("%d",&n);

  for(i=0;i<n;i++) T[i].p=NIL;

  for(i=0;i<n;i++)
  {
    scanf("%d %d %d",&v,&l,&r);
    T[v].l=l;
    T[v].r=r;
    if(l!=NIL) T[l].p=v;
    if(r!=NIL) T[r].p=v;
  }

  for(i=0;i<n;i++)
  {
    if(T[i].p==NIL) root =i;
  }

  setDepth(root,0);
  setHeight(root);

  for(i=0;i<n;i++) print(i);

  return 0;
}

void setDepth(int x, int d){
  if(x ==NIL) return;

  D[x]= d;
  setDepth(T[x].l,d+1);
  setDepth(T[x].r,d+1);
}

int setHeight(int x){
  int H1=0,H2=0;

  if(T[x].l!=NIL) H1=setHeight(T[x].l)+1;
  if(T[x].r!=NIL) H2=setHeight(T[x].r)+1;

  return H[x]=(H1>H2 ? H1 : H2);
}

int getSibling(int x){
  if(T[x].p==NIL) return NIL;
  if(T[T[x].p].l!=x && T[T[x].p].l!=NIL) return T[T[x].p].l;
  if(T[T[x].p].r!=x && T[T[x].p].r!=NIL) return T[T[x].p].r;

  return NIL;
}

void print(int x){
  int deg = 0;
  printf("node %d: ",x);
  printf("parent = %d, ",T[x].p);
  printf("sibling = %d, ",getSibling(x));

  if(T[x].l!=NIL) deg++;
  if(T[x].r!=NIL) deg++;
  printf("degree = %d, ",deg);
  printf("depth = %d, ",D[x]);
  printf("height = %d, ",H[x]);

  if(T[x].p ==NIL) printf("root\n");
  else if(T[x].l ==NIL && T[x].r == NIL) printf("leaf\n");
  else printf("internal node\n");


}
