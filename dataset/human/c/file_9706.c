#include<stdio.h>
#include<stdlib.h>
#define NIL -1

typedef struct{
  int deg;
  int depth;
  int parent;
  int *child;
  int c_check;
}node;

node *tree;

int main(){
  int num;
  int i, j, n;

  scanf("%d", &n);
  tree = (node*)malloc(sizeof(node)*n);
  for(i=0; i<n; i++){
    tree[i].depth = 0;
    tree[i].parent = NIL;
    tree[i].child = 0;
    tree[i].c_check = 0;
  }
  
  for(i=0; i<n; i++){
    scanf("%d", &num);
    scanf("%d",&tree[num].deg);
    if(tree[num].deg != 0){
      tree[num].child = (int *)malloc(sizeof(int)*tree[num].deg);
      tree[num].c_check++;
      for(j=0; j<tree[num].deg; j++){
	scanf("%d", &tree[num].child[j]);
	tree[tree[num].child[j]].parent = num;
	tree[tree[num].child[j]].depth = tree[num].depth + 1;
      }
    }
    else if(tree[num].deg==0&&tree[num].parent!=NIL){
      tree[num].depth=tree[tree[num].parent].depth+1;
    }
  }

  for(i=0; i<n; i++){
    printf("node %d: parent = %d, depth = %d, ", i, tree[i].parent, tree[i].depth);
    if(tree[i].depth == 0) printf("root, [");
    else if(tree[i].c_check == 0) printf("leaf, [");
    else printf("internal node, [");

    for(j=0; j<tree[i].deg; j++){
      if(j != 0)printf(", ");
      printf("%d", tree[i].child[j]);
    } printf("]\n");
  }
  return 0;
}
