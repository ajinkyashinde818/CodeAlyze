#include<stdio.h>
#define max 100000
#define NIL -1

typedef struct{
  int p;
  int l;
  int r;
}Node;

Node T[max];
int D[max],H[max];
int n;

int Depth(int u){
  int d=0;
  while(1){
    u=T[u].p;
    if(u==NIL) break;
    d++;
  }
  return d;
}

int Sibling(int u){
  if(T[u].p==NIL) return NIL;
  if(T[T[u].p].l!=u&&T[T[u].p].l!=NIL) return T[T[u].p].l;
  if(T[T[u].p].r!=u&&T[T[u].p].r!=NIL) return T[T[u].p].r;
  return NIL;
}

int main(){
  int i,id,l,r,p,c,deg;
  scanf("%d",&n);

  for(i=0;i<n;i++) T[i].p=NIL;

  for(i=0;i<n;i++){
    scanf("%d%d%d",&id,&l,&r);
    T[id].l=l;
    T[id].r=r;
    if(l!=NIL) T[l].p=id;
    if(r!=NIL) T[r].p=id;
  }

  for(i=0;i<n;i++){
    D[i]=Depth(i);
    H[i]=0;
  }

  for(i=0;i<n;i++){
    if(T[i].l==NIL&&T[i].r==NIL){
      H[i]=0;
      p=T[i].p;
      c=1;
      while(1){
	if(p==NIL) break;
	if(H[p]<c) H[p]=c;
	c++;
	p=T[p].p;
      }
    }
  }

  for(i=0;i<n;i++){
    printf("node %d: parent = %d, sibling = %d, ",i,T[i].p,Sibling(i));
    deg=0;
    if(T[i].l!=NIL) deg++;
    if(T[i].r!=NIL) deg++;
    printf("degree = %d, depth = %d, height = %d, ",deg,D[i],H[i]);

    if(T[i].p==NIL){
      printf("root\n");
    }
    else if(T[i].l==NIL&&T[i].r==NIL){
      printf("leaf\n");
    }
    else printf("internal node\n");
  }
  return 0;
}
