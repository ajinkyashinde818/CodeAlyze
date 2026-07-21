#include <stdio.h>
#define MAX 100000

int Depth(int);
int Sibling(int);
int Height(int);
void print(int);

typedef struct{
  int p;
  int l;
  int r;
}node;
 
node tree[MAX];
int height[MAX];
 
int main(){
 
  int n, i, id,  left, right, root;
 
  scanf("%d", &n);
 
  for( i=0; i<n; i++)
    tree[i].p = -1;
 
  for( i=0; i<n; i++){
    scanf("%d %d %d", &id, &left, &right);
    tree[id].l = left;
    tree[id].r = right;
 
    if( left != -1 ) tree[left].p = id;
    if( right != -1 ) tree[right].p= id;
  }
 
  for( i=0; i<n; i++)
    if( tree[i].p == -1 ) root = i;
 
  Height(root);
 
  for( i=0; i<n; i++)
    print(i);

  return 0;
}
 
int Depth(int u){
  int d = 0;

  while( tree[u].p != -1 ){
    u = tree[u].p;
    ++d;
  }
 
  return d;
}
 
int Sibling(int u){
  int temp = tree[u].p;
 
  if( temp == -1 ) return -1;
  if( tree[temp].l != u && tree[temp].l != -1 ) return tree[temp].l;
  if( tree[temp].r != u && tree[temp].r != -1 ) return tree[temp].r;
 
  return -1;
}
 
int Height(int u){
  int h1 = 0, h2 = 0;
 
  if( tree[u].l != -1 )    h1 = Height(tree[u].l) + 1;
  if( tree[u].r != -1 )    h2 = Height(tree[u].r) + 1;
 
  return height[u] = ( h1 > h2 ? h1 : h2 );
}

void print(int u){
  int deg = 0;
  printf("node %d: parent = %d, ", u, tree[u].p);
  printf("sibling = %d, ", Sibling(u));
 
  deg = 0;
  if( tree[u].l != -1 ) deg++;
  if( tree[u].r != -1 ) deg++;
 
  printf("degree = %d, ", deg);
  printf("depth = %d, ", Depth(u));
  printf("height = %d, ", height[u]);
 
  if( tree[u].p == -1 ) printf("root");
  else if( tree[u].l == -1 && tree[u].r == -1 ) printf("leaf");
  else printf("internal node");
 
  printf("\n");
}
