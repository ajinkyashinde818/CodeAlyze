#include <stdio.h>

#define N 100000
#define NIL -1

typedef struct node{
  int id;      //???????????????
  int k;       //??????????????°
  int left;    //???????????????????????????????????????
  int sibling; //left???????????????????????£????????????(??????)
  int parent;  //???
  int depth;   //??????????????±???
}Node;

int main()
{

  Node tree[N];
  int n, id, k, i, j, c, m, s, t, a;

  scanf("%d", &n);

  for(i=0; i<n; i++){
    tree[i].id = NIL;
    tree[i].left = NIL;
    tree[i].sibling = NIL;
    tree[i].parent = NIL;
    tree[i].depth = 0;
  }

  for(i=0; i<n; i++){
    scanf("%d%d", &id, &k);

    for(j=0; j<k; j++){
      scanf("%d", &c);

      if(j == 0){ 
	tree[id].left = c;
	tree[c].parent = id;
      }

      else{
	tree[m].sibling = c;
	tree[c].parent = id;
      }

      m = c;

    }
  }

  for(i=0; i<n; i++){

    s = i;

    while(1){
      t = tree[s].parent;
      if(t == NIL) break; //i??????????????????????????????????????????
      s = t;
      tree[i].depth++;
    }
 
    printf("node %d: ", i);
    printf("parent = %d, ", tree[i].parent);
    
    printf("depth = %d, ", tree[i].depth);

    if(tree[i].parent == NIL){
      printf("root, [");
      if(tree[i].left != NIL){printf("%d", tree[i].left);      
	a = tree[i].left;
	while(1){
	  if(tree[a].sibling == NIL) break;
	  a = tree[a].sibling;
	  printf(", %d", a);
	}
      }

      printf("]\n");
    }

    else if(tree[i].left == NIL){
      printf("leaf, []\n");
    }

    else if(tree[i].left != NIL){
      printf("internal node, [");
      printf("%d", tree[i].left);
	a = tree[i].left;
	while(1){
	if(tree[a].sibling == NIL) break;
	a = tree[a].sibling;
	printf(", %d", a);
      }
      printf("]\n");
    }

  }

  return 0;
}
