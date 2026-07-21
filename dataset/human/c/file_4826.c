#include<stdio.h>
#include<stdlib.h>
#define MAX 25
#define NIL -1
struct Node_struct{
  int p,r,l,s;
};
typedef struct Node_struct Node;
Node T[MAX];
int D[MAX], H[MAX];

int getSibling(int);
void calcDepth(int, int);
int setHeight(int);

int main(){
  int i, n, id, root = NIL;
  scanf("%d", &n);

  for(i = 0; i < n; i++) T[i].p = T[i].r = T[i].l = NIL;
  for(i = 0; i < n; i++){
    if(i == 0){
      T[0].p = NIL;
    }
    scanf("%d", &id);
    scanf("%d %d", &T[id].l, &T[id].r);
    T[T[id].r].p = T[T[id].l].p = id;
    T[T[id].r].s = T[id].r;
    T[T[id].l].s = T[id].l;
  }

  for(i=0; i<n; i++){
    if(T[i].p == -1) root = i;
  }

  calcDepth(root, 0);

  for(i=0; i<n; i++) {
    int deg=0;
    printf("node %d: parent = %d, ", i, T[i].p);
    printf("sibling = %d, ",getSibling(i));
    if(T[i].l != NIL){
      deg++;
    }
    if(T[i].r != NIL){
      deg++;
    }
    printf("degree = %d, ",deg);
    printf("depth = %d, ",D[i]);
    printf("height = %d, ",setHeight(i));
    if(T[i].p == NIL) printf("root");
    else if(T[i].l == T[i].r && T[i].l == NIL) printf("leaf");
    else printf("internal node");
    printf("\n");
  }
  return 0;
}

  int getSibling(int u){
    if(T[u].p == NIL){
      return NIL;
    }
    if(T[T[u].p].l != u && T[T[u].p].l != NIL){
      return T[T[u].p].l;
    }
    if(T[T[u].p].r != u && T[T[u].p].r != NIL){
      return T[T[u].p].r;
    }
    return NIL;
  }

  int setHeight(int u){
    int h1 = 0, h2 = 0;
    if(T[u].l != NIL){
      h1 = setHeight(T[u].l) + 1;
    }
    if(T[u].r != NIL){
      h2 = setHeight(T[u].r) +1;
    }
    if(h1 > h2){
      H[u] = h1;
    }else{
      H[u] = h2;
    }
    return H[u];
  }


  void calcDepth(int u, int p) {
    D[u] = p;
    if(T[u].l != NIL) calcDepth(T[u].l, p+1);
    if(T[u].r != NIL) calcDepth(T[u].r, p+1);
  }
