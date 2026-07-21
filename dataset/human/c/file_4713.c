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
  int left,right,num,n,i;
  int root = 0;

  scanf("%d",&n);

  for(i = 0 ; i < n ; i++) Tree[i].p = NIL;

  for(i = 0 ; i < n ; i++){
    scanf("%d%d%d",&num,&left,&right);
    Tree[num].l = left;
    Tree[num].r = right;
    if(left != NIL) Tree[left].p = num;
    if(right != NIL) Tree[right].p = num;
  }
 for(i = 0 ; i < n ; i++) if(Tree[i].p == NIL) root = i;

  setDepth(root,0);
  setHeight(root);

  for(i = 0 ; i < n ; i++) Print(i);

  return 0;
}

void setDepth(int a, int b){
  if(a == NIL) return;
  Depth[a] =b;
  setDepth(Tree[a].l,b+1);
  setDepth(Tree[a].r,b+1);
}

int setHeight(int a){
  int h1 = 0, h2 = 0;
  if(Tree[a].l != NIL) h1 = setHeight(Tree[a].l) + 1;
  if(Tree[a].r!= NIL) h2 = setHeight(Tree[a].r) + 1;

  if(h1 > h2) return Height[a] = h1;
  else return Height[a] = h2;
  
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
  int deg = 0;
  printf("node %d: ",x);
  printf("parent = %d, ",Tree[x].p);
  printf("sibling = %d, ",Sibling(x));
  if(Tree[x].l != NIL) deg++;
  if(Tree[x].r != NIL) deg++;
  printf("degree = %d, depth = %d, height = %d, ",deg,Depth[x],Height[x]);
 
  if(Tree[x].p==NIL){
    printf("root\n");
  }
  else if(Tree[x].l == NIL && Tree[x].r == NIL){
    printf("leaf\n");
  }
  else printf("internal node\n");
}
