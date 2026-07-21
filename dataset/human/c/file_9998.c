#include <stdio.h>
#define N 100001

typedef struct{

  int par; //parent node
  int l_child; //left child node
  int r_sib; //right child noed
 
} node;

node tree[N];

int depth(int);

int main(){
 
  int n,id,cnum,lef,child;
  int i,j; 

  scanf("%d",&n);
  
  for(i=0;i<n;i++){

    tree[i].par = -1;
    tree[i].l_child = -1;
    tree[i].r_sib = -1;

  }
  
  for(i=0; i<n; i++){

    scanf("%d %d", &id, &cnum);

    for(j=0; j<cnum; j++){

      scanf("%d", &child);

      if(j == 0) tree[id].l_child = child;

      else tree[lef].r_sib = child;
      tree[child].par = id;
      lef = child;

    }
  }

  for(i=0; i<n; i++){ //how the tree looks 

    printf("node %d: parent = %d, depth = %d, ", i, tree[i].par, depth(i));

    if(tree[i].par == -1) printf("root, [");

    else if(tree[i].l_child == -1) printf("leaf, [");

    else printf("internal node, [");

    lef = tree[i].l_child;

    for(j=0; ; j++){

      if(lef == -1) break; //no leaf break needed

      if(j != 0) printf(", ");

      printf("%d",lef);

      lef = tree[lef].r_sib;

    }

    printf("]\n");
  }
  
  return 0;
  
}

int depth(n){

  if(tree[n].par == -1) return 0;

  return depth(tree[n].par)+1;
}
