#include <stdio.h>
#define MAX 10000
#define NUL -1

typedef struct{
  int parent;
  int left;
  int right;
}Node;

Node T[MAX];
int n, D[MAX], H[MAX];

void Depth(int , int );
int Height(int );
int Sibling(int );
void print(int );

int main(){
  int t, l, r, root=0, i;

  scanf("%d", &n);

  for(i=0; i<n; i++) T[i].parent = NUL;
  
  for(i=0; i<n; i++){
    scanf("%d %d %d", &t, &l, &r);
    T[t].left = l;
    T[t].right = r;
    if( l != NUL ) T[l].parent = t;
    if( r != NUL ) T[r].parent = t;
  }
  
  for(i=0; i<n; i++) if( T[i].parent == NUL ) root = i;
  
  Depth(root, 0);
  Height(root);
  
  for(i=0; i<n; i++) print(i);
  
  return 0;
}

void Depth(int u, int d){
  if( u == NUL ) return;
  D[u] = d;
  Depth(T[u].left, d+1);
  Depth(T[u].right, d+1);
}

int Height(int u){
  int h_a=0, h_b=0;

  if( T[u].left != NUL ) h_a = Height( T[u].left )+1;
  if( T[u].right != NUL ) h_b = Height( T[u].right )+1;
  return H[u] = (h_a > h_b ? h_a : h_b);
}

int Sibling(int u){
  if( T[u].parent == NUL ) return NUL;
  if( T[ T[u].parent ].left != u && T[ T[u].parent ].left != NUL )
    return T[ T[u].parent ].left;
  if( T[ T[u].parent ].right != u && T[ T[u].parent ].right != NUL )
    return T[ T[u].parent ].right;
  return NUL;
}

void print(int u){
  int h = 0;
  printf("node %d: ", u);
  printf("parent = %d, ", T[u].parent);
  printf("sibling = %d, ", Sibling(u));
  if( T[u].left != NUL ) h++;
  if( T[u].right != NUL ) h++;
  printf("degree = %d, ", h);
  printf("depth = %d, ", D[u]);
  printf("height = %d, ", H[u]);

  if( T[u].parent == NUL ) printf("root\n");
  else if( T[u].left == NUL && T[u].right == NUL ) printf("leaf\n");
  else printf("internal node\n");
}
