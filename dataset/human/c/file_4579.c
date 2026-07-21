#include<stdio.h>
#include<stdlib.h>
#define N_MAX 100005
#define NIL -1

void print(int t);
int get_depth(int t);
int get_height(int t);
int get_sibling(int t);
int get_degree(int t);

struct node
{
  int parent;
  int left;
  int right;
};

struct node tree[N_MAX];


int get_depth(int t)
{
  int depth=0;
  while(tree[t].parent != NIL){
    t = tree[t].parent;
    depth ++;
  }
  
  return depth;
}

int get_height(int t)
{
  int height1=0;
  int height2=0;

  if(tree[t].right != NIL){
    height1 = get_height(tree[t].right) + 1;
  }
  if(tree[t].left != NIL){
    height2 = get_height(tree[t].left) + 1;
  }

  if(height1>height2) return height1;
  else return height2;
}

int get_sibling(int t)
{
  if(tree[t].parent == NIL) return NIL;

  if(tree[tree[t].parent].left != t && tree[tree[t].parent].left != NIL){
  return tree[tree[t].parent].left;
  }

  if(tree[tree[t].parent].right != t && tree[tree[t].parent].right != NIL){
  return tree[tree[t].parent].right;
  }
  return NIL;
}

int get_degree(int t)
{
  if(tree[t].left != NIL && tree[t].right != NIL) return 2;
  if(tree[t].left == NIL && tree[t].right == NIL) return 0;
  else return 1;
}

void print(int t)
{
  printf("node %d: ",t);

  printf("parent = %d, ",tree[t].parent);

  printf("sibling = %d, ",get_sibling(t));

  printf("degree = %d, ",get_degree(t));

  printf("depth = %d, ", get_depth(t));
  
  printf("height = %d, ", get_height(t));

  if(tree[t].parent == NIL){
    printf("root\n");
  }
  else if(tree[t].left == NIL && tree[t].right == NIL){
    printf("leaf\n");
  }
  else{
    printf("internal node\n");
  }
}



int main()
{
  int n, i;
  int id,left=0, right;

  scanf("%d", &n);
  
  for(i=0; i<n; i++){
    tree[i].parent=NIL;
    tree[i].left=NIL;
    tree[i].right=NIL;
  }

  
  for(i=0; i<n; i++){
    scanf("%d", &id);
    scanf("%d%d", &left, &right);
    tree[id].left = left;
    tree[id].right = right;

    if(left != NIL) tree[left].parent = id;
    if(right != NIL) tree[right].parent = id;
  }
  
  for(i=0; i<n; i++){
    print(i);
  }
  
  return 0;
}
