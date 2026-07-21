#include<stdio.h>
#define MAX 100000
#define NIL -1

struct Node{ int p, l, r, R, L;};
struct Node T[MAX];

void print(int u){
  
  int i = T[u].p, depth = 0, height, j = T[u].R, sibling = NIL, degree = 0;

  while(i != NIL){
    i = T[i].p;
    depth++;
  }

  height = Height(u, 0);  


  if(T[u].L == NIL && T[u].r != NIL){
    sibling = T[u].r;
  }else if(T[u].L != NIL && T[u].r == NIL){
    sibling = T[u].L;
  }

  if(T[u].l == NIL && T[u].R == NIL){
    degree = 0;
  }else if(T[u].l == NIL || T[u].R == NIL){
    degree = 1;
  }else if(T[u].l != NIL && T[u].R != NIL){
    degree = 2;
  }

  if(depth == 0){
    printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, root\n", u, T[u].p,  sibling, degree, depth, height);
  } else if(T[u].l == NIL && T[u].R == NIL){
    printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, leaf\n", u, T[u].p, sibling, degree, depth, height);
  }else{
    printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, internal node\n", u, T[u].p, sibling, degree, depth, height);  
  }
}



int Height(int a, int count){
  
  int x , y;
  x=y=count;
  if(T[a].l != NIL) x = Height(T[a].l, count+1);
  if(T[a].R != NIL) y = Height(T[a].R, count+1);
  
  if(x < y )x = y; 
  return x;
  
} 

main(){
  int i, j, temp1, temp2, temp3, n;

  scanf("%d", &n);

  for ( i = 0; i < n; i++ ) {
    T[i].p = T[i].l = T[i].r = T[i].L = T[i].R = NIL;
  }
  
  for ( i = 0; i < n; i++ ){
    scanf("%d %d %d", &temp1, &temp2, &temp3);
    T[temp1].l = temp2;
    T[temp3].L = temp2;
    T[temp1].R = temp3;
    T[temp2].r = temp3;
    T[temp2].p = temp1;
    T[temp3].p = temp1;
  }

  for ( i = 0; i < n; i++ ) print(i);
  return 0;
}
