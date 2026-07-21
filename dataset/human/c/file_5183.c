#include<stdio.h>
#define MAX 100005
#define NIL -1
struct Node_struct{int p, l, r, d, sib;}; /*p: 親(parent), l: 一番左の子(left child), r:右の兄弟(right sibling)*/
typedef struct Node_struct Node;
Node T[MAX];
int D[MAX];
int H[MAX];

void print(int u){
  int i, c;
  printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ", u, T[u].p, T[u].sib, T[u].d, D[u], H[u]);

  if(T[u].p == NIL) printf("root\n");
  else if(T[u].l == NIL && T[u].r == NIL) printf("leaf\n");
  else printf("internal node\n");
}

void calcDepth(int u, int p){
  D[u] = p;
  if(T[u].l != NIL) calcDepth(T[u].l ,p + 1);
  if(T[u].r != NIL) calcDepth(T[u].r ,p + 1);
}


int calcHeight(int u){
  int hl = 0, hr = 0;

  if(T[u].l != NIL) hl = calcHeight(T[u].l) + 1;
  if(T[u].r != NIL) hr = calcHeight(T[u].r) + 1;

  if(hl > hr){
    H[u] = hl;
    return hl;
  }
  else{
    H[u] = hr;
    return hr;
  }
}

int main(){
  int i, j, k;
  int n;
  int id, child, sib;
  int root = NIL;
  scanf("%d", &n);
  for(i=0; i<n; i++) {
    T[i].p = T[i].l = T[i].r = T[i].sib = NIL;
    T[i].d = 0;
  }

  for(i=0; i<n; i++){
    scanf("%d", &id);
    for(j = 0, sib = NIL; j<2; j++){ //子を入力する (input children)                                                                                       
      scanf("%d", &child);
      if(child == -1)
        continue;
      else{
        T[child].p = id;
        if(j == 0){
          T[id].l = child;
          sib = child;
        }
        else{
          T[id].r = child;
          T[child].sib = sib;
          if(sib != NIL)
            T[sib].sib = child;
        }
        T[id].d++;
      }
    }
  }

  //根を求める (find the root)                                                                                                                             
  for(i=0; i<n; i++){
    if(T[i].p == -1) root = i;
  }

  //それぞれのノードの深さを求める (find depth of each node)                                                                                               
  calcDepth(root, 0);

  //高さを求める                                                                                                                                           
  calcHeight(root);

  //出力 (output)                                                                                                                                          
  for(i=0; i<n; i++) print(i);

  return 0;
}
