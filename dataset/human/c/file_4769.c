#include <stdio.h>
#define N 25
#define EMPTY -1

typedef struct {
  int parent;
  int left;
  int right;
} Node;

int depth[N];
int height[N];
Node node[N];

void depthcount(int x, int d){
  if(x == EMPTY) return;
  depth[x] = d;
  depthcount(node[x].right,d+1);
  depthcount(node[x].left,d+1);
}

int heightcount(int x){
  int h1=0, h2=0;
  if(node[x].right != EMPTY) h1 = heightcount(node[x].right)+1;
  if(node[x].left != EMPTY) h2 = heightcount(node[x].left)+1;
  if(h1 >= h2) return height[x] = h1;
  else return height[x] = h2;
}  

int siblingcount(int x){
  if(node[x].parent == EMPTY) return EMPTY;
  else if(node[node[x].parent].left != EMPTY && node[node[x].parent].left != x) return node[node[x].parent].left;
  else if(node[node[x].parent].right != EMPTY && node[node[x].parent].right != x) return node[node[x].parent].right;
  return EMPTY;
}

int degcount(int x){
  int count=0;
  if(node[x].right != EMPTY) count++;
  if(node[x].left != EMPTY) count++;
  return count;
} 

int main(){
  int i,j,n,l,r,child,root=0,id;

  scanf("%d",&n);
  for(i=0; i<n; i++) {
    node[i].left = EMPTY;
    node[i].right = EMPTY;
    node[i].parent = EMPTY;
  }


  for(i=0; i<n; i++){
    scanf("%d%d%d",&id,&l,&r);
    node[id].left = l;
    node[id].right = r;
    if(l != EMPTY) node[l].parent = id;
    if(r != EMPTY) node[r].parent = id;
  }


  for(i=0; i<n; i++) if(node[i].parent == EMPTY) root = i;
  depthcount(root,0);  //根と深さの数がはいる
  heightcount(root);

  for(i=0; i<n; i++){
    printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ",i,node[i].parent,siblingcount(i),degcount(i),depth[i],height[i]);
    if(node[i].parent == EMPTY) printf("root\n");
    else if(node[i].left == EMPTY && node[i].right == EMPTY) printf("leaf\n");
    else printf("internal node\n");
  }

  return 0;
}
