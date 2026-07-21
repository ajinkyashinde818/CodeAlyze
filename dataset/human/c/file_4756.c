#include<stdio.h>
#define MAX 100005
#define NIL -1
struct Node_struct{int p, r, l;}; /*p: 親(parent) l,r*/
typedef struct Node_struct Node;
Node T[MAX];
int D[MAX], H[MAX];

int height(int);
void print(int u){
  int i, c, n;
  printf("node %d: parent = %d, sibling = ", u, T[u].p);

  if(T[u].p==NIL)printf("%d, ",NIL);
  else if(T[T[u].p].r != u && T[T[u].p].r !=NIL)printf("%d, ",T[T[u].p].r);
  else if(T[T[u].p].l != u && T[T[u].p].l !=NIL)printf("%d, ",T[T[u].p].l);
  else printf("%d, ",-1);
  
  i=0;
  if(T[u].l != NIL)i++;
  if(T[u].r != NIL)i++;
  

  printf("degree = %d, ",i);

  printf("depth = %d, ",D[u]);

 
  printf("height = %d, ",H[u]);
  
  if(T[u].p == NIL/*ここを埋める (fill this blank)*/) printf("root\n");
  else if(T[u].l == NIL && T[u].r == NIL) printf("leaf\n");
  else printf("internal node\n");
  
  
}

void calcDepth(int u, int p){
  D[u] = p;
 
  if(T[u].l != NIL/*ここを埋める(fill this blank)*/) {
    calcDepth(T[u].l, p+1/*ここを埋める(fill this blank)*/);
   }
 
  if(T[u].r != NIL/*ここを埋める(fill this blank)*/) {
    calcDepth(T[u].r, p+1/*ここを埋める(fill this blank)*/);
   }
}

int height(int u){
  int h1 = 0, h2 = 0;

  
  
  if(T[u].l != NIL/*ここを埋める(fill this blank)*/) {
    h1 = height(T[u].l) + 1;
   }
 
  if(T[u].r != NIL/*ここを埋める(fill this blank)*/) {
    h2 = height(T[u].r) + 1 ;
   }
 
  if(h1 > h2)return H[u] =  h1;
  else return H[u] = h2;
}

int main(){
  int i, j, k;
  int n;
  int id, sib, child;
  int root = NIL;
 scanf("%d", &n);
  for(i=0; i<n; i++) T[i].p = T[i].l = T[i].r  = NIL;
  
  for(i=0; i<n; i++){
    scanf("%d", &id);
    for(j = 0, sib = NIL; j<2; j++){ //子を入力する (input children)
      scanf("%d", &child);
      T[child].p = id;
      if(j == 0) T[id].l = child; //idの一番左の子 (the most left child of id)
      else T[id].r = child; //左の兄弟に繋げる (connect to left sibling)
    }
  }

  //根を求める (find the root)
  for(i=0; i<n; i++){
    if(T[i].p == -1) root = i;
   
  }
  
  //それぞれのノードの深さを求める (find depth of each node)
  calcDepth(root, 0);
  i = height(root);

  //出力 (output)
  for(i=0; i<n; i++) print(i);

 
  return 0;
}
