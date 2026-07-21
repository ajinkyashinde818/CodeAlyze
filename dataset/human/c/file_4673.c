#include<stdio.h>

#define N 100000
#define NIL -1

struct Node{
  int p;
  int l;
  int r;
};
 
struct Node T[N];
int De[N];
 
int Depth(int x){
  int sum = 0;
  while(T[x].p != NIL){
    sum++;
    x = T[x].p;
  }
  return sum;
}
 
 
int sibling(int x){
  if(T[x].p == NIL) return NIL;
  if(T[T[x].p].r == x) return T[T[x].p].l;
  if(T[T[x].p].l == x) return T[T[x].p].r;
}
 
int degree(int x){
  int sum = 0;
  if(T[x].l != NIL) sum++;
  if(T[x].r != NIL) sum++;
  return sum;
}
 
int height(int x){
  int height1 = 0;
  int height2 = 0;
 
  if(T[x].l != NIL) height1 = height(T[x].l) + 1;
  if(T[x].r != NIL) height2 = height(T[x].r) + 1;
 
  if(height1 < height2) return height2;
  else return height1;
}
 
 
main(){
  int v,d,c,s;
  int n;
  int i,j,m;
 
 
 
  scanf("%d",&n);
 
  for(i=0; i < n; i++){
    T[i].p = T[i].l = T[i].r = NIL;
  }
   

  for(j = 0; j < n; j++){
    scanf("%d",&v);
    scanf("%d %d",&T[v].l,&T[v].r);
 
    T[T[v].l].p = v;
    T[T[v].r].p = v;
  }
 

  for(i = 0; i < n; i++){
    De[i] = Depth(i);
  }
 

  for(m = 0; m<n; m++){
    printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, "
                                                        ,m,T[m].p, sibling(m), degree(m),De[m],height(m));
 
    if(T[m].p == NIL) printf("root\n");
    else if(T[m].l != NIL || T[m].r != NIL)printf("internal node\n");
    else printf("leaf\n");
  }
  return 0;
}
