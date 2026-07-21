#include<stdio.h>
#define MAX 100005
#define NIL -1
   
typedef struct{ int p, l, r;}Node;
Node T[MAX];
int n, H[MAX], D[MAX],S[MAX];
int getD(int);
int getH(int);
int getS(int);
void print(int);
 
 
   
int main(){
  int i, j, d, v, c,l,r;
     
  scanf("%d",&n);
     
  for ( i = 0; i < n; i++ ) {
    T[i].p = T[i].l = T[i].r = NIL;
  }
     
  for ( i = 0; i < n; i++ ){
    scanf("%d", &l);
    for(j = 0; j < 2; j++){
      scanf("%d", &v);
      if(v != -1){
	T[v].p = l;
	if(j == 0) T[l].l = v;
	else T[l].r = v;
      }
    }
  }
     
   
  for ( i = 0; i < n; i++ ){
    D[i] = getD(i);
    H[i] = getH(i);
    S[i] = getS(i);
  }
   
  for ( i = 0; i < n; i++ ) print(i);
  return 0;
}
 
 
int getD(int u){
  if(T[u].p == NIL) return 0;
  return getD(T[u].p) + 1;
  
}

int getH(int u){
  int a = 0, b = 0;
  if(T[u].l != -1) a = getH(T[u].l) + 1;
  if(T[u].r != -1) b = getH(T[u].r) + 1;
  return a>b ? a : b;
}

int getS(int u){
  if(T[u].p == NIL)return NIL;
  else if(T[T[u].p].l != u && T[T[u].p].l != NIL)return T[T[u].p].l;
  else if(T[T[u].p].r != u && T[T[u].p].r != NIL)return T[T[u].p].r;
  else return NIL;
}

void print(int u){
  int deg=0;
  printf("node %d: parent = %d, sibling = %d, ",u,T[u].p,S[u]);
  if(T[u].l != NIL)deg++;
  if(T[u].r != NIL)deg++;
  printf("degree = %d, depth = %d, height = %d, ",deg,D[u],H[u]);
  if(T[u].p == NIL)printf("root\n");
  else if(T[u].l == NIL && T[u].r == NIL)printf("leaf\n");
  else printf("internal node\n");
}
