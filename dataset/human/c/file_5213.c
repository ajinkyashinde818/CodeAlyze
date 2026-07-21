#include<stdio.h>
#define MAX 100005
#define NIL -1
struct Node_struct{int p,lc,rc,br,deg,h;}; 
typedef struct Node_struct Node;
Node T[MAX];
int D[MAX];

void print(int u){
  int i, c;
  printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ",u,T[u].p,T[u].br,T[u].deg,D[u],T[u].h);

  if(T[u].p==NIL) printf("root\n");
  else if(T[u].lc==NIL && T[u].rc==NIL) printf("leaf\n");
  else printf("internal node\n");
  
}

int calcDepth(int u, int p){
  int lh=NIL,rh=NIL;
  D[u] = p;
  
  if(T[u].rc!=NIL) rh=calcDepth(T[u].rc,p+1);  
  if(T[u].lc!=NIL) lh=calcDepth(T[u].lc,p+1);

  if(T[u].deg==0) T[u].h=0;
  else if(lh<=rh) T[u].h=rh+1;
  else T[u].h=lh+1;

  return T[u].h;
}

int main(){
  int i, j, k;
  int n;
  int id, sib, lc,rc;
  int root = NIL;
  scanf("%d", &n);
  for(i=0; i<n; i++) T[i].p = T[i].lc = T[i].rc = T[i].br = T[i].h = NIL;
  
  for(i=0; i<n; i++){
    scanf("%d", &id);
    scanf(" %d %d",&T[id].lc, &T[id].rc);

    T[id].deg=0;
    
    if(T[id].lc!=-1){
      T[T[id].lc].p=id;
      T[id].deg++;
    }
    if(T[id].rc!=-1){
      T[T[id].rc].p=id;
      T[id].deg++;
    }
    T[T[id].lc].br=T[id].rc;
    T[T[id].rc].br=T[id].lc;
  }

  //根を求める (find the root)
  for(i=0; i<n; i++){
    if(T[i].p == -1) root = i;
  }
  
  //それぞれのノードの深さを求める (find depth of each node)
  calcDepth(root, 0);

  //出力 (output)
  for(i=0; i<n; i++) print(i);
  
  return 0;
}
