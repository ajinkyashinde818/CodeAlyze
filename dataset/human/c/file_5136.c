#include<stdio.h>
#define MAX 100005
#define NIL -1

typedef struct{
  int p,l,r;
}Node;

Node T[MAX];
int D[MAX],S[MAX],E[MAX],H[MAX];

void print(int u){
  printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ",u,T[u].p,calcSibling(u),E[u],D[u],H[u]);

  if(T[u].p == NIL)printf("root\n");
  else if(T[u].l == NIL && T[u].r == NIL)printf("leaf\n");
  else printf("internal node\n");
}

void calcDepth(int u, int p){
  D[u] = p;
  if(T[u].r != NIL) calcDepth(T[u].r,p+1);
  if(T[u].l != NIL) calcDepth(T[u].l,p+1);
}

void calcDegree(int u){
  if(T[u].l == NIL && T[u].r == NIL)E[u] = 0;
  else if(T[u].r == NIL || T[u].l == NIL)E[u] = 1;
  else E[u] = 2;
}

int  calcSibling(int u){
  if(T[u].p == NIL)return NIL;
  if(T[T[u].p].l != NIL && T[T[u].p].l != u)return T[T[u].p].l;
  if(T[T[u].p].r != NIL && T[T[u].p].r != u)return T[T[u].p].r;
  return NIL; 
}

int calcHeight(int u){
  int H1=0,H2=0;
  if(T[u].l != NIL){
    H1 = 1 + calcHeight(T[u].l);
  }
  if(T[u].r != NIL){
    H2 = 1 + calcHeight(T[u].r);
  }
  if(H1 < H2){
    H[u] = H2;
    return H[u];
  }
  else{
    H[u] = H1;
    return H[u];
  }
}

int main(){
  int n,id,root=0,l,r,i,j;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    T[i].p = T[i].r = T[i].l = NIL;
  }

  for(i=0;i<n;i++){
      scanf("%d %d %d",&id,&l,&r);
      T[id].l = l;
      T[id].r = r;
      if(l != NIL) T[l].p = id;
      if(r != NIL) T[r].p = id;
  }
  
  for(i=0;i<n;i++){//根
    if(T[i].p == NIL){
      root = i;
    }
  }

  calcDepth(root,0);//深さ

  
  for(i=0;i<n;i++){//出力
    calcDegree(i);
    calcHeight(i);
    print(i);
  }

  return 0;
}
