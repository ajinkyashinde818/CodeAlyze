#include<stdio.h>
#define NILL -1

typedef struct
{
  int parent;
  int r; //right sibling
  int l; //left  sibling
} TREE;

int sibling(int);
int degree(int);
int depth(int,int);
int height(int);

int n;
int h[30];
TREE t[30];

int main()
{
  int i;
  int n;
  scanf("%d",&n);
  //TREE &point = t;
  
  for(i=0;i < n;i++) t[i].parent = NILL;

  int v;
  for(i=0;i < n;i++){
    scanf("%d",&v);
    scanf("%d%d",&t[v].l,&t[v].r);
    if(t[v].l != NILL) t[t[v].l].parent = v;
    if(t[v].r != NILL) t[t[v].r].parent = v;
  }
  
  for(i=0;i < n;i++){
    printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ",
	   i,t[i].parent,sibling(i),degree(i),depth(i,0),height(i));
    if(t[i].parent == NILL) printf("root\n");
    else if(t[i].l == NILL && t[i].r == NILL) printf("leaf\n");
    else printf("internal node\n");
  }
  return 0;
}

int sibling(int i)
{
  if(t[i].parent == NILL) return NILL;//root
  if(t[t[i].parent].r != i && t[t[i].parent].r != NILL) return t[t[i].parent].r;
  if(t[t[i].parent].l != i && t[t[i].parent].l != NILL) return t[t[i].parent].l;
  return -1;
}

int degree(int i)
{
  int cnt=0;
  if(t[i].l != NILL) cnt++;
  if(t[i].r != NILL) cnt++;
  return cnt;
}

int depth(int i, int di)
{
  di = 0;
  while(t[i].parent != NILL){
    i = t[i].parent;
    di++;
  }
  return di;
}

int height(int i)
{
  int h1=0,h2=0;
  if(t[i].r != NILL) h1 = height(t[i].r)+1;
  if(t[i].l != NILL) h2 = height(t[i].l)+1;

  if(h1 > h2) h[i] = h1;
  else h[i] = h2;
  return h[i];
}
