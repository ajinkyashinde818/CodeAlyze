#include<stdio.h>

#define NIL -1
#define MAX 10000

typedef struct Node{
  int id;
  int p;
  int left;
  int right;
  int s;
  int deg;
  int dep;
  int h;
  char* type;
}Node;

Node T[MAX];

int getdeg(int);
int getdep(int);
int geth(int);
char* gettype(int);

int d;

int main(){
  int n,i,u;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    T[i].p=NIL;
    T[i].s=NIL;
    T[i].left=NIL;
    T[i].right=NIL;
    T[i].deg=0;
    T[i].dep=0;
    T[i].h=0;
  }
  
  for(i=0;i<n;i++){
    scanf("%d",&u);
    T[u].id=u;
    scanf("%d%d",&T[u].left,&T[u].right); 
    T[T[u].left].p=T[u].id;
    T[T[u].left].s=T[u].right;
    T[T[u].right].p=T[u].id;
    T[T[u].right].s=T[u].left;
  }

  for(i=0;i<n;i++){
    T[i].deg=getdeg(i);
    T[i].dep=getdep(i);
    T[i].h=geth(i);
    T[i].type=gettype(i);
    d=0;
  }

  for(i=0;i<n;i++){
    printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, %s\n",i,T[i].p,T[i].s,T[i].deg,T[i].dep,T[i].h,T[i].type);
  }

  return 0;
}

int getdeg(int u){
  if((T[u].left==NIL)&&(T[u].right==NIL))
    return 0;
  else if((T[u].left!=NIL)&&(T[u].right!=NIL))
    return 2;
  else 
    return 1;
}


int getdep(int u){
  if(T[u].p==NIL)
    return d;
  else{
    d++;
    return getdep(T[u].p);
  }
}

int geth(int u){
  int h1=0,h2=0;
  if(T[u].right!= NIL)
    h1=geth(T[u].right)+1;
  if(T[u].left!=NIL)
    h2=geth(T[u].left)+1;
  return (h1 > h2 ? h1 : h2);
}
char* gettype(int u){
  if(T[u].p != NIL){
    if((T[u].left == NIL)&&(T[u].right == NIL))
      return "leaf";
    else
      return "internal node";
  }
  else
    return "root";
}
