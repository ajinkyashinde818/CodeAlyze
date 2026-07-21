#include <stdio.h>
#define MAX 10000
#define NIL -1


typedef struct {
  int parent;
  int left;
  int right;
}Node;


Node t[MAX];
int n, D[MAX], H[MAX];


void sDep(int u,int d) {
  if(u == NIL){
    return;
  }
  D[u] = d;
  sDep(t[u].left, d+1);
  sDep(t[u].right,d+1);
}


int sHei(int u) {
  int h1 = 0, h2 = 0;
  if(t[u].left != NIL)
    h1 = sHei(t[u].left) + 1;
  if(t[u].right != NIL)
    h2 = sHei(t[u].right) + 1;
  return H[u] = (h1 > h2 ? h1 : h2);
}


int gSib(int u) {
  if( t[u].parent == NIL ){
    return NIL;
  }
  if(t[t[u].parent].left != u && t[t[u].parent].left != NIL ){
    return t[t[u].parent].left;
  }
  if(t[t[u].parent].right != u && t[t[u].parent].right != NIL ){
    return t[t[u].parent].right;
  }
  return NIL;
}


void print(int u) {
  printf("node %d: ",u);
  printf("parent = %d, ",t[u].parent);
  printf("sibling = %d, ",gSib(u));
  int deg = 0;
  if(t[u].left  != NIL) deg++;
  if(t[u].right != NIL) deg++;
  printf("degree = %d, ",deg);
  printf("depth = %d, ",D[u]);
  printf("height = %d, ",H[u]);
  
  if(t[u].parent == NIL) {
    printf("root\n");
  } else if(t[u].left == NIL && t[u].right == NIL) {
    printf("leaf\n");
  } else {
    printf("internal node\n");
  }
}





int main(void) {
  int v, l, r, root = 0;
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    t[i].parent = NIL;
  }
  for(int i=0;i<n;i++){
    scanf("%d %d %d",&v,&l,&r);
    t[v].left  = l;
    t[v].right = r;
    if(l != NIL) t[l].parent = v;
    if(r != NIL) t[r].parent = v;
  }



  
  for(int i=0; i<n; i++)
  if(t[i].parent == NIL) root = i;

  
  sDep(root,0);
  sHei(root);

  
  for(int i=0;i<n;i++){
    print(i);
  }
  
  return 0;
}
