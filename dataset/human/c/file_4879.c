#include <stdio.h>
#define N 25
#define NIL -1

typedef struct{
  int p,l,r;
} Node_t;

Node_t T[N];
int n,D[N],H[N];

void setDep(int u, int d){ //??±?????\???
  if(u==NIL) return;
  D[u]=d;
  setDep(T[u].l,d+1);
  setDep(T[u].r,d+1);
}

int setHe(int u){ //????????\???
  int h1=0,h2=0;
  if(T[u].l!=NIL) h1=setHe(T[u].l)+1;
  if(T[u].r!=NIL) h2=setHe(T[u].r)+1;
  if(h1>h2) H[u]=h1;
  else H[u]=h2;
  return H[u];
}

int getSib(int u){ //??????????????±?????????
  if(T[u].p==NIL) return NIL;
  if(T[T[u].p].l!=u&&T[T[u].p].l!=NIL) return T[T[u].p].l;
  if(T[T[u].p].r!=u&&T[T[u].p].r!=NIL) return T[T[u].p].r;
  return NIL;
}

void output(int u){
  int zisu=0;
  printf("node %d: parent = %d, sibling = %d, ",u,T[u].p,getSib(u));
  if(T[u].l!=NIL) zisu++;
  if(T[u].r!=NIL) zisu++;
  printf("degree = %d, depth = %d, height = %d, ",zisu,D[u],H[u]);
  if(T[u].p==NIL) printf("root\n");
  else if(T[u].l==NIL&&T[u].r==NIL) printf("leaf\n"); //???????????????
  else printf("internal node\n");
}

int main(){
  int id,l,r,root=0,i;
  scanf("%d",&n);
  for(i=0;i<n;i++) T[i].p=NIL;
  for(i=0;i<n;i++){
    scanf("%d%d%d", &id,&l,&r);
    T[id].l=l;
    T[id].r=r;
    if(l!=NIL) T[l].p=id;
    if(r!=NIL) T[r].p=id;
  }

for(i=0;i<n;i++) if(T[i].p==NIL) root=i;

setDep(root, 0);
setHe(root);

for(i=0;i<n;i++) output(i);

return 0;
}
