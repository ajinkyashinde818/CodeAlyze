#include<stdio.h>

#define MAX 10000
#define NIL -1

struct Node{
  int p, l, r;
};

struct Node Tree[MAX];
int Depth[MAX], Height[MAX];

void setDepth(int, int);
int setHeight(int);
int Sibling(int);
void Print(int);

int main(){
  int n,i,num,le,ri;
  int root = 0;

  scanf("%d",&n);

  for(i = 0 ; i < n ; i++) Tree[i].p = NIL;

  for(i = 0 ; i < n ; i++){
    scanf("%d%d%d",&num,&le,&ri);
    Tree[num].l = le;
    Tree[num].r = ri;
    if(le != NIL) Tree[le].p = num;
    if(ri != NIL) Tree[ri].p = num;
  }

  for(i = 0 ; i < n ; i++) if(Tree[i].p == NIL) root = i;

  setDepth(root,0);
  setHeight(root);

  for(i = 0 ; i < n ; i++) Print(i);

  return 0;
}

void setDepth(int x, int y){
  if(x == NIL) return;
  Depth[x] = y;
  setDepth(Tree[x].l, y+1);
  setDepth(Tree[x].r, y+1);
}

int setHeight(int x){
  int h1 = 0, h2 = 0;
  if(Tree[x].l != NIL) h1 = setHeight(Tree[x].l) + 1;
  if(Tree[x].r != NIL) h2 = setHeight(Tree[x].r) + 1;

  if(h1 > h2) return Height[x] = h1;
  else return Height[x] = h2;
}

int Sibling(int x){
  if(Tree[x].p == NIL) return NIL;
  if(Tree[Tree[x].p].l != x && Tree[Tree[x].p].l != NIL){
    return Tree[Tree[x].p].l;
  }
  if(Tree[Tree[x].p].r != x && Tree[Tree[x].p].r != NIL){
    return Tree[Tree[x].p].r;
  }

  return NIL;
}

void Print(int x){
  int degree = 0;
  printf("node %d: ",x);
  printf("parent = %d, ",Tree[x].p);
  printf("sibling = %d, ",Sibling(x));
  if(Tree[x].l != NIL) degree++;
  if(Tree[x].r != NIL) degree++;
  printf("degree = %d, ",degree);
  printf("depth = %d, ",Depth[x]);
  printf("height = %d, ",Height[x]);

  if(Tree[x].p == NIL){
    printf("root\n");
  }
  else if(Tree[x].l == NIL && Tree[x].r == NIL){
    printf("leaf\n");
  }
  else printf("internal node\n");
}
