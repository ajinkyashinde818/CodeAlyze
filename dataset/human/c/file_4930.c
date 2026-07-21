#include<stdio.h>
#define MAX 100005
#define NIL -1

struct Node{ int p, l, r;};
struct Node T[MAX];
int n, H[MAX], D[MAX],S[MAX],DG[MAX];

int getHeight(int u,int left,int right){

  if(T[u].l == NIL && T[u].r == NIL) return 0;
  
  if(T[u].l != NIL){ 
    left = getHeight(T[u].l,left,0)+1;
  }
    if(T[u].r != NIL) right = getHeight(T[u].r,0,right)+1;

  if(left > right) {
    return left;
  }
  else{
    return right;
  }
}

int getDepth(int u){
  int d = 0;
  int i = 0;
  while(1){
    if(T[u].p == NIL) break;
    d++;
    u = T[u].p;
  }
  return d;
}

int getDegree(int u){
  if((T[u].l == NIL) && (T[u].r == NIL)) return 0;
  else if((T[u].l == NIL) || (T[u].r == NIL)) return 1;
  else return 2;
}

int getSibling(int u){
  
  /*  if(T[u].p == NIL) return NIL;
      
      else if(T[T[u].p].l == NIL){ 
      printf("u = %d T[u].l = %d\n",u,T[T[u].p].l); 
      return T[T[u].p].r;  
      }
      
      else { 
      printf("u = %d T[u].r = %d\n",u,T[u].r); 
      return T[T[u].p].l;  
      }*/
  
  /*  int i;
      for(i=0; i<n; i++){
      if((T[u].p == T[i].p) && (u != i))
      return i;
      }
      return NIL;
  */
  
  if(T[u].p == NIL) return NIL;
  
  else if(T[T[u].p].l != u){ 
    return T[T[u].p].l;  
  }
  
  else { 
    return T[T[u].p].r;  
  }
}

void print(int u){
  
  printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ",u,T[u].p, S[u],DG[u], D[u], H[u]);
  
  if( T[u].p == NIL) printf("root\n");
  else if(T[u].l == NIL && T[u].r == NIL) printf("leaf\n");
  else printf("internal node\n");
  
}


main(){
  int i, j, d, v, l;
  int pre;
  
  scanf("%d", &n);
  
  for ( i = 0; i < n; i++ ) {
    T[i].p = T[i].l = T[i].r = NIL;
  }
  
  for ( i = 0; i < n; i++ ){
    scanf("%d",&v);
    scanf("%d %d",&T[v].l,&T[v].r);
    T[T[v].l].p = v;
    T[T[v].r].p = v;
  }
  
  for(i=0; i < n; i++){
    S[i] = getSibling(i);
    DG[i] = getDegree(i);
    D[i] = getDepth(i);
    H[i] = getHeight(i,0,0);
  }  
    
  for ( i = 0; i < n; i++ ) print(i);
  return 0;
}
