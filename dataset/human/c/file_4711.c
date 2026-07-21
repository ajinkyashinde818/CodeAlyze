#include<stdio.h>
#define MAX 10000
#define NIL -1
 
typedef struct {int parent, left , right;} Node;
 
Node T[MAX];
int n,D[MAX], H[MAX];
 
void setDepth(int u , int d) {
  if ( u == NIL) return ;
  D[u]  = d;
  setDepth(T[u].left , d + 1);
  setDepth(T[u].right, d + 1);
 
}
 
int setHeight(int u)  {
  int h1 = 0, h2 = 0;
  if( T[u].left != NIL)
  h1 = setHeight(T[u].left) + 1;
  if(T[u].right != NIL)
  h2 = setHeight(T[u].right) + 1;
  return H[u] = (h1 > h2 ? h1 : h2);
}
 
int getSibling(int u) {
  if(T[u].parent == NIL) return NIL;
  if(T[T[u].parent].left != u && T[T[u].parent].left != NIL)
  return T[T[u].parent].left;
  if(T[T[u].parent].right != u && T[T[u].parent].right != NIL)
  return T[T[u].parent].right;
  return NIL;
}
 
void print(int u) {
  int i,c;
  printf("node %d: ", u);
  printf("parent = %d, ", T[u].parent);
  printf("sibling = %d, ", getSibling(u));
    int deg = 0;
  if(T[u].left != NIL) deg++;
  if(T[u].right != NIL) deg++;
  printf("degree = %d, ", deg );
  printf("depth = %d, ", D[u] );
  printf("height = %d, ", H[u] );
 
  if(T[u].parent == NIL) printf("root\n");
  else if (T[u].left == NIL && T[u].right == NIL) printf("leaf\n");
  else printf("internal node\n");
 
}
 
int main()  {
  int i,a,b,c,root = 0;
  scanf("%d\n",  &n);
 
  for(i = 0; i < n;i++) T[i].parent = NIL;
 
  for(i = 0 ; i < n ; i++) {
    scanf("%d %d %d \n", &a, &b , &c);
    T[a].left = b;
    T[a].right = c;
    if ( b!= NIL) T[b].parent = a;
    if ( c!= NIL) T[c].parent = a;
  }
 
  for(i = 0; i < n ;i++) if ( T[i].parent == NIL) root = i;
 
  setDepth(root , 0);
  setHeight(root);
 
  for ( i = 0; i  < n; i++) print(i);
 
  return 0;
}
