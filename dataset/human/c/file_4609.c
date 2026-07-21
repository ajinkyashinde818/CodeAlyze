#include<stdio.h>
#define MAX 100005
#define NIL -1

struct Node_struct{int p,l,r;}; /*p: 親(parent), l: 一番左の子(left child), r:右のこども(right child)*/
typedef struct Node_struct Node;

Node T[MAX];
int D[MAX];
int H[MAX];
int deg[MAX];
int S[MAX];
int t;

void print(int u){
  
  printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ",u,T[u].p,S[u],deg[u],D[u],H[u]);
  
  if(T[u].p == NIL) printf("root");
  else if(T[u].l == NIL && T[u].r== NIL) printf("leaf");
  else printf("internal node");
  printf("\n");
}

void calcDepth(int u, int p){
  D[u] = p;
  
  if(T[u].l != NIL) calcDepth(T[u].l,p+1);
  if(T[u].r != NIL) calcDepth(T[u].r,p+1);
}

void calcHeight(int u, int p){
  if(T[u].p != NIL) calcHeight(T[u].p,p+1);
  if(p >= H[u]) H[u] = p;
}

int main(){
  int i,j;
  int n;
  int c;
  int id,L_child,R_child;
  int root = NIL;
  scanf("%d",&n);
  for(i=0; i<n; i++) T[i].p = T[i].l = T[i].r = S[i] = NIL;
  
  for(i=0; i<n; i++){
    scanf("%d",&id);  
    scanf("%d%d",&L_child,&R_child);
    
    T[id].l = L_child;
    T[id].r = R_child;
    
    if(i == 0){
      S[id] = NIL;
      T[id].p = NIL;
    }
    if(L_child != NIL){
      T[L_child].p = id;
      if(R_child != NIL){
	S[L_child] = R_child;
      }
    }
    
    if(R_child != NIL){
      T[R_child].p = id;
      if(L_child != NIL){
	S[R_child] = L_child;
      }
    }


  }
  
  //根
  for(i=0; i<n; i++){
    if(T[i].p == -1) root = i;
  }
  
  //深さ
  calcDepth(root, 0);
    
  //高さ
  for(i=0; i<n; i++){
    calcHeight(i,0);
  }
  
  //こどもの数
  for(i=0; i<n; i++){
    if(T[i].l != NIL && T[i].r != NIL) deg[i] = 2;
    if((T[i].l != NIL && T[i].r == NIL) || (T[i].l == NIL && T[i].r != NIL)) deg[i] = 1;
    if(T[i].l == NIL && T[i].r == NIL) deg[i] = 0;
  }
  
  //出力
  for(i=0; i<n; i++){
    print(i);
  }
  return 0;
}
