#include<stdio.h>
#include<stdlib.h>
#define MAX 100005
#define NIL -1
struct Node_struct{int p, l, r;}; /*p: 親(parent), l: 一番左の子(left child), r:右の兄弟(right sibling)*/
typedef struct Node_struct Node;
Node T[MAX];
int D[MAX];
int H[MAX];
int n;
int sibling(int);

void print(int u){
  int i,z, degree=0;
  if(T[u].l!=NIL)degree++;
  if(T[u].r!=NIL)degree++;
  z=sibling(u);
  printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ", u, T[u].p,z,degree, D[u],H[u]);

  if(T[u].p==-1) printf("root");
  else if(T[u].l==-1&&T[u].r==NIL) printf("leaf");
  else printf("internal node");
  printf("\n");

}
void calcDepth(int u, int p){
  if(u==NIL)return;
  D[u] = p;
  if(T[u].r!=NIL) calcDepth(T[u].r,p+1);
  if(T[u].l!=NIL) calcDepth(T[u].l,p+1);
}

int HEIGHT(int u){
  int k,h1=0,h2=0;
  if(T[u].r!=NIL)h1=HEIGHT(T[u].r)+1;
  if(T[u].l!=NIL)h2=HEIGHT(T[u].l)+1;
  if(h1>h2)H[u]=h1;
  else H[u]=h2;
  return H[u];
  


}
int main(){
  int i, j, k;
  int id, sib, child,left,right;
  int root = NIL;
  scanf("%d", &n);
  for(i=0; i<n; i++) T[i].p = T[i].l = T[i].r = NIL;
   for(i=0; i<n; i++){
    scanf("%d %d %d",&child, &left, &right);
    if(left!=NIL)T[left].p=child;
    if(right!=NIL)T[right].p=child;
    T[child].l = left;
    T[child].r = right;
  }


//根を求める (find the root)                                                                                 
for(i=0; i<n; i++){
  if(T[i].p == -1) root = i;
 }

//それぞれのノードの深さを求める (find depth of each node)                                                   
calcDepth(root, 0);
HEIGHT(root);
//出力 (output)                                                                                              
for(i=0; i<n; i++) print(i);

return 0;
}

int sibling(int u){
  int i,j;
  if(T[u].p==NIL)return NIL;
  /*for(i=0;;i++){
    if(u!=i&&D[u]==D[i])return D[j];
    return -1;
    }*/
  if(T[T[u].p].l!=u&&T[T[u].p].l!=NIL)
  return T[T[u].p].l;
 if(T[T[u].p].r!=u&&T[T[u].p].r!=NIL)
return T[T[u].p].r;
return -1;
}
