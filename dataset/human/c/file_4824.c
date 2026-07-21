#include<stdio.h>
#define M 100000
#define N -1

typedef struct{
  int parent;
  int left;
  int right;
}Node;

Node T[M];
int n,D[M],H[M];

void setD(int,int);
int setH(int);
int setS(int);
void hyoji(int);

int main(){
  int v,i,l,r,root = 0;

  scanf("%d",&n);

  for(i = 0; i < n; i++) T[i].parent = N;

  for(i = 0; i < n; i++){
    scanf("%d %d %d",&v,&l,&r);
    T[v].left = l;
    T[v].right = r;
    if(l != N) T[l].parent = v;
    if(r != N) T[r].parent = v;
  }

  for(i = 0; i < n; i++){
    if(T[i].parent == N) root = i;
  }

  setD(root,0);
  setH(root);

  for(i = 0; i < n; i++) hyoji(i);

  return 0;
}

void setD(int u, int d){
  if(u == N) return;
  D[u] = d;
  setD(T[u].left, d+1);
  setD(T[u].right, d+1);
}

int setH(int u){
  int h = 0,k = 0;
  if(T[u].left != N) h = setH(T[u].left)+1;
  if(T[u].right != N) k = setH(T[u].right)+1;
  return H[u] = (h > k ? h : k);
}

int setS(int u){
  if(T[u].parent == N) return N;
  if(T[T[u].parent].left != u && T[T[u].parent].left != N) return T[T[u].parent].left;
  if(T[T[u].parent].right != u && T[T[u].parent].right != N) return T[T[u].parent].right;
  return N;
}

void hyoji(int u){
  printf("node %d: ",u);
  printf("parent = %d, ",T[u].parent);
  printf("sibling = %d, ",setS(u));
  int deg = 0;
  if(T[u].left != N) deg++;
  if(T[u].right != N) deg++;
  printf("degree = %d, ",deg);
  printf("depth = %d, ",D[u]);
  printf("height = %d, ",H[u]);

  if(T[u].parent == N) printf("root\n");
  else if(T[u].left == N && T[u].right == N) printf("leaf\n");
  else printf("internal node\n");
}
