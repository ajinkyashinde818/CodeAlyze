#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int name;
  int parent;
  int child;
  int brother;
} node_t;

node_t tree[100003];

int main()
{
  int n,i,child_number,j,child,depth,parent,heap;

  scanf("%d",&n);

  for(i = 0;i < n;i++){
    tree[i].name = -1;
    tree[i].parent = -1;
    tree[i].child = -1;
    tree[i].brother = -1;
  }

  for(i = 0;i < n;i++){
    scanf("%d",&heap);
    tree[heap].name = heap;
    scanf("%d",&child_number);
   /* ある変数に一個上の兄の情報を更新する  */
   /* 一個上の兄の変数 */
    for(j = 0;j < child_number;j++){
      if(j == 0){
	scanf("%d",&tree[heap].child);
	tree[tree[heap].child].parent = tree[heap].name; /* 親情報を入力 */
	child = tree[heap].child; /* 一個上の兄を更新 */
      }
      else{
	scanf("%d",&tree[child].brother);
	tree[tree[child].brother].parent = tree[heap].name; /* 親情報を入力 */
	child = tree[child].brother; /* 一個上の兄を更新 */
      }
    }
  }

  /* 出力 */
  for(i = 0;i < n;i++){
    depth = 0;
    parent = tree[i].parent;
    while(parent != -1){
      depth++;
      parent = tree[parent].parent;
    }
    printf("node %d: parent = %d, depth = %d, ",tree[i].name,tree[i].parent,depth);
    if(tree[i].parent == -1) printf("root, ");
    else if(tree[i].child == -1) printf("leaf, ");
    else printf("internal node, ");
    printf("[");
    child = tree[i].child;
    while(child != -1){
      printf("%d",child);
      child = tree[child].brother;
      if(child != -1) printf(", ");
    }
    printf("]\n");
  }

  return 0;
}
