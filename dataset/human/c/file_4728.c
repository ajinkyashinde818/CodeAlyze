#include<stdio.h>
#define MAX 100005
#define NIL -1
struct Node_struct{int p, l, r;}; /*p: 親(parent), l: 一番左の子(left child), r:右の兄弟(right sibling)*/
typedef struct Node_struct Node;
Node T[MAX];
int D[MAX];/*depth*/
int H[MAX];/*height*/
int n;

int sibling(int u){
 if(T[u].p == NIL) return NIL;
 if(T[T[u].p].l != u && T[T[u].p].l != NIL) return  T[T[u].p].l;
 if(T[T[u].p].r != u && T[T[u].p].r != NIL) return T[T[u].p].r;
 return NIL;
}

void print(int u){
 int i, c;
 int degree=0;

 if(T[u].l != NIL) degree=degree+1;
 if(T[u].r != NIL) degree=degree+1;

 printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ", u, T[u].p,sibling(u),degree, D[u],H[u]);

 if(T[u].p == NIL) printf("root");
 else if(T[u].l == NIL && T[u].r == NIL) printf("leaf");
 else printf("internal node");

 printf("\n");

}

void calcDepth(int u, int p){
//if(u==NILL) return;
 D[u] = p;
 if(T[u].r != NIL) calcDepth(T[u].r,p+1);
 if(T[u].l != NIL) calcDepth(T[u].l,p+1);
}


int calcHeight(int u){
 int h1=0,h2=0;
 if(T[u].r != NIL) h1=calcHeight(T[u].r)+1;
 if(T[u].l != NIL) h2=calcHeight(T[u].l)+1;

 if(h1 > h2) return H[u]=h1;
 else return H[u]=h2;
}

int main(){
 int i, j, k;
 int n;
 int id, left, right;
 int root = NIL;

 scanf("%d", &n);
 for(i=0; i<n; i++) T[i].p = T[i].l = T[i].r = NIL;

 for(i=0; i<n; i++){
   scanf("%d", &id);
   scanf("%d %d", &left, &right);
   T[id].r = right;
   T[id].l = left;
   if(right != NIL) T[right].p = id;
    if(left != NIL) T[left].p = id;
 }

 //根を求める (find the root)
 for(i=0; i<n; i++){
   if(T[i].p == NIL) root = i;
 }

 //それぞれのノードの深さを求める (find depth of each node)
 calcDepth(root, 0);
 calcHeight(root);

 //出力 (output)
 for(i=0; i<n; i++) print(i);

 return 0;
}
