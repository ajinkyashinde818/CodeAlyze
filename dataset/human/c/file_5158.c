#include<stdio.h>
#define MAX 100005
#define NIL -1

struct Node{ int p, l, r,t;};
struct Node T[MAX];
int n, H, D[MAX],h[MAX];

void getDepth(int u){
  // if(D[u]!=NIL) return ;
  int d=0;
  /*while(1){
    if(T[u].p==NIL){
      break;
    }
    else{
      d++;
      u = T[u].p;
  }
  return d;
  }*/
  if(T[u].r!=NIL){
    D[T[u].r]=D[u]+1;
    getDepth(T[u].r);
  }
  if(T[u].l!=NIL){ 
    D[T[u].l]=D[u]+1;
    getDepth(T[u].l);
  }
}

int getheight(int u){
  int a,s;
  a=s=0;
  if(T[u].r==NIL && T[u].l==NIL) return 0;
  if(T[u].l!=NIL){
    a=getheight(T[u].l)+1;
  }
  if(T[u].r!=NIL){
    s=getheight(T[u].r)+1;
  }
  if(a>s) return a;
  else return s;
}

void print(int u){
  printf("node %d: parent = %d,",u,T[u].p);
if(T[u].p==NIL)/*(T[T[u].p].l==NIL && T[T[u].p].r ==NIL) */printf(" sibling = -1, ");
  else if(T[T[u].p].r==u)  printf(" sibling = %d, ",T[T[u].p].l);
  else   if(T[T[u].p].l==u) printf(" sibling = %d, ",T[T[u].p].r);
  printf("degree = %d, ",T[u].t);
  printf("depth = %d, height = %d, ",D[u],h[u]);
  if(T[u].p==NIL) printf("root\n");
  else if(T[u].t==0) printf("leaf\n");
  else printf("internal node\n");
  /*
  printf("[");
  int a;
  a=u;
  if(T[a].l!=NIL){ 
    printf("%d",T[a].l);   
    if(T[T[a].l].r==NIL) printf("]\n");
    else printf(", ");
    a=T[a].l;
    while(T[a].r!=NIL){
      printf("%d",T[a].r);
      if(T[T[a].r].r==NIL) printf("]\n");
      else printf(", ");
      a=T[a].r;
    }
  }
  else puts("]");
  */
}

main(){
  int i,d, v, c, l,r;
  
  scanf("%d", &n);
  
  for ( i = 0; i < n; i++ ) {
    T[i].p = T[i].l = T[i].r = NIL;
  }
  
  for ( i = 0; i < n; i++ ){
    scanf("%d%d%d", &v,&l,&r);
    if(l!=NIL){
      T[l].p=v;
    }
    if(r!=NIL){
      T[r].p=v;
    }
    T[v].l = l;
    T[v].r = r;
  }
  for ( i = 0; i < n; i++ ){
    if(T[i].l != -1){
      T[i].t++;
    }
    if(T[i].r != -1){
      T[i].t++;
    }
  }
  
  //v = children numbers
  /*for ( j = 0; j < d; j++ ){
    scanf("%d", &c);
      T[c].p=v;
      if(j>=1){T[r].r=c;}
      if(j==0){T[v].l=c;}
      r=c;
  */
  
  
  for ( i = 0; i < n; i++ ){
    if(T[i].p==NIL){D[i]=0; getDepth(i); break;}
  }
  for ( i = 0; i < n; i++ ){
    h[i]=getheight(i); 
  }

  for ( i = 0; i < n; i++ ) print(i);
  return 0;
}
