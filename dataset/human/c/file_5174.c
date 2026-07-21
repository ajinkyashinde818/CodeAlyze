#include<stdio.h>
#define MAX 100005
#define NIL -1
struct Node_struct{int p, l, r ,s,h;}; /*p: 親(parent), l: 一番左の子(left child), r:右の兄弟(right sibling),s(兄弟)*/
typedef struct Node_struct Node;
Node T[MAX];
int D[MAX];

void print(int u){
  int i, d=0;
  printf("node %d: parent = %d, sibling = %d,", u, T[u].p,T[u].s);
  
  if(T[u].r!=NIL)d++;
  if(T[u].l!=NIL)d++;
  printf(" degree = %d, depth = %d, height = %d, ",d, D[u],T[u].h);

  
  if(T[u].p==NIL) printf("root\n");
  else if(T[u].l==NIL && T[u].r==NIL) printf("leaf\n");
  else printf("internal node\n");
  
  
}

int calcDepth(int u, int p){
  int h1=0,h2=0; /* 再帰しない時の為の初期化 */
  D[u] = p;
  if(T[u].l!=NIL) h1=calcDepth(T[u].l,p+1);
  if(T[u].r!=NIL) h2=calcDepth(T[u].r,p+1);

  if(T[u].l==NIL && T[u].r==NIL){
    T[u].h=0;
    return 1;
  }

  T[u].h=h1<h2 ? h2 : h1;
  return T[u].h+1;
}

int main(){
  int i, j, k;
  int n;
  int id, l,r, child;
  int root = NIL;
  scanf("%d", &n);
  for(i=0; i<n; i++) T[i].p = T[i].l = T[i].r =T[i].s= NIL;
  
  for(i=0; i<n; i++){
    scanf("%d%d%d", &id,&l,&r);
     //子を入力する (input children)
      
      T[l].p = id;
      T[r].p = id;
      T[l].s = r;
      T[r].s = l;
      T[id].r=r;
      T[id].l=l;
      
    
  }

  //根を求める (find the root)
  for(i=0; i<n; i++){
    if(T[i].p == -1) root = i;
  }
  
  //それぞれのノードの深さを求める (find depth of each node)
  calcDepth(root, 0);

  //出力 (output)
  for(i=0; i<n; i++) print(i);
  
  return 0;
}
