#include<stdio.h>
#include<stdlib.h>

struct nod{
  struct nod*parent;
  struct nod*left;
  struct nod*right;
  int node_number;
  int height_check;
};

typedef struct nod*NodePointer;

main(){
  int i,j,n,k;
  int n1,n2,n3;
  int sibling=0,degree=0,depth=0,height=0;
  int count=0;
  NodePointer roop;
  NodePointer node[27],NIL;
  int countmax=0;
  
  roop=malloc(sizeof(struct nod));
  NIL=malloc(sizeof(struct nod));
	     
	     NIL->node_number=-1;
	     NIL->left=NULL;
	     NIL->right=NULL;
	     NIL->parent=NIL;
	     NIL->height_check=0;
	     scanf("%d",&n);
  
  for(i=0;i<n;i++)
    {  
      node[i]=malloc(sizeof(struct nod));
    }
  
  for(i=0;i<n;i++)
    {
      node[i]->node_number=-1;
      node[i]->left=NULL;
      node[i]->right=NULL;
      node[i]->parent=NIL;
      node[i]->height_check=0;
    }
  
  for(i=0; i<n ;i++)
    {
      scanf("%d",&n1);
      scanf("%d",&n2);
      scanf("%d",&n3);
      
      node[n1]->node_number=n1;
      
      if(n2!=-1)
	{
	  node[n1]->left=node[n2];
	  node[n2]->parent=node[n1];
	  node[n2]->node_number=n2;
	}
      else
	node[n1]->left=NULL;
      
      if(n3!=-1)
	{
	  node[n1]->right=node[n3];
	  node[n3]->parent=node[n1];
	  node[n3]->node_number=n3;
	}
      else
	node[n1]->right=NULL;
    }


  for(i=0;i<n;i++)
    {
      if(node[i]->parent->node_number==-1)
	node[i]->height_check=1;
     
      else if( node[i]->left==NULL &&node[i]->right==NULL)
	node[i]->height_check=3;
	
      else
	node[i]->height_check=2;

    }
 
  for(i=0;i<n;i++)
    {
      printf("node %d: ",node[i]->node_number);
      printf("parent = %d, ",node[i]->parent->node_number);

      if(node[i]->parent->node_number==-1)
	printf("sibling = -1, ");	
      else if(node[i]->parent->right==node[i] && node[i]->parent->left!=NULL)
	printf("sibling = %d, ",node[i]->parent->left->node_number);
      else if(node[i]->parent->left==node[i] && node[i]->parent->right !=NULL)
	printf("sibling = %d, ",node[i]->parent->right->node_number);
      else
	printf("sibling = -1, ");
      
      
      if(node[i]->right !=NULL && node[i]->left != NULL)
	printf("degree = 2, ");
      else if(node[i]->right ==NULL && node[i]->left == NULL)
	printf("degree = 0, ");
      else
	printf("degree = 1, ");
      
      depth = 0;
     for(roop = node[i]; roop->parent->node_number != -1; roop =roop->parent)
	depth++;
      printf("depth = %d, ",depth);

      
      if(node[i]->height_check==3)
	height = 0;
      
      
      else if(node[i]->height_check == 2)
	{ 
	  height =0;
	  for(j=0;j<n;j++)
	    {
	      count=0;
	      if(node[j]->height_check==3)
		{
		  
		  for(roop = node[j]; roop->parent->node_number != -1; roop =roop->parent)
		    {
		      count++;
		      
		      if(roop->node_number==node[i]->node_number)		      
			{
			  if(count>height)
			    height=count;
			  break;
			}
		    }
		  
		  
		}
	    }
	}
      
      

      else
	{ 
	  height =0;
	  
	  for(j=0;j<n;j++)
	    {
	      count=0;
	      if(node[j]->height_check==3)
		{
		  
		  for(roop = node[j]; roop->parent->node_number != -1; roop =roop->parent)
		    {
		      count++;
		      
		      if(countmax<count)
			countmax=count;
		      
		      
		    }
		}
	    }
	  height=countmax;
	}
      

      
      
      if(node[i]->height_check==2)
	printf("height = %d, internal node",height-1);
      else if(node[i]->height_check==1)
	printf("height = %d, root",height);
      else
	printf("height = %d, leaf",height);
      

      
      
      printf("\n");
    }
  

  return 0;
}
