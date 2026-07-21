#include<stdio.h>
#define MAX 10000
#define NIL -1

struct Node{
  int par,l,r;
};

struct Node T[MAX];
int n,dep[MAX],h[MAX];

int Depth(int u){
  int d=0;
  while(1){
    u = T[u].par;
    if(u == NIL)break;
    d++;
  }
  return d;
}

int Sibling(int u){
  if(T[u].par == NIL)return NIL;
  if(T[T[u].par].l != u && T[T[u].par].l != NIL)return T[T[u].par].l;
  if(T[T[u].par].r != u && T[T[u].par].r != NIL)return T[T[u].par].r;
    return NIL; 
}


int main(){
  int i,id/*node*/,l,r,p,c,deg;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    T[i].par = NIL;
  }
  for(i=0;i<n;i++){
    scanf("%d %d %d",&id,&l,&r);
    T[id].l = l;
    T[id].r = r;
        if(l != NIL)T[l].par = id;
    if(r != NIL)T[r].par = id;
  }
  for(i=0;i<n;i++){
    dep[i] = Depth(i);/*depth*/
    h[i] = 0;/*height*/
  }
  for(i=0;i<n;i++){/*height*/
    if(T[i].l == NIL && T[i].r == NIL){
      h[i] = 0;
      p = T[i].par;
      c = 1;
      while(1){
        if(p == NIL)break;
        if(h[p] < c)h[p] = c;
        c++;
        p = T[p].par;
      }
    }
  }
  for(i=0;i<n;i++){/*print*/
    printf("node %d: ",i);
    printf("parent = %d, ",T[i].par);
    printf("sibling = %d, ",Sibling(i));
    deg = 0;
    if(T[i].l != NIL)deg++;
    if(T[i].r != NIL)deg++;
    printf("degree = %d, ",deg);
    printf("depth = %d, ",dep[i]);
    printf("height = %d, ",h[i]);

    if(T[i].par == NIL){
      printf("root\n");
    }
    else if(T[i].l == NIL && T[i].r == NIL){
      printf("leaf\n");
    }
    else {
     printf("internal node\n");
    }
  }

  return 0;
}
