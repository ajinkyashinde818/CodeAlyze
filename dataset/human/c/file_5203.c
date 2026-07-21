#include <stdio.h>

#define MAX 25
#define NIL -1
#define max(x,y) x > y ? x : y

typedef struct{
  int parent,left,right;
}TREE;

void print(TREE tree[],int i,int depth[],int height[]);
void SetDepth(TREE tree[],int root,int depth[],int p);
int SetHeight(TREE tree[],int root,int height[]);


int main(){
  TREE tree[MAX];
  int depth[MAX],height[MAX];
  int i;
  int n,id,left,right;
  int root;

  for (i = 0;i < MAX;i++){
    tree[i].parent = NIL;
    tree[i].left = NIL;
    tree[i].right = NIL;
    depth[i] = 0;
    height[i] = 0;
  }
  
  scanf("%d",&n);

  for (i = 0;i < n;i++){
    scanf("%d %d %d",&id,&left,&right);
    
    tree[id].left = left;
    tree[id].right = right;
    tree[left].parent = id;
    tree[right].parent = id;
  }

  for (i = 0;i < n;i++){
    if (tree[i].parent == NIL){
      root = i;
      break;
    }     
  }

  SetDepth(tree,root,depth,0);
  SetHeight(tree,root,height);

  for (i = 0;i < n;i++)
    print(tree,i,depth,height);
  
  return 0;
}

void print(TREE tree[],int i,int depth[],int height[]){
  int deg = 0;

  printf("node %d: ",i);
  printf("parent = %d, ",tree[i].parent);

  if (tree[i].parent == NIL)
    printf("sibling = -1, ");
  
  else if (i == tree[tree[i].parent].left)
  printf("sibling = %d, ",tree[tree[i].parent].right);

  else
    printf("sibling = %d, ",tree[tree[i].parent].left);

  if (tree[i].left != NIL)
    deg++;
  
  if (tree[i].right != NIL)
    deg++;

  printf("degree = %d, ",deg);
  printf("depth = %d, ",depth[i]);
  printf("height = %d, ",height[i]);

  if (tree[i].parent == NIL)
    printf("root\n");

  else if (tree[i].left != NIL || tree[i].right != NIL)
    printf("internal node\n");

  else
    printf("leaf\n");
}

void SetDepth(TREE tree[],int root,int depth[],int p){
  depth[root] = p;

  if(tree[root].left != NIL)
    SetDepth(tree,tree[root].left,depth,p + 1);

  if (tree[root].right != NIL)
    SetDepth(tree,tree[root].right,depth,p + 1);
}

int SetHeight(TREE tree[],int root,int height[]){
  int h1 = 0,h2 = 0;

  if (tree[root].left != NIL)
    h1 = SetHeight(tree,tree[root].left,height) + 1;

  if (tree[root].right != NIL)
    h2 = SetHeight(tree,tree[root].right,height) + 1;
    
  return height[root] = max(h1,h2);
}
