#include <stdio.h>
#include <stdlib.h>

typedef struct{
  int parent;
  int left;  //左の子
  int right; //右の子
}Node;

int getDepth(Node**, int);
int getHeight(Node**, int);
int getSibling(Node**, int);
int getDegree(Node**, int);

main(){
  int n, i, id, depth, height, sibling, degree;
  Node **tree;

  scanf("%d", &n);
  tree = (Node**)malloc(sizeof(Node*)*n);
  for(i=0; i<n; i++){
    tree[i] = (Node*)malloc(sizeof(Node));
    tree[i]->parent = -1;
  }

  for(i=0; i<n; i++){
    scanf("%d", &id);
    scanf("%d%d", &tree[id]->left, &tree[id]->right);
    if(tree[id]->left != -1){
      tree[tree[id]->left]->parent = id;
    }
    if(tree[id]->right != -1){
      tree[tree[id]->right]->parent = id;
    }
  }

  for(i=0; i<n; i++){
    depth = getDepth(tree, i);
    height = getHeight(tree, i);
    sibling = getSibling(tree, i);
    degree = getDegree(tree, i);
    printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ",i, tree[i]->parent, sibling, degree, depth, height);
    
    if(depth == 0) printf("root\n");
    else if(degree == 0) printf("leaf\n");
    else printf("internal node\n");

    }

  return 0;
}

int getDepth(Node **nodes, int p){
  if(nodes[p]->parent == -1) return 0;
  else{
    return 1 + getDepth(nodes, nodes[p]->parent);
  }
}

int getHeight(Node **nodes, int p){
  int right=0, left=0;

  if(nodes[p]->left != -1){
    left = 1 + getHeight(nodes, nodes[p]->left);
  }
  if(nodes[p]->right != -1){
    right = 1 + getHeight(nodes, nodes[p]->right);
  }

  return ((right >= left) ? right : left);
}

int getSibling(Node **nodes, int p){
  int parent = nodes[p]->parent;

  if (parent == -1) return -1;
  else if(nodes[parent]->left != p) return nodes[parent]->left;
  else return nodes[parent]->right;
}

int getDegree(Node **nodes, int p){
  int res = 0;
  
  if(nodes[p]->right != -1) res++;
  if(nodes[p]->left != -1) res++;

  return res;
}
