#include<stdio.h>
#define NIL -1
#define MAX 100000

struct Node{
  int p;
  int l;
  int r;
};

struct Node T[MAX];
int depth[MAX];

void print(int u){
  int i,c;
  printf("node %d: ", u);
  printf("parent = %d, ", T[u].p);
  printf("depth = %d, ", depth[u]);
  
  if(T[u].p == NIL)printf("root, ");
  else if(T[u].l==NIL)printf("leaf, ");
 else printf("internal node, ");

  printf("[");
  for(i=0,c=T[u].l; c !=NIL; i++,c=T[c].r){
    if(i)printf(", ");
  printf("%d", c);
 }
printf("]\n");
}

void rec(int u, int p){
  depth[u]=p;
  if(T[u].r != NIL)rec(T[u].r, p);
  if(T[u].l != NIL)rec(T[u].l, p+1);
}

int main(){
  int i,j,e,v;
  int n,c,l,r;
  scanf("%d", &n);
  
  for(i=0;i<n;i++){
    T[i].r=NIL;
    T[i].l=T[i].r;
    T[i].p=T[i].l;}
  for(i=0;i<n;i++){scanf("%d %d", &v, &e);
   for(j=0;j<e;j++){
     scanf("%d", &c);
     if(j==0)T[v].l=c;
     else T[l].r=c;
     l=c;
     T[c].p=v;
   }
  }
 for(i=0;i<n;i++){
    if(T[i].p==NIL)r=i;
}

  rec(r,0);
  for(i=0;i<n;i++){print(i);}
  return 0;
}
