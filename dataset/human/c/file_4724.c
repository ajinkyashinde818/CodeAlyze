#include<stdio.h>
#include<stdlib.h>
#define MAX 10000
#define NIL -1

int parent[MAX], left[MAX], right[MAX];
int n, D[MAX], H[MAX];

int getDepth(int u){
  int d = 0;
  while(parent[u] != NIL){
    u = parent[u];
    d++;
  }
  return d;
}
void setDepth(int u, int p){
  D[u] = p;
  if(right[u] != NIL){
    setDepth(right[u], p+1 );
  }
  if(left[u] != NIL){
    setDepth(left[u], p+1 );
  }
}

int seTHeight(int u){
  int h1 = 0;
  int h2 = 0;
  if( right[u] != NIL ){
    h1 = seTHeight(right[u]) + 1;
  }
  if( left[u] != NIL ){
    h2 = seTHeight(left[u]) + 1;
  }
  return H[u] =(h1 > h2 ? h1 : h2);
}

int seTSibling(int u){
  if(parent[u] == NIL ) return NIL;
  if(left[parent[u]] != u && left[parent[u]] != NIL ) return left[parent[u]];
  if(right[parent[u]] != u && right[parent[u]] != NIL) return right[parent[u]];
  return NIL;
}

void printChildren(int u){

  int i, c;
  int deg = 0;

  printf("node %d: ", u);
  printf("parent = %d, ", parent[u]);
  printf("sibling = %d, ", seTSibling(u));
  if(left[u] != NIL ) deg++;
  if(right[u] != NIL ) deg++;
  printf("degree = %d, ", deg);
  printf("depth = %d, ", D[u]);
  printf("height = %d, ", H[u]);

  if(parent[u] == NIL) printf("root\n");
  else if(left[u] == NIL && right[u] == NIL ) printf("leaf\n");
  else printf("internal node\n");
}

int main(){
  int i, d, v, l, r;
  scanf("%d", &n);
  for(i = 0 ; i < n ; i++)  parent[i] = left[i] = right[i] = NIL;

  for( i = 0 ; i < n ; i++){
    scanf("%d", &v);
    scanf("%d", &l);
    scanf("%d", &d);
    left[v] = l;
    right[v] = d;
    if(l != NIL ) parent[l] = v;
    if(d != NIL ) parent[d] = v;
  }
  for( i = 0 ; i < n ; i++){
    if( parent[i] == NIL ) r = i;
  }

  setDepth(r, 0);
  seTHeight(r);

  for( i = 0 ; i < n ; i++) printChildren(i);

  return 0;
}
