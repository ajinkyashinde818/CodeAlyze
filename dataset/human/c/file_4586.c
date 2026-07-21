#include <stdio.h>
#define MAX 25
#define NIL -1

typedef struct node{
  int left;
  int right;
  int p;
}Node;

Node tree[MAX];
int D[MAX];
int H[MAX];

int depth(int u , int p){
  D[u] = p;
	if (tree[u].right != NIL)
		depth(tree[u].right, p + 1);
	if (tree[u].left != NIL)
		depth(tree[u].left, p + 1);
}

int height(int u){
  int h1, h2;
  h1 = h2 = 0;
  if (tree[u].left != NIL)
    h1 = height(tree[u].left) + 1;
  if (tree[u].right != NIL)
    h2 = height(tree[u].right) + 1;
  if(h1 >= h2)return H[u] = h1;
  else return H[u] = h2;
}

int main(){
  int n;
  int i;
  int degree[MAX]={};
  int id;
  int l;
  int r;

  scanf("%d",&n);
  for(i = 0 ; i < n ; i++){
    tree[i].left = NIL;
    tree[i].right = NIL;
    tree[i].p = NIL;
  }
  //set tree
  for(i = 0 ; i < n ; i++){
    scanf("%d" , &id);
    scanf("%d" , &l);
    scanf("%d" , &r);
    degree[id] = 0;

    if(l != NIL){
      tree[id].left = l;
      tree[l].p = id;
      degree[id] += 1;
    }
    if(r != NIL){
      tree[id].right = r;
      tree[r].p = id;
      degree[id] += 1;
    }
  }

  //find root
  int root = 0;
  while (tree[root].p != NIL) {
		root = tree[root].p;
	}

  depth(root , 0);
  height(root);

  //print out
  for(i = 0 ; i < n ; i++){
    printf("node %d: parent = %d, ", i , tree[i].p);
    if(tree[i].p != NIL){
      if(tree[ tree[i].p ].left == i)printf("sibling = %d, " , tree[ tree[i].p ].right);
      else printf("sibling = %d, " , tree[ tree[i].p ].left);
    }
    else printf("sibling = -1, ");

    printf("degree = %d, depth = %d, height = %d, ",degree[i],D[i],H[i]);
    if(tree[i].p == NIL)printf("root\n");
    else if(degree[i] != 0)printf("internal node\n");
    else printf("leaf\n");
  }

  return 0;
}
