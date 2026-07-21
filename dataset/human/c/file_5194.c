#include<stdio.h>

int depth(int);
int degree(int);
int sibling(int);
int height(int);

int n,counti=0;
int countj=0;
int count=0;

typedef struct{
  int id;
  int parent;
  int right;
  int left;
} node;

node A[100000];

int main()
{
  int i,rightchild,leftchild,id;

  scanf("%d",&n);

  for(i=0;i<n;i++)
    {
      A[i].parent=-1;
    }
  
  for(i=0;i<n;i++)
    {
      scanf("%d",&id);
      A[id].id=id;
      scanf("%d",&leftchild);
      A[id].left=leftchild;
      A[leftchild].parent=id;
      scanf("%d",&rightchild);
      A[id].right=rightchild;
      A[rightchild].parent=id;
    }

  for(i=0;i<n;i++)
    {
      count=0;
      countj=0;
      counti=0;
      printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ",i,A[i].parent,sibling(i),degree(i),depth(i),height(i));
      if(A[i].parent==-1) printf("root\n");
      else if((A[i].left==-1)&&(A[i].right==-1)) printf("leaf\n");
      else printf("internal node\n");
    }

  return 0;
}

int depth(int m)
{
  int l;
  l=A[m].parent;
  if(l==-1) return count;
  count++;
  depth(l);
}

int height(int m)
{
  int j=0,i=0;
  if(A[m].left!=-1)
    {
      i=height(A[m].left)+1;
    }
  if(A[m].right!=-1)
    {
      j=height(A[m].right)+1;
    }
  if(i>j) return i;
  else return j;
}

int sibling(int m)
{
  int i;
  for(i=0;i<n;i++)
    {
      if((A[i].id!=m)&&(A[m].parent==A[i].parent)) return A[i].id;
    }
  return -1;
}

int degree(int m)
{
  int i=0;
  if(A[m].left!=-1) i++;
  if(A[m].right!=-1) i++;
  return i;
}
