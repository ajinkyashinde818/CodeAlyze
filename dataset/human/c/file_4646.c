#include<stdio.h>
#define MAX 100005
#define NIL -1

struct Node{ int p, l, r, depth, degree, sibling, height;};
struct Node T[MAX];

int gheight;
int n;

void maketree(int id, int l, int r){
  if( l != -1 ){
    T[id].l = l;
    T[l].p = id;
    T[l].sibling = r;
    T[id].degree++;
  }
  if( r != -1 ){
    T[id].r = r;
    T[r].p = id;
    T[r].sibling = l;
    T[id].degree++;
  }
}

int search(int u, int i){
  while(1){
    if(i != u){
      i = T[i].p;
      gheight++;
    }
    if(i == -1){ 
      return 0;
      break;
    }
    else if(i == u) return 1;
  }
}

void print(int u){
  int i = 0;

  T[u].height = 0;
  for(i=0; i<n; i++){
    gheight = 0;
    if(T[i].r == -1 && T[i].l == -1){
      if(search(u, i) && gheight > T[u].height) T[u].height = gheight;
    }
  }
  if(T[u].p == -1){
    printf("node %d: parent = %d, ", u, T[u].p); 
    printf("sibling = %d, ", -1);
    printf("degree = %d, depth = %d, height = %d, root", T[u].degree, T[u].depth, T[u].height);
  }
  else if(T[u].l == -1 && T[u].r == -1) printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, leaf", u, T[u].p, T[u].sibling, T[u].degree, T[u].depth, 0);
  else printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, internal node", u, T[u].p, T[u].sibling, T[u].degree, T[u].depth, T[u].height);
}

int main(){
  int parent, i, id, l, r;

  scanf("%d",&n);
  for ( i = 0; i < n; i++ ) {
    T[i].p = T[i].l = T[i].r = T[i].sibling = NIL;
    T[i].height = 0;
  }
  for(i = 0; i < n; i++ ){
    scanf("%d%d%d",&id,&l,&r);
    maketree(id, l, r);
  }
  for(i = 0; i < n; i++ ){
    parent = T[i].p;
    while(1){
      if(parent == -1) break;
      parent = T[parent].p;
      T[i].depth++;
    }
    print(i);
    printf("\n");
  }
  return 0;
}
