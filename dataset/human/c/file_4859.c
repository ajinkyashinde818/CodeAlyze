#include <stdio.h>
#define NIL -1

typedef struct{
  int left, right, par, dep, hei;
}tree;

tree t[100000];

void depth(int id, int d)
{
  if (id == NIL)
    return;
  t[id].dep = d;
  depth(t[id].left,d+1);
  depth(t[id].right,d+1);
}

int height(int id)
{
  int h1 = 0, h2 = 0;

  if (t[id].left != NIL)
    h1 = height(t[id].left)+1;
  if (t[id].right != NIL)
    h2 = height(t[id].right)+1;
  if (h1 >= h2)
    return t[id].hei = h1;
  return t[id].hei = h2;
}

int sibling(int id)
{
  if (t[id].par == NIL)
    return NIL;
  if (t[t[id].par].left != id && t[t[id].par].left != NIL)
    return t[t[id].par].left;
  if (t[t[id].par].right != id && t[t[id].par].right != NIL)
    return t[t[id].par].right;
  return NIL;
}

int main()
{
  int n, i, id, l, r, root, deg;

  scanf("%d",&n);
  for (i = 0; i < n; i++){
    t[i].par = NIL;
    t[i].dep = t[i].hei = 0;
  }
  for (i = 0; i < n; i++){
    scanf("%d%d%d",&id,&l,&r);
    t[id].left = l;
    t[id].right = r;
    if (l != NIL)
      t[l].par = id;
    if (r != NIL)
      t[r].par = id;
  }
  for (i = 0; i < n; i++)
    if (t[i].par == NIL)
      root = i;
  depth(root,0);
  height(root);
  for (i = 0; i < n; i++){
    deg = 0;
    if (t[i].left != NIL)
      deg++;
    if (t[i].right != NIL)
      deg++;
    printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ",i,t[i].par,sibling(i),deg,t[i].dep,t[i].hei);
    if (t[i].par == NIL)
      printf("root\n");
    else if (t[i].left == NIL && t[i].right == NIL)
      printf("leaf\n");
    else
      printf("internal node\n");
  }
    
  return 0;
}
