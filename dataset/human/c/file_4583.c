#include <stdio.h>
#include <stdlib.h>

int Sibling(int);
int degree(int);
int Depth(int);
int height(int);

typedef struct{
  int parent;
  int left;
  int right;
}tree;

tree *TREE;

int N;

#define fr -1

int main(){
  int id,i,j,de,depth;

  scanf("%d",&N);
  TREE = (tree *)malloc(sizeof(tree)*N);

  for(i=0;i<N;i++){
    TREE[i].parent = fr;
    TREE[i].left = fr;
    TREE[i].right = fr;
  }

for(i=0;i<N;i++){
  scanf("%d",&id);
  scanf("%d",&TREE[id].left);
  scanf("%d",&TREE[id].right);

if(TREE[id].left != -1){
  TREE[TREE[id].left].parent = id;
}
if(TREE[id].right != -1){
  TREE[TREE[id].right].parent = id;
}
}

for(i=0;i<N;i++){
//if(TREE[i].parent == -1){
//printf("node %d: parent = -1",i);
//}

//else{
  printf("node %d: parent = %d, ",i,TREE[i].parent);
//}


printf("sibling = %d, ",Sibling(i));
de = degree(i);
printf("degree = %d, ",de);

printf("depth = %d, ",Depth(i));
depth = Depth(i);

printf("height = %d, ",height(i));

if(TREE[i].parent == -1){
  printf("root\n");
}
else if(TREE[i].left == fr && TREE[i].right == fr){
  printf("leaf\n");
}
else printf("internal node\n");

}

return 0;
}

//Sibling Function!<f>
int Sibling(int id){
  int i;
  for(i=0;i<N;i++){
    if(TREE[id].parent == TREE[i].parent && id != i){
      return i;
    }
  }
  return -1;
}

//degree Function!<f>
int degree(int id){
  int i;
if(TREE[id].left != -1 && TREE[id].right != -1){
  return 2;
}
  else if(TREE[id].left != -1 || TREE[id].right != -1){
    return 1;
  }
  else return 0;
}

//depth Function!<f>
int Depth(int id){
  int i = TREE[id].parent;
  int depth = 0;
  while(i!=fr){
    i = TREE[i].parent;
    depth++;
  }
return depth;
}

//height Function
int height(int id){
  int lheight=0,rheight=0;
  if(TREE[id].left != fr){
    lheight = height(TREE[id].left) + 1;
  }
  if(TREE[id].right != fr){
  rheight = height(TREE[id].right) + 1;
}
if(lheight > rheight){
  return lheight;
}
else{
  return rheight;
}
}
