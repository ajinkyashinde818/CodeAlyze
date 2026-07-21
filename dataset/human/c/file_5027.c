#include<stdio.h>
#define NIL -1
struct Node_struct{int p, l, r, s, d;};
typedef struct Node_struct Node;
Node T[25];
int D[25];
int H[25];

void print(int u){
int i, c;
printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ", u, T[u].p, T[u].s, T[u].d+1, D[u], H[u]);

if(T[u].p == NIL) printf("root\n");
else if(T[u].l == NIL && T[u].r == NIL) printf("leaf\n");
else printf("internal node\n");

}

void calcDepth(int u, int p){
D[u] = p;
if(T[u].l != NIL) calcDepth(T[u].l,p+1);
if(T[u].r != NIL) calcDepth(T[u].r,p+1);
}

void calcHeight(int u){
if(T[u].d == NIL) H[u] = 0;
else{
if(T[u].l != NIL) calcHeight(T[u].l);if(T[u].r != NIL) calcHeight(T[u].r);

H[u] = H[T[u].l]+1;
if( H[T[u].l] < H[T[u].r]) H[u] = H[T[u].r]+1;
}
}

int main(){
int i, j;
int n;
int id,l,r;
int root = NIL;
scanf("%d", &n);
for(i=0; i<n; i++) T[i].p = T[i].l = T[i].r = T[i].s = T[i].d = H[i] = NIL;

for(i=0; i<n; i++)
  {
scanf("%d %d %d", &id, &l, &r);
if(l != -1)
  {
T[id].l = l;
T[l].p = id;
T[id].d++;
if(r != -1) T[l].s = r;
}
if(r != -1)
  {
T[id].r = r;
T[r].p = id;
T[id].d++;
if(l != -1) T[r].s = l;
}

}

//根を求める (find the root)
for(i=0; i<n; i++){
if(T[i].p == -1) root = i;
}

//それぞれのノードの深さを求める (find depth of each node)
calcDepth(root, 0);

calcHeight(root);

//出力 (output)
for(i=0; i<n; i++) print(i);

  return 0;
}
