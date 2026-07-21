#include <stdio.h>
#define N 25

typedef struct {
  int parent;
  int left;
  int right;
} Node;

Node Tree[N];

int getSibling(int x) {
  int sibling = -1;
  if(Tree[x].parent == -1) return -1;
  if(Tree[Tree[x].parent].left != -1 && Tree[Tree[x].parent].left != x)
     sibling = Tree[Tree[x].parent].left;
  if(Tree[Tree[x].parent].right != -1 && Tree[Tree[x].parent].right != x)
     sibling = Tree[Tree[x].parent].right;
  return sibling;
}

int getDegree(int x) {
  int degree = 0;
  if(Tree[x].left != -1) degree++;
  if(Tree[x].right != -1) degree++;
  return degree;
}

int getDepth(int x) {
  int depth = 1;
  if(Tree[x].parent == -1) return 0;
  depth += getDepth(Tree[x].parent);
  return depth;
}

int getHeight(int x) {
  int heightL = 0, heightR = 0;
  if(Tree[x].left == -1 && Tree[x].right == -1)  return 0;
  if(Tree[x].left != -1)heightL = getHeight(Tree[x].left);
  if(Tree[x].right != -1)heightR = getHeight(Tree[x].right);
  if(heightL >= heightR) return 1 + heightL;
  else return 1 + heightR;
}

int main() {
  int n, i;
  int id, sibling, degree, depth, height;

  scanf("%d", &n);
  for(i = 0; i < n; i++) {
    Tree[i].parent = -1;
    Tree[i].left = -1;
    Tree[i].right = -1;
  }
  for(i = 0; i < n; i++) {
    scanf("%d", &id);
    scanf("%d", &Tree[id].left);
    if(Tree[id].left != -1) Tree[Tree[id].left].parent = id;
    scanf("%d", &Tree[id].right);
    if(Tree[id].right != -1)Tree[Tree[id].right].parent = id;
  }

  for(i = 0; i < n; i++) {
    sibling = getSibling(i);
    degree = getDegree(i);
    depth = getDepth(i);
    height = getHeight(i);
    printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ",
            i, Tree[i].parent, sibling, degree, depth, height);
    if( Tree[i].parent == -1) printf("root\n");
    else if(Tree[i].right == -1 && Tree[i].left == -1) printf("leaf\n");
    else  printf("internal node\n");
  }

  return 0;
}
