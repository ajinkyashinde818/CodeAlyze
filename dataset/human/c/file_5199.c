#include<stdio.h>
#define MAX 10000
#define NIL -1

typedef struct{
  int parent;
  int left;
  int right;
}Node;

Node tree[MAX];
int depth[MAX],height[MAX];

void setDepth(int,int);
int setHeight(int);
int Sibling(int);
void Print(int);

int main(){
  int n,i,num,l,r;
  int root = 0;

  scanf("%d",&n);

  for(i = 0; i < n; i++){
    tree[i].parent = NIL;
  }
  for(i = 0; i < n ;i++){
    scanf("%d%d%d",&num,&l,&r);
    tree[num].left = l;
    tree[num].right = r;
    if(l != NIL) tree[l].parent = num;
    if(r != NIL) tree[r].parent = num;
  }
  for(i = 0; i < n; i++){
    if(tree[i].parent == NIL)root = i;
  }

  setDepth(root,0);
  setHeight(root);

  for(i = 0; i < n ;i++)Print(i);

  return 0;
}

int Sibling(int x){
  if(tree[x].parent == NIL) return NIL;
  if(tree[tree[x].parent].left != x && tree[tree[x].parent].left != NIL)return tree[tree[x].parent].left;
  if(tree[tree[x].parent].right != x && tree[tree[x].parent].right != NIL)return tree[tree[x].parent].right;

  return NIL;
}
void setDepth(int x,int y){
  if(x == NIL) return;
   depth[x] = y;
   setDepth(tree[x].left, y+1);
   setDepth(tree[x].right, y+1);
}

int setHeight(int x){
  int h1 = 0, h2 = 0;
  if(tree[x].left != NIL) h1 = setHeight(tree[x].left) + 1;
  if(tree[x].right != NIL) h2 = setHeight(tree[x].right) + 1;
  if(h1 > h2) return height[x] = h1;
  else return height[x] = h2;
}

void Print(int x){
  int degree = 0;
  printf("node %d: ",x);
  printf("parent = %d, ",tree[x].parent);
  printf("sibling = %d, ",Sibling(x));
  if(tree[x].left != NIL) degree++;
  if(tree[x].right != NIL) degree++;
  printf("degree = %d, ",degree);
  printf("depth = %d, ",depth[x]);
  printf("height = %d, ",height[x]);

  if(tree[x].parent == NIL){
  printf("root\n");
  }
  else if(tree[x].left == NIL && tree[x].right == NIL){
  printf("leaf\n");
  }
  else printf("internal node\n");
}
