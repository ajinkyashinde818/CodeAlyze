#include<stdio.h>

#define MAX 100005
#define NIL -1

struct Node_struct{

  int p, l, r;   /* p:親　l:一番左の子　r:右の兄弟 */
};
typedef struct Node_struct Node;

Node T[MAX];
int D[MAX], H[MAX], S[MAX], DEG[MAX];

void print(int u){

  int i;
  printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ", u, T[u].p, S[u], DEG[u], D[u], H[u]);

  if(T[u].p == NIL)
    printf("root");

  else if(T[u].l == NIL && T[u].r == NIL)
    printf("leaf");

  else printf("internal node");

  printf("\n");
}

void calcDepth(int u, int p){

  D[u] = p;
  if(T[u].l != NIL)
    calcDepth(T[u].l, p + 1);

  if(T[u].r != NIL)
    calcDepth(T[u].r, p + 1);
}

int height(int u){

  int hl = 0, hr = 0;

  if(u == NIL) return 0;

  hl = height(T[u].l) + 1;
 hr = height(T[u].r) + 1;

  if(hl > hr) {
    H[u] = hl - 1;
    return hl;
  }
  else {
    H[u] = hr - 1;
    return hr;
  }
}

int main(){

  int i, j, k;
  int n;
  int id, sib, child;
  int root = NIL;

  scanf("%d", &n);

  for(i = 0; i < n; i++)
    T[i].p = T[i].l = T[i].r = S[i] = NIL;

  for(i = 0; i < n; i++){
scanf("%d", &id);

    for(j = 0, sib = NIL; j < 2; j++){
      scanf("%d", &child);
      T[child].p = id;
      if(j == 0)
        T[id].l = child;
      else
        T[id].r = child;
    }
  }

  for(i = 0; i < n; i++){

    S[T[i].l] = T[i].r;
    S[T[i].r] = T[i].l;
  }

  for(i = 0; i < n; i++){

    if(T[i].l != NIL && T[i].r != NIL)
      DEG[i] = 2;
    else if(T[i].l != NIL || T[i].r != NIL)
      DEG[i] = 1;
   else
      DEG[i] = 0;
  }

  for(i = 0; i < n; i++){

    if(T[i].p == -1)
      root = i;
  }

  calcDepth(root, 0);
  height(root);

  for(i = 0; i < n; i++)
    print(i);

  return 0;
}
