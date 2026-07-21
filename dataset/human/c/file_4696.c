#include<stdio.h>
#define MAX 100005
#define NIL -1
int parent[MAX],left[MAX],right[MAX],n, D[MAX],H[MAX];

int getDepth(int u);
int setHeight(int u);
int setSibling(int u);
void setDepth(int u,int p);
void printChildren(int u);

int main(){
  int i,j,d,v,c,l,r,w,t;
   scanf("%d",&n);
  for(i=0;i<n; i++){
    parent[i] = -1;
    left[i] = -1;
    right[i] = -1;   
  }
  
  for(i = 0; i < n; i++){
    scanf("%d",&v);
    scanf("%d",&l);
    scanf("%d",&d);
    left[v] = l;
    right[v] =d;
    if(l != NIL)parent[l] =v;
    if(d != NIL) parent[d] =v;
  }
  for(i = 0; i<n ; i++){
    if(parent[i] == NIL ) r = i;
  }
  setDepth(r,0);
  setHeight(r);
  for(i = 0; i< n; i++) printChildren(i);

  return 0;
}

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
  if(right[u] !=NIL){
    setDepth(right[u],p+1);
  }
  if(left[u] != NIL){
    setDepth(left[u],p+1);
  }
}
int setHeight(int u){
  int h1 = 0;
  int h2 = 0;
  if(right[u] != NIL){
    h1 = setHeight(right[u]) +1;
  }
  if(left[u] != NIL){
    h2 = setHeight(left[u]) + 1;
  }
  return H[u] = (h1 > h2 ? h1 : h2);
}

int setSibling(int u){
  if(parent[u] == NIL) return NIL;

  if(left[parent[u]] != u && left[parent[u]] != NIL) return left[parent[u]];
  
  if(right[parent[u]] != u && right[parent[u]] != NIL) return right[parent[u]];
  return NIL;
}
  


void printChildren(int u){
  int i,c;
  int deg = 0;

  printf("node %d: ", u);
  printf("parent = %d, ", parent[u]);
  printf("sibling = %d, ",setSibling(u));
  if(left[u] != NIL) deg++;
  if(right[u] != NIL) deg++;
  printf("degree = %d, ",deg);
  printf("depth = %d, ", D[u]);
  printf("height = %d, ", H[u]);
  
  if(parent[u] == NIL){
    printf("root\n");
  }
  else if (left[u] == NIL && right[u] == NIL){
    printf("leaf\n");
  }
  else{
    printf("internal node\n");
  }
}
