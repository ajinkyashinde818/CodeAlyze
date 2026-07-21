#include<stdio.h>
#define MAX 100005
#define NIL -1
struct Node_struct{int p, l, r;}; /*p: 親(parent), l: 一番左の子(left child), r:右の兄弟(right sibling)*/
typedef struct Node_struct Node;
Node T[MAX];
int D[MAX];
int H[MAX];


void calcDepth(int u, int p){
  D[u] = p;
  if(T[u].l!=NIL) calcDepth(T[u].l,p+1);
  if(T[u].r!=NIL) calcDepth(T[u].r,p+1);
}


int calcHeight(int u){
  int a=0,b=0;
  if(T[u].l!=NIL){
    a=calcHeight(T[u].l)+1;
  }
  if(T[u].r!=NIL){
    b=calcHeight(T[u].r)+1;
  }

  if(a>b){
    H[u]=a;
    return H[u];
  }else{
    H[u]=b;
    return H[u];
  }
}


int getSib(int u){
  int n;
  n=T[u].p;
  if(n==NIL){
    return NIL;
  }else if(T[n].l!=NIL&&T[n].l!=u){
    return T[n].l;
  }else if(T[n].r!=NIL&&T[n].r!=u){
    return T[n].r;
  }else{
    return NIL;
  }
}

void print(int u){
  int degree=0;
  if(T[u].l!=NIL)degree++;
  if(T[u].r!=NIL)degree++;
  printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ", u, T[u].p,getSib(u),degree, D[u],H[u]);

  if(T[u].p==NIL) printf("root\n");
  else if(T[u].l==NIL&&T[u].r==NIL) printf("leaf\n");
  else printf("internal node\n");
}
 

int main(){
  int i;
  int n;
  int id, l, r;
  int root = NIL;
  scanf("%d", &n);
  for(i=0; i<n; i++) T[i].p = T[i].l = T[i].r = NIL;
  
  for(i=0; i<n; i++){
    scanf("%d %d %d", &id, &l,&r);
    T[id].l=l;
    T[id].r=r;
    if(l!=NIL){
      T[l].p=id;
    }
    if(r!=NIL){
      T[r].p=id;
    }
  }

  //根を求める (find the root)
  for(i=0; i<n; i++){
    if(T[i].p == -1) root = i;
  }
  
  //それぞれのノードの深さ,高さを求める
  calcDepth(root, 0);
  calcHeight(root);
  //出力 (output)
  for(i=0; i<n; i++) print(i);
  
  return 0;
}
