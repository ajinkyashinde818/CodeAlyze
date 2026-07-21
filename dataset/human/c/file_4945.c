//Binary Trees

#include<stdio.h>
#define N 10000
#define NILL -1

struct Node
{
  int parent,left,right;
};

struct Node tree[N];
int n,de[N],he[N];

void dep(int u,int d)
{
  if(u == NILL) return;

  de[u] = d;

  dep(tree[u].left, d + 1);
  dep(tree[u].right, d + 1);

}

int hei(int u)
{
  int h1 = 0, h2 = 0;

  if(tree[u].left != NILL) h1 = hei(tree[u].left)+1;
  if(tree[u].right != NILL) h2 = hei(tree[u].right)+1;

  if(h1 >= h2) return he[u] = h1;
  if(h2 > h1)return he[u] = h2;
}

int sibling(int u)
{
  if(tree[u].parent == NILL) return NILL;
  if(tree[tree[u].parent].left != u && tree[tree[u].parent].left != NILL)
    {
      return tree[tree[u].parent].left;
    }
  if(tree[tree[u].parent].right != u && tree[tree[u].parent].right != NILL)
    {
      return tree[tree[u].parent].right;
    }
  return NILL; 
}

void worktime(int u)
{
  int degree = 0;
  printf("node %d: ",u);
  printf("parent = %d, ",tree[u].parent);
  printf("sibling = %d, ",sibling(u));

  if(tree[u].left != NILL) degree++;
  if(tree[u].right != NILL) degree++;

  printf("degree = %d, ",degree);
  printf("depth = %d, ",de[u]);
  printf("height = %d, ",he[u]);

  if(tree[u].parent == NILL)
    {
      printf("root\n");
    }
  else if(tree[u].left == NILL && tree[u].right == NILL)
    {
      printf("leaf\n");
    }
  else{
    printf("internal node\n");
  }
  
}

int main()
{
  int a,b,c,i, root = 0;
  scanf("%d",&n);

  for(i = 0; i < n; i++)
    {
      tree[i].parent = NILL;
    }

  for(i = 0; i < n; i++)
    {
      scanf("%d %d %d",&a,&b,&c);
      tree[a].left = b;
      tree[a].right = c;
      if(b != NILL) tree[b].parent = a;
      if(c != NILL) tree[c].parent = a;
    }

  for(i = 0; i < n; i++)
    {
      if(tree[i].parent == NILL) root = i;
    }

  dep(root,0);
  hei(root);

  for(i = 0; i < n; i++) worktime(i);
    
  return 0;
}
