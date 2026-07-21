#include<stdio.h>
#define MAX 30
#define NIL -1
struct Node_struct{int p, l, r, s;}; 
typedef struct Node_struct Node;
Node T[MAX];
int D[MAX];
int Deg[MAX];
int H[MAX];

void print(int u){
 int i, c;
 printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d", u, T[u].p, T[u].s, Deg[u], D[u], H[u]);

 if(D[u] == 0) printf(", root");
 else if(H[u] == 0) printf(", leaf");
 else printf(", internal node");

 printf("\n");

}

void calcDegree(int u){
  if(T[u].r != NIL){
    Deg[u]++;
    calcDegree(T[u].r);
  }
  if(T[u].l != NIL){
    Deg[u]++;
    calcDegree(T[u].l);
  }
}

void calcDepth(int u, int p){
 D[u] = p;
 if(T[u].r != NIL) calcDepth(T[u].r,p+1);
 if(T[u].l != NIL) calcDepth(T[u].l,p+1);
}

int calcHeight(int u){
  int l=0,r=0;
  if(T[u].r == NIL && T[u].l == NIL){
    H[u] = 0;
    return 0;
  }
  if(T[u].r != NIL)r = calcHeight(T[u].r)+1;
  if(T[u].l != NIL)l = calcHeight(T[u].l)+1;
  if(l>r)H[u] = l;
  else H[u] = r;
  return H[u];
}

int main(){
 int i, j, k;
 int n;
 int id, child;
 int root = NIL;
 scanf("%d", &n);
 for(i=0; i<n; i++) T[i].p = T[i].l = T[i].r = T[i].s = NIL;

 for(i=0; i<n; i++){
   scanf("%d", &id);
   for(j = 0; j<2; j++){ //子を入力する (input children)
     scanf("%d", &child);
     T[child].p = id;
     if(j == 0) T[id].l = child; //idの一番左の子 (the most left child of id)
     else{
       T[id].r = child;
       T[T[id].r].s = T[id].l;
       T[T[id].l].s = T[id].r;
     } //左の兄弟に繋げる (connect to left sibling)
     //次の子供の左の兄弟 (the left sibling of the next child)
   }
 }

 //根を求める (find the root)
 for(i=0; i<n; i++){
   if(T[i].p == -1) root = i;
 }

 calcDegree(root);

 //それぞれのノードの深さを求める (find depth of each node)
 calcDepth(root, 0);

 calcHeight(root);

 //出力 (output)
 for(i=0; i<n; i++) print(i);

 return 0;
}
