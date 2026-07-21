#include<stdio.h>

#define MAX 100000
#define NIL -1

struct Node {
  int pa,le,ri;
};

struct Node Tree[MAX];

int Depth[MAX],Height[MAX];

void setdepth(int,int);

int setheight(int);

int getsibling(int);

void print(int);

int main(){
  int h,i,nu,l,r;
  int root=0;

  scanf("%d",&h);

  for(i=0;i<h;i++)Tree[i].pa=NIL;

  for(i=0;i<h;i++){
    scanf("%d%d%d",&nu,&l,&r);
    Tree[nu].le=l;
    Tree[nu].ri=r;
    if(l!=NIL)Tree[l].pa=nu;
    if(r!=NIL)Tree[r].pa=nu;
  }

  for(i=0;i<h;i++)if(Tree[i].pa==NIL)root=i;

  setdepth(root,0);
  setheight(root);

  for(i=0;i<h;i++)print(i);

  return 0;
}

void setdepth(int x,int y){
  if(x == NIL)return;
  Depth[x]=y;
  setdepth(Tree[x].le,y+1);
  setdepth(Tree[x].ri,y+1);
}

int setheight(int x){
  int a1=0,a2=0;
  if(Tree[x].le!=NIL)a1 = setheight(Tree[x].le) + 1;
  if(Tree[x].ri!=NIL)a2 = setheight(Tree[x].ri) + 1;

  if( a1 > a2) return Height[x]=a1;
  else return Height[x]=a2;
}

  int getsibling(int x){
  if(Tree[x].pa==NIL)return NIL;
  if(Tree[Tree[x].pa].le!=x && Tree[Tree[x].pa].le!=NIL){
    return Tree[Tree[x].pa].le;
  }
  if(Tree[Tree[x].pa].ri!=x && Tree[Tree[x].pa].ri!=NIL){
    return Tree[Tree[x].pa].ri;
  }
  return NIL;
}

void print(int x){
  int deg = 0;
  printf("node %d: ",x);
  printf("parent = %d, ",Tree[x].pa);
  printf("sibling = %d, ",getsibling(x));
  if(Tree[x].le!=NIL) deg++;
  if(Tree[x].ri!=NIL) deg++;
  printf("degree = %d, ",deg);
  printf("depth = %d, ",Depth[x]);
  printf("height = %d, ",Height[x]);

  if(Tree[x].pa==NIL){
    printf("root\n");
  }
  else if(Tree[x].le==NIL && Tree[x].ri==NIL){
    printf("leaf\n");
  }
  else printf("internal node\n");
}
