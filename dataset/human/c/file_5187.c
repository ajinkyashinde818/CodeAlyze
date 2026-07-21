#include <stdio.h>
#define N 10000

struct Node{
  int parent;
  int left;
  int right;
};

struct Node node[N];
int n,D[N],H[N];

void setDepth(int u,int d){
  if(u==-1)return;
  D[u] = d;
  setDepth(node[u].left,d+1);
  setDepth(node[u].right,d+1);
}

int setHeight(int u){
  int h1 = 0;
  int h2 = 0;
  if(node[u].left != -1){
    h1 = setHeight(node[u].left) + 1;
  }
  if(node[u].right != -1){
    h2 = setHeight(node[u].right) + 1;
  }
  return H[u] = (h1 > h2 ? h1 : h2);
}

int getSibling(int u){
  if(node[u].parent == -1) return -1;
  if(node[node[u].parent].left != u && node[node[u].parent].left != -1){
    return node[node[u].parent].left;
  }
  if(node[node[u].parent].right != u && node[node[u].parent].right != -1){
    return node[node[u].parent].right;
  }
  return -1;
}

void print(int u){
  int degree = 0;
  printf("node %d: ",u);
  printf("parent = %d, ",node[u].parent);
  printf("sibling = %d, ",getSibling(u));

  if(node[u].left != -1) degree++;
  if(node[u].right != -1) degree++;

  printf("degree = %d, ",degree);
  printf("depth = %d, ",D[u]);
  printf("height = %d, ",H[u]);

  if(node[u].parent == -1){
    printf("root\n");
  }
  else if(node[u].left == -1 && node[u].right == -1){
    printf("leaf\n");
  }
  else {
    printf("internal node\n");
  }
}

int main(){
  int i,v,l,r;
  int root=0;
  scanf("%d",&n);

  for(i=0; i<n; i++) node[i].parent = -1;

  for(i=0; i<n; i++){
    scanf("%d%d%d",&v,&l,&r);
    node[v].left = l;
    node[v].right = r;
    if(l != -1) node[l].parent = v;
    if(r != -1) node[r].parent = v;
  }

  for(i=0; i<n; i++){
    if(node[i].parent == -1) root = i;
  }
  setDepth(root,0);
  setHeight(root);

  for(i=0; i<n; i++) print(i);

  return 0;
}
