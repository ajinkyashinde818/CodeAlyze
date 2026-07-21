#include<stdio.h>

#define MAX 10000
#define NIL -1

struct Node{
  int parent, left, right;
};

struct Node Tree[MAX];
int Depth[MAX], Height[MAX];

void setDepth(int, int);
int setHeight(int);
int Sibling(int);
void Print(int);

int main(){
  int n,i,num,l,r;
  int root = 0;

  scanf("%d",&n);

  for(i = 0 ; i < n ; i++) Tree[i].parent = NIL;

  for(i = 0 ; i < n ; i++){
    scanf("%d%d%d",&num,&l,&r);
    Tree[num].left = l;
    Tree[num].right = r;
    if(l != NIL) Tree[l].parent = num;
    if(r != NIL) Tree[r].parent = num;
  }

  for(i = 0 ; i < n ; i++) if(Tree[i].parent == NIL) root = i;

  setDepth(root,0);
  setHeight(root);

  for(i = 0 ; i < n ; i++) Print(i);

  return 0;
}

void setDepth(int x, int y){
  if(x == NIL) return;
  Depth[x] = y;
  setDepth(Tree[x].left, y+1);
  setDepth(Tree[x].right, y+1);
}

int setHeight(int x){
  int h1 = 0, h2 = 0;
  if(Tree[x].left != NIL) h1 = setHeight(Tree[x].left) + 1;
  if(Tree[x].right != NIL) h2 = setHeight(Tree[x].right) + 1;

  if(h1 > h2) return Height[x] = h1;
  else return Height[x] = h2;
}

int Sibling(int x){
  if(Tree[x].parent == NIL) return NIL;
  if(Tree[Tree[x].parent].left != x && Tree[Tree[x].parent].left != NIL){
    return Tree[Tree[x].parent].left;
  }
  if(Tree[Tree[x].parent].right != x && Tree[Tree[x].parent].right != NIL){
    return Tree[Tree[x].parent].right;
  }

  return NIL;
}

void Print(int x){
  int degree = 0;
  printf("node %d: ",x);
  printf("parent = %d, ",Tree[x].parent);
  printf("sibling = %d, ",Sibling(x));
  if(Tree[x].left != NIL) degree++;
  if(Tree[x].right != NIL) degree++;
  printf("degree = %d, ",degree);
  printf("depth = %d, ",Depth[x]);
  printf("height = %d, ",Height[x]);

  if(Tree[x].parent == NIL){
    printf("root\n");
  }
  else if(Tree[x].left == NIL && Tree[x].right == NIL){
    printf("leaf\n");
  }
  else printf("internal node\n");
}
