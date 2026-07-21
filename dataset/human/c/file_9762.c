#include<stdio.h>
#define MAX 100000
#define NIL -1

struct Node{ int p, l, r;};

struct Node T[MAX];

int n;
int H, D[MAX];

int getDepth(int);
void print(int);



int main(){
  
  int i, j;
  int d, v;
  int c, l;

  
  scanf("%d", &n);

  
  for ( i = 0; i < n; i++ ) {
    
    T[i].p = NIL;
    T[i].l = NIL;
    T[i].r = NIL;
    
  }

  for ( i = 0; i < n; i++ ){
    
    scanf("%d %d", &v, &d);

    for ( j = 0; j < d; j++ ){
      
      scanf("%d", &c);
      
      if ( j == 0 ) {
	T[v].l = c;
      }
      else{
	T[l].r = c;
      }
      
      l = c;
      T[c].p = v;
      
    }
  }
  
  H = 0;
  
  for ( i = 0; i < n; i++ ){
    
    D[i] = getDepth(i);
    
    if ( D[i] > H ) {
      H = D[i];
    }
    
  }

  for ( i = 0; i < n; i++ ) {
    print(i);
  }
  
  return 0;
}





int getDepth(int u){
  
  int d = 0;
  
  while(1){
    
    u = T[u].p;
    if ( u == NIL ) break;
    d++;
    
  }
  return d;
  
}

void print(int u){
  
  int i, c;
  
  printf("node %d: ", u);
  printf("parent = %d, ", T[u].p);
  printf("depth = %d, ", D[u]);

  if ( T[u].p == NIL ) {
    printf("root, ");
  }
  else if ( T[u].l == NIL ) {
    printf("leaf, ");
  }
  else{
    printf("internal node, ");
  }
  
  printf("[");
  
  for(i = 0, c = T[u].l; c != NIL; i++, c = T[c].r){

    if (i) printf(", ");

    printf("%d", c);

  }
  
  printf("]\n");
}
