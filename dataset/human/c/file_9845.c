#include<stdio.h>
#define NIL -1

typedef struct node{
  int p;
  int l;
  int r;
}Node;
Node T[100000];
int D[100000];
int n;

void print(int u){
  int i,c;
  printf("node %d: ",u);
  printf("parent = %d, ",T[u].p);
  printf("depth = %d, ",D[u]);
  if(T[u].p == NIL){
    printf("root, ");
  }else if(T[u].l == NIL){
    printf("leaf, ");
  }else{
    printf("internal node, ");
  }
  printf("[");
  c = T[u].l;
  while(c != NIL){
    printf("%d",c);
    if(T[c].r!=NIL){
      printf(", ");
    }
    c = T[c].r;
  }
  printf("]\n");
}

void rec(int u,int p){
D[u] = p;
  if(T[u].r != NIL)rec(T[u].r,p);
  if(T[u].l != NIL)rec(T[u].l,p+1);
}


int main(){
  int i,j,k,v,c,l,r;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    T[i].p = NIL;
    T[i].l = NIL;
    T[i].r = NIL;
  }

  for(i=0;i<n;i++){
    scanf("%d%d",&v,&k);
    for(j=0;j<k;j++){
      scanf("%d",&c);

      if(j == 0){
        T[v].l = c;
      }else{
        T[l].r = c;
      }
      l = c;
      T[c].p = v;
    }
  }
  for(i=0;i<n;i++){
    if(T[i].p == NIL){
      r = i;
    }
  }
    rec(r,0);

    for(i=0;i<n;i++){
      print(i);
    }

    return 0;

}
