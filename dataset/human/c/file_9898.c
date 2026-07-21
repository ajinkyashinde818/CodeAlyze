#include <stdio.h>
#include <stdlib.h>

#define NIL -1

typedef struct{
  int p;
  int l;
  int r;
} node;


void print(node *, int);
int depth(node *, int);


int main(){
  node u[100001];
  int n, k, id, c, l, r;
  int i, j;
  

  scanf("%d", &n);
  
  for(i = 0; i < n; i++){
    u[i].p = NIL;
    u[i].l = NIL;
    u[i].r = NIL;
  }


  for(i = 0; i < n; i++){
    scanf("%d%d", &id, &k);

    for(j = 0; j < k; j++){
      scanf("%d", &c);
      if(j == 0) u[id].l = c;

      else u[l].r = c;

      l = c;
      u[c].p = id; 
    }
  }

  for(i = 0; i < n; i++) print(u, i);
  
  return 0;
}


void print(node *u, int i){
  int c;

  printf("node %d: ", i);
  printf("parent = %d, ", u[i]);
  printf("depth = %d, ", depth(u, i));

  if(u[i].p == NIL) printf("root, ");
  if(u[i].p != NIL && u[i].l == NIL) printf("leaf, ");
  if(u[i].p != NIL && u[i].l != NIL) printf("internal node, ");

  
  printf("[");

  if(u[i].l != NIL){
    printf("%d", u[i].l);
    c = u[i].l;

    while(u[c].r != NIL){
      printf(", %d", u[c].r);
      c = u[c].r;
    }
  }

  printf("]\n");
}


int depth(node *u, int x){
  int count = 0, temp;

  while(u[x].p != NIL){
    count++;
    temp = u[x].p;
    x = temp;
  }

  return count;
}
