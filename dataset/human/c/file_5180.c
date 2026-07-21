#include<stdio.h>

#define MAX 30
#define NIL -1

typedef struct node{
  int parent;
  int left;
  int right;
}Node;

Node T[MAX];
int Dep[MAX], Hei[MAX];

void print(int u){
  int i, sib, deg = 0;
  int parent = T[u].parent; 
  printf("node %d: parent = %d, ", u, T[u].parent);
  
  if(T[u].parent == NIL) sib = NIL;
  else{
    if(T[parent].right != u) sib = T[parent].right;
    if(T[parent].left != u) sib = T[parent].left;
  }
  printf("sibling = %d, ", sib);

  if(T[u].right != NIL) deg++;
  if(T[u].left != NIL) deg++;
  printf("degree = %d, ",deg);
  
  printf("depth = %d, height = %d, ", Dep[u], Hei[u]);

  if(T[u].parent == NIL) printf("root");
  else if(T[u].left == NIL && T[u].right == NIL) printf("leaf");
  else printf("internal node");
  printf("\n");
}

int calcHeight(int u){
  int h1 = 0, h2 = 0;
  int maxh;
  if(T[u].right != NIL) h1 = calcHeight(T[u].right) + 1;
  if(T[u].left != NIL) h2 = calcHeight(T[u].left) + 1;

  if(h1 > h2) maxh = h1;
  else maxh = h2;
  return maxh;
}

void calcDepth(int u, int p){
  Dep[u] = p;
  if(T[u].right != NIL) calcDepth(T[u].right, p+1);
  if(T[u].left != NIL) calcDepth(T[u].left, p+1);
}

int main(){
  int i, j, n;
  int id, left, right;
  int root = NIL;
  
  scanf("%d",&n);
  for(i=0; i<n; i++){
    T[i].parent = NIL;
    T[i].left = NIL;
    T[i].right = NIL;
  }

  for(i=0; i<n; i++){
    scanf("%d%d%d",&id,&left,&right);
    T[id].left = left;
    T[id].right = right;
    if(left != NIL) T[left].parent = id;
    if(right != NIL) T[right].parent = id;
  }
  for(i=0; i<n; i++){
    if(T[i].parent == -1) root = i;
  }

  
  calcDepth(root, 0);
  for(i=0; i<n; i++) Hei[i] = calcHeight(i);
  for(i=0; i<n; i++) print(i);
  return 0;
}
