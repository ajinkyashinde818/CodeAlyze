#include<stdio.h>

struct Node_struct{int id, par, dep, left, right, sib, height;};
typedef struct Node_struct Node;
Node node[200000];

int dfs(int pos, int dep){
  node[pos].dep = dep;
  int a = 0, b = 0;
  if(node[pos].left != -1) a = dfs(node[pos].left, dep + 1);
  if(node[pos].right != -1) b = dfs(node[pos].right, dep + 1);
  node[pos].height = a < b? b:a;
  return node[pos].height + 1;
}

int main(){
  int i, j, k;
  int N;
  int id, left, right;
  int deg;
  int root;
  scanf("%d", &N);
  for(int i=0;i<N;i++) node[i].par = node[i].left = node[i].right = node[i].sib = -1;
  
  for(i=0;i<N;i++){
    scanf("%d %d %d", &id, &left, &right);
    node[id].id = id;
    node[id].left = left;
    node[id].right = right;
    if(left != -1) node[left].par = id, node[left].sib = right;
    if(right != -1) node[right].par = id, node[right].sib = left;
  }
  
  for(i=0;i<N;i++) if(node[i].par == -1) root = i;
  dfs(root, 0);

  for(i=0;i<N;i++){
    deg = (node[i].left != -1) + (node[i].right != -1);
    printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ",
	   node[i].id, node[i].par, node[i].sib, deg, node[i].dep, node[i].height);
    if(node[i].par == -1) printf("root\n");
    else if(node[i].left == -1 && node[i].right == -1) printf("leaf\n");
    else printf("internal node\n");
  }
  return 0;
}
