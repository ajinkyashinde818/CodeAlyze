#include<stdio.h>
#include<stdlib.h>
#define MAX 10000
#define MIN -1

  
int Height(int);
int Sibling(int);
void Depth(int,int);
void Print(int);
  
typedef struct {
  int p,l,r;
}Node;
  
Node node[MAX];
  
int n, height[MAX], depth[MAX];
  
int main(){
  int i;
  int id, l, r, root = 0;
  
  scanf("%d",&n);
  
  for( i = 0 ; i < n ; i++ ) {
    node[i].p = MIN;
  }
  
  for( i = 0 ; i < n ; i++ ) {
    scanf("%d%d%d",&id,&l,&r);
    
    node[id].l = l;
    node[id].r = r;
    if(l != MIN) node[l].p = id;
    if(r != MIN) node[r].p = id;
  }
  
  for( i=0 ; i<n ; i++) {
    if( node[i].p == MIN ) {
      root = i;
    }
  }
  
  Depth(root,0);
  Height(root);
  
  i = 0;
  while( i < n ){
    Print(i);
    i++;
  }
  
  return 0;
}

int Height(int u) {
  int h1 = 0 , h2 = 0;
  
  if(node[u].l != MIN) {
    h1 = Height(node[u].l) + 1;
  }
  if(node[u].r != MIN) {
    h2 = Height(node[u].r) + 1;
  }
  
  if(h1 > h2) return height[u] = h1;
  else return height[u] = h2;
}
  
int Sibling(int u) {
  if(node[u].p == MIN) return MIN;
  if( node[node[u].p].r != u && node[node[u].p].r != MIN ) return node[node[u].p].r;
  if( node[node[u].p].l != u && node[node[u].p].l != MIN ) return node[node[u].p].l;
  
  return MIN;
}
  
void Depth( int u, int d ) {
  if(u == MIN) return;
  depth[u] = d;
  Depth(node[u].l, d+1);
  Depth(node[u].r, d+1);
}
  
void Print(int u) {
  int suu = 0;
  
  printf("node %d: parent = %d, sibling = %d, ",u,node[u].p,Sibling(u));
  if(node[u].l != MIN) suu++;
  if(node[u].r != MIN) suu++;
  
  printf("degree = %d, depth = %d, height = %d, ",suu,depth[u],height[u]);
  if(node[u].p == MIN) printf("root\n");
  else if( node[u].l == MIN && node[u].r == MIN ) printf("leaf\n");
  else printf("internal node\n");
}
