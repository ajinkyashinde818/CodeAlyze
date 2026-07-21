#include <stdio.h>
#define N 100000

typedef struct{
  int parent;
  int left;
  int right;
} Node;

int depth(int);
void judgenode(int);
void children(int);

Node node[N];

main() {
  int i,j,id,k,n,left,child;

  scanf("%d",&n);

  for(i=0; i<n; i++) {
    node[i].parent = -1;
    node[i].left = -1;
    node[i].right = -1;
  }

  for(i=0; i<n; i++) {
    scanf("%d%d",&id,&k);
    for(j=0; j<k; j++){
      scanf("%d",&child);
      if(j == 0)
	node[id].left = child;
      else
	node[left].right = child;
      node[child].parent = id;
      left = child;
    }
  }


  for(i=0; i<n; i++) {
    printf("node %d: parent = %d, depth = %d, ",i,node[i].parent,depth(i));
    judgenode(i);
    children(i);
  }

  return 0;

}


  int depth(int i) {
    int count=0, iparent;
    iparent=i;
    while(1) {
      if(node[iparent].parent == -1)
	break;
      iparent = node[iparent].parent;
      count+=1;
    }
    return count;
  }


  void judgenode(int i) {
    if(node[i].left == -1 && node[i].parent != -1)
      printf("leaf,");
    else if(node[i].parent == -1)
      printf("root,");
    else 
      printf("internal node,");
  }


void children(int i) {
  int sibling;
  printf(" [");
  if(node[i].left != -1) {
    printf("%d",node[i].left);
    sibling = node[i].left;
    while(1) {
      if(node[sibling].right == -1)
	break;
      printf(", %d",node[sibling].right);
      sibling = node[sibling].right;
    }
  }
  printf("]\n");
}
