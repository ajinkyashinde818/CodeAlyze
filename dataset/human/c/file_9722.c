#include<stdio.h>
#include<stdlib.h>

#define MAX 100005
#define NIL -1

struct node{
  int p;
  int r;
  int l;
};

struct node T[MAX];
int n,D[MAX];

void print(int u){
  int c,i;
  printf("node %d: ",u);
  printf("parent = %d, ",T[u].p);
  printf("depth = %d, ",D[u]);
 
  if(T[u].p==NIL)printf("root, [");
  else if(T[u].l==NIL)printf("leaf, [");
  else printf("internal node, [");

  for(i=0,c=T[u].l;c!=NIL;i++,c=T[c].r){
    if(i!=0){
      printf(", ");
    }
    printf("%d",c);
  }
  printf("]\n");
}


int rec(int u, int p){
  D[u]=p;
  if(T[u].r!=NIL) rec(T[u].r,p);
  if(T[u].l!=NIL) rec(T[u].l,p+1);
}


int main(){
  int i,j,d,v,c,l,r;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    T[i].p=NIL;
    T[i].r=NIL;
    T[i].l=NIL;
  }
  
 for(i=0;i<n;i++){
   scanf("%d %d",&v,&d);
   for(j=0;j<d;j++){
     scanf("%d",&c);
     if(j==0){
       T[v].l=c;
     }
     else{
       T[l].r=c;
     }
     l=c;
     T[c].p=v;
   }
 }

 
 for(i=0;i<n;i++){
   if(T[i].p==NIL) r=i;
 }

 rec(r,0);
  for(i=0;i<n;i++){
    print(i);
  }

  return 0;
}
