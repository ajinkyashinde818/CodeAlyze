#include <stdio.h>
#define MAX 25

typedef struct{
  int parent;
  int left;
  int right;
}Node;

Node T[MAX];
int n, D[MAX], H[MAX];
void Depth(int, int);
int Height(int);
int Sibling(int);

int main(){
  int i, id, l, r, root = 0, count = 0;
  scanf("%d",&n);
  for(i = 0; i < n; i++){
    T[i].parent = -1;
  }
  for(i = 0; i < n; i++){
    scanf("%d%d%d",&id, &l, &r);
    T[id].left = l;
    T[id].right = r;
    if(l != -1) T[l].parent = id;
    if(r != -1) T[r].parent = id;
  }
  for(i = 0; i < n; i++){
    if(T[i].parent == -1) root = i;
    Depth(root,0);
    Height(root);
  }

  for(i = 0; i < n; i++){
    count = 0;
    printf("node %d: parent = %d, sibling = %d, ",i, T[i].parent, Sibling(i));
    if(T[i].left != -1) count++;
    if(T[i].right != -1) count++;    
    printf("degree = %d, depth = %d, height = %d, ",count, D[i], H[i]);
    if(T[i].parent == -1) printf("root\n");
    else if(T[i].left == -1 && T[i].right == -1) printf("leaf\n");
    else printf("internal node\n");
  }

  return 0;
}

void Depth(int r, int p){
  if(r == -1) return;
  D[r] = p;
  Depth(T[r].left, p+1);
  Depth(T[r].right, p+1);
}

int Height(int r){
  int hl = 0, hr = 0;
  if( T[r].left != -1) hl = Height(T[r].left)+1;
  if( T[r].right != -1) hr = Height(T[r].right)+1;
  if( hl > hr ){
    H[r] = hl;
    return H[r];
  }
  else{
    H[r] = hr;
    return H[r];
  }
}

int Sibling(int r){
  if(T[r].parent == -1) return -1;
  if(T[T[r].parent].left != r && T[T[r].parent].left != -1) return T[T[r].parent].left;
  if(T[T[r].parent].right != r && T[T[r].parent].right != -1) return T[T[r].parent].right;
  return -1;
}
