#include<stdio.h>

typedef struct{
  int parent;
  int sibling;
  int child;
}Tree;

int main()
{
  int i, j, n, id,  x, temp, kids, depth, d;

  
  scanf("%d", &n);
  
  Tree T[n];

  for( i=0; i<n; i++ )
    {
      T[i].parent = -1;
    }
  
  for( i=0; i<n; i++ )
    {
      scanf("%d%d", &id, &x);
      
      if( x != 0 )
	{
	  scanf("%d", &T[id].child);

	  kids = T[id].child;
	  
	  for( j=0; j<x; j++ )
	    {
	      if( j == x-1 ) T[kids].sibling = -1;
	      else scanf("%d", &T[kids].sibling);
	      
	      T[kids].parent = id; 
	   
	      kids = T[kids].sibling;
	    }
	}

      else T[id].child = -1;
    }


  for( i=0; i<n; i++ )
    {
      printf("node %d: ", i);
      printf("parent = %d, ", T[i].parent);
      
      depth = 0;
      d = i;
      while(1)
	{
	  if( T[d].parent == -1 ) break;
	  depth++;
	  d = T[d].parent;
	}
	   
      printf("depth = %d, ", depth);
      
      if( T[i].parent == -1 )
	{
	  if( T[i].child == -1 ) printf("root, []\n");
	  
	  else
	    {
	      printf("root, [%d", T[i].child);
	      temp = T[i].child;
	      
	      while(1)
		{
		  if( T[temp].sibling == -1 )
		    {
		      printf("]\n");
		      break;
		    }
		  printf(", %d", T[temp].sibling);
		  temp = T[temp].sibling;
		  
		}
	    }
	}
      
      else if( T[i].child == -1 ) printf("leaf, []\n");
      
      else
	{
	  printf("internal node, [");
	  temp = T[i].child;
	  
	  while(1)
	    {
	      if( T[temp].sibling == -1 )
		{
		  printf("%d]\n", temp);
		  break;
		}
	      else
		{
		  printf("%d, ", temp);
		  temp = T[temp].sibling;
		}
	      
	    }
	}
    } 

  return 0;
}
