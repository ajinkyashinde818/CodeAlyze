#include<stdio.h>
#define MAX 100000
#define MIN -1

struct Node{ int parent, left, right;};
struct Node T[MAX];

int getDepth(int);
void print(int);
int  D[MAX];
int main(){
  int i,j,n,x,y,c,l,a;
  scanf("%d", &n);
  for ( i = 0; i < n; i++ ){
    T[i].parent = T[i].left = T[i].right = MIN;
  }
  
  for ( i = 0; i < n; i++ ){
    scanf("%d%d",&x,&y);
    for ( j = 0; j < y; j++ ){
      scanf("%d", &c);
      if ( j == 0 ) T[x].left = c;
      else T[l].right = c;
      l = c;
      T[c].parent =x;
    }
  }
  
  a=0;
  for ( i = 0; i < n; i++ ){
    D[i] = getDepth(i);
    if ( D[i] > a ){
      a = D[i];
    }
  }

  for ( i = 0; i < n; i++ ){
    print(i);
  }
  
  return 0;
}


int getDepth(int u){
  int d=0;
  while(T[u].parent!=MIN){
    u=T[u].parent;
    d++;
  }
  return d;
}


void print(int u){
  int i, c;
  printf("node %d: ", u);
  printf("parent = %d, ", T[u].parent);
  printf("depth = %d, ", D[u]);

  if ( T[u].parent == MIN) printf("root, [");
  else if ( T[u].left == MIN) printf("leaf, [");
  else printf("internal node, [");

  for(i = 0, c = T[u].left; c != MIN; i++, c = T[c].right){
    if (i) printf(", ");
    printf("%d", c);
  }
  printf("]\n");
}
