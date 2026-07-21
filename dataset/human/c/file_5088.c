#include<stdio.h>
#include<stdlib.h>
#define MAX 100005
#define NIL -1
struct Node_struct{int p, l, r, sib;}; /*p: 親(parent), l: 一番左の子(left chil\
d), r:右の兄弟(right sibling)*/
typedef struct Node_struct Node;
Node T[MAX];
int D[MAX];
int deg[MAX];
int hei[MAX];

void print(int u){
  int i, c;
  printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height =\
 %d, ", u, T[u].p, T[u].sib, deg[u], D[u], hei[u]);

  if(T[u].p == -1) printf("root");
  else if(T[u].l == NIL && T[u].r == NIL) printf("leaf");
  else printf("internal node");
  printf("\n");

}
void calcDegree(int n){
  int i;
  for(i=0;i<n;i++){
    deg[i] = 0;
  }
  for(i=0;i<n;i++){
    if(T[i].p != -1) deg[T[i].p]++;
  }
}

void calcDepth(int u, int p){
  D[u] = p;
  if(T[u].r != NIL) calcDepth(T[u].r, p+1);
  if(T[u].l != NIL) calcDepth(T[u].l, p+1);
}


int max(int a ,int b){
  if(a>b) return a;
  else return b;
}

int calcHeight(int n){
  int h1 = 0, h2 = 0;
  if(T[n].l != NIL) h1 = calcHeight(T[n].l) +1;
  if(T[n].r != NIL) h2 = calcHeight(T[n].r) +1;

  return hei[n] = max(h1, h2);
}




int main(){
  int i, j, k;
  int n;
  int id, child1, child2;
  int root = NIL;
  scanf("%d", &n);
  for(i=0; i<n; i++) T[i].p = T[i].l = T[i].r = T[i].sib = NIL;

  for(i=0; i<n; i++){
    scanf("%d %d %d", &id, &child1, &child2);
    T[id].l = child1;
    T[id].r = child2;
    if(child1 != NIL) T[child1].p = id;
    if(child2 != NIL) T[child2].p = id;
    T[child1].sib = child2;
    T[child2].sib = child1;
  }




  //根を求める (find the root)                                                  
  for(i=0; i<n; i++){
    if(T[i].p == -1) root = i;
  }

  calcDegree(n);// ノードの子の数を求める                                       

  //それぞれのノードの深さを求める (find depth of each node)                    
  calcDepth(root, 0);

  calcHeight(root);


  //出力 (output)                                                               
  for(i=0; i<n; i++) print(i);

  return 0;
}
