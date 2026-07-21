#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#define N 200001

typedef struct _n {
  int deg;
  int right;
  int left;
  int r;
  int parent;
  int sib;
  int depth;
  int height;
} node;

node tree[100000];
int n;
void setDepth(int);
int setHeight(int);
int main() {
  int i;
  int  j, k, l, r;

  scanf("%d", &n);
  for(i = 0; i < n; i++) {
    tree[i].parent = -1;
    tree[i].sib = -1;
    tree[i].depth = 0;
    tree[i].height = 0;
    tree[i].deg = 0;
  }

  for(k = 0; k < n; k++) {
    scanf("%d", &i);
    scanf("%d %d", &tree[i].left, &tree[i].right);
    if(tree[i].left != -1) tree[tree[i].left].sib = tree[i].right;
    if(tree[i].right != -1) tree[tree[i].right].sib = tree[i].left;
    if(tree[i].left != -1)tree[tree[i].left].parent = i;
    if(tree[i].right != -1) tree[tree[i].right].parent = i;
    if(tree[i].left != -1) tree[i].deg++;
    if(tree[i].right != -1) tree[i].deg++;
  }

  for(i = 0; i < n; i++) {
    if(tree[i].parent == -1) {k = i;}
  }
  setDepth(k);
  setHeight(k);

  for(i = 0; i < n; i++) {
    printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ",
	   i, tree[i].parent, tree[i].sib, tree[i].deg, tree[i].depth, tree[i].height);
    if(tree[i].parent == -1) {printf("root\n");}
    else if(tree[i].deg == 0) {  printf("leaf\n");}
    else {  printf("internal node\n");}
  }
  return 0;
}

void setDepth(int r) {
  if(tree[r].right != -1 )tree[tree[r].right].depth += 1 + tree[r].depth;
  if(tree[r].left != -1) tree[tree[r].left].depth += 1 + tree[r].depth;
  if(tree[r].left != -1) setDepth(tree[r].left);
  if(tree[r].right != -1) setDepth(tree[r].right);
}

int setHeight(int r) {
  int i, h, x, y, n;
  h=0;
  if(tree[r].deg == 0) {
    tree[r].height = 0;
    return 0;
  }
  if(tree[r].left != -1) {x = setHeight(tree[r].left);}
  else {x = 0;}
  if(tree[r].right != -1) {y = setHeight(tree[r].right);}
  else {y = 0;}
  h = (x < y)? y: x;
  h++;
  tree[r].height = h;
  return h;
}
