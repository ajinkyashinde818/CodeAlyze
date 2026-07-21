#include<stdio.h>

#define MAX 100005
#define NIL -1

struct Node{ int p, l, r, t;};
struct Node T[MAX];

int n, H, D[MAX],h[MAX];

void Depth(int u){
  
  int d=0;
  if(T[u].r!=NIL){
    D[T[u].r]=D[u]+1;
    Depth(T[u].r);
  }
  if(T[u].l!=NIL){ 
    D[T[u].l]=D[u]+1;
    Depth(T[u].l);
  }
}

int Height(int u){

  int a,s;
  a=s=0;
  if(T[u].r==NIL && T[u].l==NIL) return 0;
  if(T[u].l!=NIL){
    a=Height(T[u].l)+1;
  }
  if(T[u].r!=NIL){
    s=Height(T[u].r)+1;
  }
  if(a>s) return a;
  else return s;
}

int main(){
  int i,d, v, c, l,r;
  
  scanf("%d", &n);
  
  for (i=0;i<n;i++){
    T[i].p=T[i].l=T[i].r=NIL;
  }
  
  for(i=0;i<n;i++){
    scanf("%d%d%d",&v,&l,&r);
    if(l!=NIL){
      T[l].p=v;
    }
    if(r!=NIL){
      T[r].p=v;
    }
    T[v].l = l;
    T[v].r = r;
  }
  for (i=0;i<n;i++){
    if(T[i].l != -1){
      T[i].t++;
    }
    if(T[i].r != -1){
      T[i].t++;
    }
  }
  
  for (i=0;i<n;i++){
    if(T[i].p==NIL){
      D[i]=0;
      Depth(i);
      break;
    }
  }
  
  for (i=0;i<n;i++){
    h[i]=Height(i); 
  }
  
  for (i=0;i<n;i++){
    printf("node %d: parent = %d,",i,T[i].p);
    if(T[i].p==NIL)printf(" sibling = -1, ");
    else if(T[T[i].p].r==i)  printf(" sibling = %d, ",T[T[i].p].l);
    else   if(T[T[i].p].l==i) printf(" sibling = %d, ",T[T[i].p].r);
    printf("degree = %d, ",T[i].t);
    printf("depth = %d, height = %d, ",D[i],h[i]);
    if(T[i].p==NIL) printf("root\n");
    else if(T[i].t==0) printf("leaf\n");
    else printf("internal node\n");
  }
  return 0;
}
