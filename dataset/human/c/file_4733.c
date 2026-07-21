#include <stdio.h>
#define NIL -1
#define MAX 10000

void print(int);


typedef struct{
  int left,right,parent;
}node;

node T[MAX];
int n,D[MAX];
int H[MAX];

int main(){
  int i,j;
  int a,l,r;
  int root;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    T[i].parent = NIL;
  }
  for(i=0;i<n;i++){
    scanf("%d %d %d",&a,&l,&r);
    T[a].left = l;
    T[a].right = r;
    if( l != NIL) T[l].parent = a;
    if( r != NIL) T[r].parent = a;
  }
  for(i = 0; i <n; i++){
    if(T[i].parent == NIL) root = i;
  }
  setDepth(root,0);
  setHeight(root);

  for(i = 0; i <n; i++) print(i);
  
}

int setDepth(int u,int d){
  if(u == NIL) return NIL;
  D[u] = d;
  setDepth(T[u].left,d + 1);
  setDepth(T[u].right, d + 1);
}

int setHeight(int u){
  int h1=0;
  int h2=0;
  if(T[u].left != NIL) h1 = setHeight(T[u].left) +1;
  if(T[u].right != NIL) h2 = setHeight(T[u].right) +1;
  if(h1>h2){
    H[u] = h1;
  }
  else{
    H[u] = h2;
  }
    return H[u];
}

int getSibling(int u){
  if(T[u].parent == NIL) return NIL;
  if(T[T[u].parent].right != u && T[T[u].parent].right !=NIL)
    return T[T[u].parent].right;
  if(T[T[u].parent].left != u &&T[T[u].parent].left !=NIL )
    return  T[T[u].parent].left;
  return NIL;
}

void print(int u){
  int i,c;
  int deg=0;
  printf("node %d: parent = %d, ",u,T[u].parent);
  if(T[u].right != NIL) deg++;
  if(T[u].left != NIL) deg++;
  printf("sibling = %d, degree = %d, ",getSibling(u),deg);
  printf("depth = %d, height = %d, ",D[u],H[u]);
  
  if(T[u].parent==NIL) printf("root");
  else if(T[u].left == NIL && T[u].right == NIL) printf("leaf");
  else printf("internal node");
  printf("\n");
}
