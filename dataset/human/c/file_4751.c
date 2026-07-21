#include<stdio.h>
#define MAX 100005
#define NIL -1

struct Node{ int p, l, r,key;};
struct Node T[MAX];

int n, S[MAX],DG[MAX],H[MAX], D[MAX];

int getDepth(int u){
  int d = 0,n = u;
  while(1){
    n = T[n].p;
    if(n == NIL)break;
    d++;
  }
  return d;
}


int getHeight(int u){
  int L=0,R=0;
  if (T[u].r == NIL && T[u].l == NIL) return 0;
    if (T[u].l != NIL){
      L =  getHeight(T[u].l)+1;
    }
    if(T[u].r != NIL){
      R =  getHeight(T[u].r)+1;
    }
    if(L > R) return L; 
    
    else return R; 
}


int getDegree(int u){
  int n = u;
  if(T[n].l != NIL && T[n].r != NIL)return 2;
  else if(T[n].l != NIL || T[n].r != NIL)return 1;
  else return 0;
}

int getSibling(int u, int n){
  int i;
  for(i = 0; i < n; i++ ){
    if(T[u].p == T[i].p && i != u)return i; 
  }
  return NIL;
}

void print(int u){
  int n = u;
  printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d,",u,T[u].p,S[u],DG[u],D[u],H[u]);
  n = T[n].l;

  if(T[u].p == NIL)printf(" root\n");
  else if(DG[u]>= 1 && DG[u] <= 2)printf(" internal node\n");
  else printf(" leaf\n");
 
}
int main(){
  int i,v,l,r;

  scanf("%d", &n);

  for ( i = 0; i < n; i++ ) {
    T[i].p = T[i].l = T[i].r = NIL;
  }

  for ( i = 0; i < n; i++ ){
    scanf("%d %d %d", &v,&l,&r);
    /*make tree*/
    T[v].l = l;
    T[v].r = r;
    if(l != NIL)T[l].p = v;
    if(r != NIL)T[r].p = v;
  }
 
  for(i = 0; i < n; i++){
    S[i] = getSibling(i,n);
  }

  for(i = 0; i < n; i++){
    DG[i] = getDegree(i);
    }
  for ( i = 0; i < n; i++ ){
     D[i] = getDepth(i);
  }
 
  for (i = 0; i < n; i++ ){
    H[i] = getHeight(i);
  } 

  for ( i = 0; i < n; i++ ) print(i);
  return 0;
  
}
