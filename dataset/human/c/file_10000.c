#include <stdio.h>
#define max 100000
#define nil -1

typedef struct{
  int parent;
  int leaf;
  int right;
}node;

node t[max];
int n;

int dep(int id, int c){
  int i, depth = 0;
  if(t[id].parent != nil){
    depth = dep(t[id].parent, c);
    return depth+1;
  }
  else return 0;
}

int main(void){
  int i, j, id, k, c, sibling;
  scanf("%d", &n);

  //init
  for(i = 0; i < n; i++)
    t[i].parent = t[i].leaf = t[i].right = nil;

  //maketree
  for(i = 0; i < n; i++){
    scanf("%d%d", &id, &k);
    for(j = 0; j < k; j++){
      //for first time
      scanf("%d", &c); //1つの子ノードのid
      if(j == 0){
        t[c].parent = id; //親ノードのidを設定
        t[id].leaf = c; //自分の子を設定
        sibling = c; //次に作る子の兄弟はc
      } else {
        t[sibling].right = c; //前の子の次はc

        t[c].parent = id;
        sibling = c;
      }
    }
  }

  //printtree
  for(i = 0; i < n; i++){
    printf("node %d: ", i);
    printf("parent = %d, ", t[i].parent);
    printf("depth = %d, ", dep(i, 0));

    if(t[i].parent == nil)
      printf("root, [");

    else if(t[i].leaf != nil)
      printf("internal node, [");
    else{
      printf("leaf, []\n");
      continue;
    }
    if(t[i].leaf != nil){
      printf("%d", t[i].leaf);
      c = t[i].leaf;
    }
    else c = i;
    while(t[c].right != nil){
        printf(", %d", t[c].right);
        c = t[c].right;
    }
    printf("]\n");
  }

  return 0;
}
