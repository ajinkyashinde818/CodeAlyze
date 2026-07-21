#include<stdio.h>
#define MAX 100000
#define NIL -1

struct Node{
  int p,l,r;
};

struct Node T[MAX];

int getDepth(int u){
  int d = 0;
  while(T[u].p != NIL){
    u = T[u].p;
    d++;
  }
  return d;
}

int getHeight(int u){
  int h1=0,h2=0;
  if (T[u].l != NIL) h1 = getHeight(T[u].l)+1;
  if (T[u].r != NIL) h2 = getHeight(T[u].r)+1;

  if(h1 > h2) return h1;
  else return h2;
}

int getSibling(int u){
  int sib;
  if (T[u].p == NIL) sib = NIL;
  else if (T[T[u].p].l != NIL && T[T[u].p].r != NIL){
    if (T[T[u].p].l == u) sib = T[T[u].p].r;
    if (T[T[u].p].r == u) sib = T[T[u].p].l;
  }
  return sib;
}

void print(int u){
  int degree = 0;
  
  printf("node %d: parent = %d, sibling = %d, ",u,T[u].p,getSibling(u));
  if (T[u].l != NIL) degree++;
  if (T[u].r != NIL) degree++;
  printf("degree = %d, depth = %d, height = %d, ",degree,getDepth(u),getHeight(u));

  if(T[u].p == NIL) printf("root\n");
  else if(T[u].l == NIL && T[u].r == NIL) printf("leaf\n");
  else printf("internal node\n");
}

int main(){
  int i;
  int n,id,l,r;

  scanf("%d",&n);

  for(i=0; i<n; i++) T[i].p = NIL;

  for(i=0; i<n; i++){
    scanf("%d%d%d",&id,&l,&r);
    T[id].l = l;
    T[id].r = r;
    if (l != NIL) T[l].p = id;
    if (r != NIL) T[r].p = id;
  }

  for(i=0; i<n; i++) print(i);

  return 0;
}
