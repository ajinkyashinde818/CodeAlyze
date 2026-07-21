#include<stdio.h>
#include<stdlib.h>
#define N 10000
#define NIL -1
#define max(a,b) ((a) > (b) ? (a) : (b))

struct Node {int p,l,r;};
struct Node T[N];

int H[N];

int getDepth(u){
  int d = 0;
  while(T[u].p != NIL){
    u = T[u].p;
    d++;
  }
  return d;
}

int setHight(int H[],int u){
  int h1 = 0, h2 = 0;
  if(T[u].r != NIL){
    h1 = setHight(H,T[u].r) + 1;
  }
  if(T[u].l != NIL){
    h2 = setHight(H,T[u].l) + 1;
  }

  return H[u] = max(h1,h2);
}

int getSibling(int u){
  if(T[u].p == NIL) return NIL;
  if(T[T[u].p].l != u && T[T[u].p].l != NIL){
    return T[T[u].p].l;
  }
  if(T[T[u].p].r != u && T[T[u].p].r != NIL){
    return T[T[u].p].r;
  }
  return NIL;
}


/*void printChildren(u){
  int c = T[u].l;
  while(c != NIL){
    if(T[c].r == NIL) printf("%d",c);
    else printf("%d, ",c);
    c = T[c].r;
  }
  }*/

int main(){
  int n,i,j,d,v,c,l,r;
  
  scanf("%d",&n);

  for(i = 0; i < n; i++){
    T[i].p = NIL;
    T[i].l = NIL;
    T[i].r = NIL;
  }

  /* for(i = 0; i < n; i++){
    scanf("%d%d",&v,&d);
    for(j = 0; j < d; j++){
      scanf("%d",&c);
      if(j == 0) T[v].l = c;
      else T[l].r = c;
      l = c;
      T[c].p = v;
    }
    }*/
  for(i = 0; i < n; i++){
    scanf("%d%d%d",&v,&l,&r);
    T[v].l = l;
    T[v].r = r;
    if(l != NIL) T[l].p = v;
    if(r != NIL) T[r].p = v;
  }
  
  for(i = 0; i < n; i++){
    if(T[i].p == NIL) r = i;
  }
  for(i = 0; i < n; i++){
    printf("node %d: ",i);
    printf("parent = %d, ",T[i].p);
    printf("sibling = %d, ",getSibling(i));
    int deg = 0;
    if(T[i].l != NIL) deg++;
    if(T[i].r != NIL) deg++;
    printf("degree = %d, ",deg);
    printf("depth = %d, ",getDepth(i));
    setHight(H,i);
    printf("height = %d, ",H[i]);

    if(T[i].p == NIL) printf("root\n");
    else if(T[i].l == NIL && T[i].r == NIL) printf("leaf\n");
    else printf("internal node\n");
    
  }

}
