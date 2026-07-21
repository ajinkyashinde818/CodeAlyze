#include<stdio.h>
#define MAX 100000
#define NIL -1
 
struct node {
  int p, l, r, t;
};

struct node T[MAX];

void depth(int);
int height(int);
void print(int);

int n, H, D[MAX], h[MAX];
 
int main(){
  
  int i, d, v, c, l, r;
   
  scanf("%d", &n);
   
  for(i = 0; i < n; i++){
    T[i].p = NIL;
    T[i].l = NIL;
    T[i].r = NIL;
  }
   
  for(i = 0; i < n; i++) {
    scanf("%d %d %d", &v, &l, &r);
    if(l != NIL) {
      T[l].p = v;
    }
    if(r != NIL) {
      T[r].p = v;
    }
    T[v].l = l;
    T[v].r = r;
  }
  for ( i = 0; i < n; i++ ){
    if(T[i].l != NIL) {
      T[i].t++;
    }
    if(T[i].r != NIL){
      T[i].t++;
    }
  }
   
  for(i = 0; i < n; i++){
    if(T[i].p==NIL) {
      D[i] = 0; 
      depth(i); 
      break;
    }
  }
  for(i = 0; i < n; i++){
    h[i] = height(i); 
  }
 
  for ( i = 0; i < n; i++ ) {
    print(i);
  }

  return 0;
}

void depth(int u){
  
  int d = 0;

  if(T[u].r != NIL){
    D[T[u].r] = D[u]+1;
    depth(T[u].r);
  }
  if(T[u].l != NIL){ 
    D[T[u].l] = D[u]+1;
    depth(T[u].l);
  }
}
 
int height(int u){
  
  int a = 0, s = 0;

  if(T[u].r == NIL && T[u].l == NIL) 
    return 0;
  if(T[u].l != NIL) {
    a = height(T[u].l)+1;
  }
  if(T[u].r != NIL) {
    s = height(T[u].r)+1;
  }
  if(a > s) 
    return a;
  else 
    return s;
}
 
void print(int u){
  printf("node %d: parent = %d,", u, T[u].p);
  if(T[u].p == NIL)
    printf(" sibling = -1, ");
  else if(T[T[u].p].r == u)
    printf(" sibling = %d, ", T[T[u].p].l);
  else if(T[T[u].p].l == u)
    printf(" sibling = %d, ", T[T[u].p].r);
  printf("degree = %d, ", T[u].t);
  printf("depth = %d, height = %d, ", D[u], h[u]);

  if(T[u].p == NIL)
    printf("root\n");
  else if(T[u].t == 0)
    printf("leaf\n");
  else
    printf("internal node\n");
}
