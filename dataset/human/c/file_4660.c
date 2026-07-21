#include <stdio.h>
#define MAX 10000
#define NIL -1

struct node {
  int parent,right,left;
};

struct node T[MAX];
int n;
int D[MAX],H[MAX];

int Depth(int u);
int bro(int u);
void print(int u);

int main(){
  int i,v,l,r;
  scanf("%d",&n);

  for(i=0;i<n;i++){
    T[i].parent=NIL;
  }


  for(i=0;i<n;i++){
    scanf("%d %d %d",&v,&l,&r);

    T[v].left=l;
    T[v].right=r;

    if(l!=NIL){
      T[l].parent=v;
    }
    if(r!=NIL){
      T[r].parent=v;
    }
  }


  for(i=0;i<n;i++){
    D[i]=Depth(i);
    H[i]=0;
  }

  for(i=0;i<n;i++){
    if (T[i].left==NIL && T[i].right==NIL ) {
      H[i]=0;
      int p=T[i].parent;
      int c=1;
      while(1){
        if (p==NIL) {
          break;
        }
        if (H[p]<c){
          H[p]=c;
        }
        c++;
        p=T[p].parent;

      }
    }
  }
  for (i=0;i<n;i++){
    print(i);
  }
  return 0;
}
int Depth(int u){
  int d=0;
  while(1){
    u=T[u].parent;
    if(u==NIL) {
      break;
    }
    d++;
  }
  return d;
}


int bro(int u){

  if(T[u].parent==NIL) {
    return NIL;
  }
  if(T[T[u].parent].left!=u && T[T[u].parent].left!=NIL) {
    return T[T[u].parent].left;
  }
  if(T[T[u].parent].right!=u && T[T[u].parent].right!=NIL) {
    return T[T[u].parent].right;
  }
  else  {
    return NIL;
  }
}

void print(int u){
  int deg=0;
  printf("node %d: ", u);
  printf("parent = %d, ", T[u].parent);
  printf("sibling = %d, ", bro(u));

  if (T[u].left!=NIL ) {
    deg++;
  }
  if (T[u].right!=NIL) {
    deg++;
  }

  printf("degree = %d, ", deg);
  printf("depth = %d, ", D[u]);
  printf("height = %d, ", H[u]);
  if (T[u].parent==NIL){
    printf("root\n");
  }
  else if (T[u].left==NIL && T[u].right==NIL){
    printf("leaf\n");
  }
  else {
    printf("internal node\n");
  }
}
