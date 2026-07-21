#include<stdio.h>
#define MAX 100005
#define NIL -1
struct Node_struct{int p, l, r;}; /*p: 親(parent), l: 左の子(left child), r:右の子(right child)*/
typedef struct Node_struct Node;
Node T[MAX];
int D[MAX];
int calcHeight(int u){
int l=0,r=0;
if(T[u].l==-1 && T[u].r==-1)return 0;
else if(T[u].l==-1 && T[u].r!=-1)r=calcHeight(T[u].r);
else if(T[u].l!=-1 && T[u].r==-1)r=calcHeight(T[u].l);
else {
  l=calcHeight(T[u].l);
  r=calcHeight(T[u].r);
}
	if(l>r)return ++l;
	else return ++r;
}
void print(int u){
 int i, c, h;
 printf("node %d: parent = %d, sibling = ", u, T[u].p);
 if(T[u].p==-1)printf("-1");
 else if(T[T[u].p].l==u)printf("%d",T[T[u].p].r);
 else printf("%d",T[T[u].p].l);
 printf(", degree = ");
 if(T[u].l!=-1 && T[u].r!=-1)printf("2");
 else if(T[u].l==-1 && T[u].r==-1)printf("0");
 else printf("1");
 printf(", depth = %d, ", D[u]);
 h=calcHeight(u);
 printf("height = %d, ",h);
 if(T[u].p==-1) printf("root");
 else if(T[u].l==NIL && T[u].r==NIL) printf("leaf");
 else printf("internal node");
 printf("\n");
}
void calcDepth(int u, int p){
 D[u] = p;
 if(T[u].l!=NIL) calcDepth(T[u].l,p+1);
 if(T[u].r!=NIL) calcDepth(T[u].r,p+1);
}
int main(){
 int i, j, k;
 int n;
 int id, sib, child;
 int root = NIL;
 scanf("%d", &n);
 for(i=0; i<n; i++) T[i].p = T[i].l = T[i].r = NIL;
 for(i=0; i<n; i++){
   scanf("%d", &id);
   scanf("%d %d", &T[id].l,&T[id].r);
   T[T[id].l].p = T[T[id].r].p = id;
   }
 
 //根を求める (find the root)
 for(i=0; i<n; i++){
   if(T[i].p == -1) root = i;
 }
 //それぞれのノードの深さを求める (find depth of each node)
 calcDepth(root, 0);
 //calcHeight
 //出力 (output)
 /*s
 for(i=0; i<n; i++)
 printf("lc:%d, r:%d\n",T[i].l,T[i].r);
 e*/
 for(i=0; i<n; i++) print(i);
 return 0;
}
