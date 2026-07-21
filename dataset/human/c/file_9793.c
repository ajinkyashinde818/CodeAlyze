#include<stdio.h>

int depth(int);
int n,count=0;
typedef struct{
  int k;
  int parent;
  int right;
  int left;
} node;

node A[100000];

int main()
{
  int i,j,k,x,c,l,child,id;

  scanf("%d",&n);

  for(i=0;i<n;i++)
    {
            A[i].parent=-1;
      A[i].right=-1;
      A[i].left=-1;
    }
  
  for(i=0;i<n;i++)
    {
      scanf("%d",&id);
      scanf("%d",&A[id].k);
      for(j=0;j<A[id].k;j++)
	{
	  scanf("%d",&child);
	  if(j==0)
	    {
	      A[id].left=child;
	      A[child].parent=id;
	      c=child;
	    }

	  else
	    {
	      A[c].right=child;
	      A[child].parent=id;
	      c=child;
	    }
	}
    }

  for(i=0;i<n;i++)
    {
      count=0;
      printf("node %d: parent = %d, depth = %d, ",i,A[i].parent,depth(i));
      if(A[i].parent==-1) printf("root, [");
      else if(A[i].left==-1) printf("leaf, [");
      else if(A[i].left!=-1) printf("internal node, [");

      if(A[i].left!=-1)
	{
	  printf("%d",A[i].left);
	  l=A[i].left;
	
	  for(j=0;j<A[i].k-1;j++)
	    {	    
	      printf(", %d",A[l].right);

	      l=A[l].right;
	    }
	}
      printf("]\n");
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
