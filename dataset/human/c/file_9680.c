#include <stdio.h>
#define N 100001

typedef struct{
  int parent;
  int left;
  int right;
} node;

node tree[N];

int depth(int);

int main(){

  int n,id,cnum,lef,child;
  int i,j; 

  scanf("%d",&n);

  for(i=0;i<n;i++){
    tree[i].parent = -1;
    tree[i].left = -1;
    tree[i].right = -1;
  }
  for(i = 0;i < n;i++){
    scanf("%d %d", &id, &cnum);
    for(j = 0;j < cnum;j++){
      scanf("%d", &child);
      if(j == 0) tree[id].left = child;
      else tree[lef].right = child;
      tree[child].parent = id;
      lef = child;
    }
  }
  for(i = 0;i < n;i++){ 
    printf("node %d: parent = %d, depth = %d, ", i, tree[i].parent, depth(i));

    if(tree[i].parent == -1) printf("root, [");
    else if(tree[i].left == -1) printf("leaf, [");
    else printf("internal node, [");

    lef = tree[i].left;

    j = 0;
    while(1){
      if(lef == -1) break;
      if(j != 0) printf(", ");
      printf("%d",lef);
      lef = tree[lef].right;
      j++;
    }
    printf("]\n");
  }
  return 0;
}
 
int depth(int n){
  if(tree[n].parent == -1) return 0;
  return depth(tree[n].parent)+1;
}
