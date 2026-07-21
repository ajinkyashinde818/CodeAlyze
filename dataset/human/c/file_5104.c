#include<stdio.h>
#define MAX 1000
 
typedef struct
{
  int p;
  int l;
  int r;
}Binary;
 
Binary tree[MAX];
 
int main()
{
  int i, n, k;
  int id;
 
  scanf("%d", &n);
  for(i = 0; i < n; i++)
    tree[i].l = tree[i].r = tree[i].p = -1;
  
  for(i = 0; i < n; i++)
    {
      scanf("%d", &id);
      scanf("%d%d", &tree[id].l, &tree[id].r);
      if(tree[id].l != -1) tree[tree[id].l].p = id;
      if(tree[id].r != -1) tree[tree[id].r].p = id;
    }
 
  for(i = 0; i < n; i++)
    print( i );
  return 0;
}
 
 
void print(int);
 
int getheight(int i){
  int x=0,y=0;
  if(tree[i].l!=-1)
    x=getheight(tree[i].l)+1;
  if(tree[i].r!=-1)
    y=getheight(tree[i].r)+1;
  if(x>y)
    return x;
  else
    return y;
}
 
int getdepth(int i){
  int d=0;
  while(tree[i].p>=0){
    i=tree[i].p;
    d++;
  }
  return d;
}
 
int getsibling(int i){
  if(tree[i].p==-1)
    return -1;
  else if(tree[tree[i].p].r==i)
    return tree[tree[i].p].l;
  else
    return tree[tree[i].p].r;
}
 
int getdeg(int i){
  int d=0;
  if(tree[i].l!=-1)
    d++;
  if(tree[i].r!=-1)
    d++;
  return d;
}
 
 
void print(int i){
    int h=getheight(i);
    int dep=getdepth(i);
 
    printf("node %d: parent = %d, sibling = %d, degree = %d, ",i,tree[i].p,getsibling(i\
),getdeg(i));
 
    printf("depth = %d, height = %d, ",dep,h);
    if(dep==0)
      printf("root\n");
    else if(h==0)
      printf("leaf\n");
    else
      printf("internal node\n");
}
