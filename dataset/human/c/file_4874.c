#include<stdio.h>
#include<stdlib.h>
#define MAX 10000

int parent[MAX], left[MAX], right[MAX];
int n, D[MAX], H[MAX];

int getDepth(int u);

void setDepth(int u, int p);

int setHeight(int u);
  
int setSibling(int u);

  void printChildren(int u);

int main(){
  int i, a, b, l, r;
  scanf("%d", &n);
  for(i = 0 ; i < n ; i++)  parent[i] = left[i] = right[i] = -1;

  for( i = 0 ; i < n ; i++){
    scanf("%d", &b);
    scanf("%d", &l);
    scanf("%d", &a);
    left[b] = l;
    right[b] = a;
    if(l != -1 ) parent[l] = b;
    if(a != -1 ) parent[a] = b;
  }
   for(i = 0; i < n; i++){
    if( parent[i] == -1) r = i;
  }

  setDepth(r, 0);
  setHeight(r);

  for(i = 0 ;i < n; i++) printChildren(i);

  return 0;
}

int getDepth(int u){
  int d = 0;
  while(parent[u] != -1){
    u = parent[u];
    d++;
  }
  return d;
}

void setDepth(int u, int p){
  D[u] = p;
  if(right[u] != -1){
    setDepth(right[u], p+1);
  }
  if(left[u] != -1){
    setDepth(left[u], p+1);
  }
}

int setHeight(int u){
  int h1 = 0;
  int h2 = 0;
  if( right[u] != -1){
    h1 = setHeight(right[u]) + 1;
  }
  if( left[u] != -1){
    h2 = setHeight(left[u]) + 1;
  }
  return H[u] =(h1 > h2 ? h1 : h2);
}
int setSibling(int u){
  if(parent[u] == -1) return -1;
  if(left[parent[u]] != u && left[parent[u]] != -1) return left[parent[u]];
  if(right[parent[u]] != u && right[parent[u]] != -1) return right[parent[u]];
  return -1;
}

void printChildren(int u){

  int i, c;
  int deg = 0;
   printf("node %d: ", u);
  printf("parent = %d, ", parent[u]);
  printf("sibling = %d, ", setSibling(u));

  if(left[u] != -1) deg++;
  if(right[u] != -1) deg++;
  printf("degree = %d, ", deg);
  printf("depth = %d, ", D[u]);
  printf("height = %d, ", H[u]);

  if(parent[u] == -1) printf("root\n");
  else if(left[u] == -1 && right[u] == -1) printf("leaf\n");
  else printf("internal node\n");
}
