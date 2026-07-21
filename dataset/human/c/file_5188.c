#include<stdio.h>
#define NIL -1
#define MAX 10000

int setHeight(int );
void setDepth(int ,int );
int getSibling(int );
void print(int );

typedef struct{
  int p,l,r;
}Node;

Node T[MAX];
int D[MAX],H[MAX],n;

int main(){
  int i;
  int a,b,c;
  int root=0;
  
  scanf("%d",&n);

  for(i=0;i<n;i++) T[i].p=NIL;

  for(i=0;i<n;i++){
    scanf("%d%d%d",&a,&b,&c);
    T[a].l=b;
    T[a].r=c;
    if(b != NIL) T[b].p=a;
    if(c != NIL) T[c].p=a;
  }
  for(i=0;i<n;i++) if(T[i].p==NIL) root=i;

  setDepth(root,0);
  setHeight(root);

  for(i=0;i<n;i++) print(i);

  return 0;
}

int setHeight(int u){
  int h1=0,h2=0;
  if(T[u].l!=NIL) h1=setHeight(T[u].l)+1;
  if(T[u].r!=NIL) h2=setHeight(T[u].r)+1;
  return H[u]=(h1>h2 ? h1:h2);
}
void setDepth(int u,int d){
  if(u==NIL) return;
  D[u]=d;
  setDepth(T[u].l,d+1);
  setDepth(T[u].r,d+1);
}
int getSibling(int u){
  if(T[u].p==NIL) return NIL;
  if(T[T[u].p].l !=u &&T[T[u].p].l!=NIL) return T[T[u].p].l;
  if(T[T[u].p].r!=u &&T[T[u].p].r!=NIL) return T[T[u].p].r;
  return NIL;
 }
void print(int u){
  printf("node %d: parent = %d, sibling = %d",u,T[u].p,getSibling(u));
  int degr=0;
  if(T[u].l!=NIL) degr++;
  if(T[u].r!=NIL) degr++;
  printf(", degree = %d, depth = %d, height = %d",degr,D[u],H[u]);
  if(T[u].p==NIL) printf(", root");
  else if(T[u].l==NIL && T[u].r==NIL) printf(", leaf");
  else printf(", internal node");
  printf("\n");
    }
