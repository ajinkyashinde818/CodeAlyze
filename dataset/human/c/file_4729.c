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
int sibling(node *, int);
int degree(node *, int);
int height(node *, int, int); 


int n;


int main(){
  node u[100001];
  int k, id, c, l, r;
  int i, j;
  

  scanf("%d", &n);
  
  for(i = 0; i < n; i++){
    u[i].p = NIL;
    u[i].l = NIL;
    u[i].r = NIL;
  }


  for(i = 0; i < n; i++){
    scanf("%d", &id);

    for(j = 0; j < 2; j++){
      scanf("%d", &c);
      if(j == 0) u[id].l = c;

      else u[id].r = c;

      l = c;
      if(l >= 0) u[c].p = id; 
    }
  }

  for(i = 0; i < n; i++) print(u, i);
  
  return 0;
}


void print(node *u, int i){
  int c;

  printf("node %d: ", i);
  printf("parent = %d, ", u[i].p);
  printf("sibling = %d, ", sibling(u, i));
  printf("degree = %d, ", degree(u, i));
  printf("depth = %d, ", depth(u, i));
  printf("height = %d, ", height(u, i, 0));

  if(u[i].p == NIL) printf("root");
  else if(u[i].p != NIL && u[i].r == NIL && u[i].l == NIL) printf("leaf");
  else printf("internal node");

  printf("\n");
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


int sibling(node *u, int x){
  if(u[x].p == NIL) return NIL;
  if(u[u[x].p].r == x) return u[u[x].p].l;
  if(u[u[x].p].l == x) return u[u[x].p].r;

  return NIL;
}


int degree(node *u, int x){
  int deg = 0;

  if(u[x].l != NIL && u[x].r != NIL)      deg = 2;
  else if(u[x].l != NIL || u[x].r != NIL) deg = 1;
  
  return deg;
}


int height(node *u, int x, int count){
  int a, b;
  
  if(degree(u, x) == 2){
    count++;
    a = height(u, u[x].l, count);
    b = height(u, u[x].r, count);

    if(a >= b) return a;
    else return b;
  }

  else if(degree(u, x) == 1){
    count++;

    if(u[x].l != NIL) return height(u, u[x].l, count);
    if(u[x].r != NIL) return height(u, u[x].r, count);

    return count;
  }

  else return count;
}
