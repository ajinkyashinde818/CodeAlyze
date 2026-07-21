#include <stdio.h>
#include <string.h>
 
#define N 25
 
typedef struct{
  int par, left, right, status, depth, sibling, degree, height;
}Node;
 
Node tree[N];
int n;
char root[N];
 
void calc_depth(int p, int d){
  tree[p].depth = d;
  if(tree[p].right != -1) calc_depth(tree[p].right, d + 1);
  if(tree[p].left != -1) calc_depth(tree[p].left, d + 1);
}
 
int calc_height(int p){
  int a = 0, b = 0;
  if(tree[p].left != -1) a = calc_height(tree[p].left) + 1;
  if(tree[p].right != -1) b = calc_height(tree[p].right) + 1;
  if(a < b) tree[p].height = b;
  else tree[p].height = a;
  return tree[p].height;
}
 
main(){
  int i, r;
  scanf("%d", &n);
  memset(root, 1, n);
  for(i=0;i<n;i++) tree[i].left = tree[i].right = tree[i].sibling = -1;
  for(i=0;i<n;i++){
    int idx, l, r;
    scanf("%d %d %d", &idx, &l, &r);
    if(l != -1){
      tree[idx].left = l;
      tree[l].par = idx;
    }
    if(r != -1){
      tree[idx].right = r;
      tree[r].par = idx;
    }
    if(l == -1 && r == -1){
      tree[idx].status = 1;
      tree[idx].degree = 0;
    }else if(l == -1 || r == -1){
      tree[idx].status = 2;
      tree[idx].degree = 1;
    }else{
      tree[idx].status = 2;
      tree[idx].degree = 2;
      tree[l].sibling = r;
      tree[r].sibling = l;
    }
    root[l] = root[r] = 0;
  }
  for(i=0;i<n;i++) if(root[i]) r = i;
  tree[r].par = -1;
  tree[r].status = 0;
  calc_depth(r, 0);
  calc_height(r);
  for(i=0;i<n;i++){
    printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ", i, tree[i].par, tree[i].sibling, tree[i].degree, tree[i].depth, tree[i].height);
    if(tree[i].status == 0) printf("root\n");
    else if(tree[i].status == 1) printf("leaf\n");
    else if(tree[i].status == 2) printf("internal node\n");
  }
  return 0;
}
