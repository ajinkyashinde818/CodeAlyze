#include <stdio.h>
#include <string.h>

#define N 100000
typedef struct{
  int par, left_child, right_sibling, depth;
  char status[15];
}Node;

Node tree[N];
int n, nchild[N];
char root[N];

void calc_depth(int p, int d){
  tree[p].depth = d;
  if(tree[p].right_sibling != -1) calc_depth(tree[p].right_sibling, d);
  if(tree[p].left_child != -1) calc_depth(tree[p].left_child, d+1);
}

void print_node(int p, int cnt, int size){
  if(cnt + 1 == size) printf("%d", p);
  else{
    printf("%d, ", p);
    print_node(tree[p].right_sibling, cnt + 1, size);
  }
}

main(){
  int i, j, r;
  scanf("%d", &n);
  memset(root, 1, n);
  for(i=0;i<n;i++) tree[i].left_child = tree[i].right_sibling = -1;
  for(i=0;i<n;i++){
    int idx;
    scanf("%d", &idx);
    scanf("%d", &nchild[idx]);
    if(nchild[idx] == 0) strcpy(tree[idx].status, "leaf");
    else strcpy(tree[idx].status, "internal node");
    for(j=0;j<nchild[idx];j++){
      int in, pre;
      scanf("%d", &in);
      tree[in].par = idx;
      root[in] = 0;
      if(j == 0) tree[idx].left_child = in;
      else tree[pre].right_sibling = in;
      pre = in;
    }
  }
  for(i=0;i<n;i++) if(root[i]) r = i;
  tree[r].par = -1;
  strcpy(tree[r].status, "root");
  calc_depth(r, 0);
  for(i=0;i<n;i++){
    printf("node %d: parent = %d, depth = %d, %s, [", i, tree[i].par, tree[i].depth, tree[i].status);
    if(tree[i].left_child != -1) print_node(tree[i].left_child, 0, nchild[i]);
    printf("]\n");
  }
  return 0;
}
