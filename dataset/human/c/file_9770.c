#include<stdio.h>
#include<stdlib.h>
#define N 100001
#define B -1
typedef struct {
  int  parent;
  int  left;
  int  right;
}BINARY;
  
BINARY A[N];
 
int depth(int);
int degree(int);
 
main(){
  int i,j,ch,sugiyama,id,de,l;
  scanf("%d", &sugiyama);
  for(i=0; i<sugiyama; i++)
    {
      A[i].parent = B;
      A[i].left = B;
      A[i].right = B;
    }
  //ここから
  for(i=0; i<sugiyama;i++)
    {
      scanf("%d%d",&id, &de);
      for(j = 0; j < de; j++)
	{
	  scanf("%d", &ch);
	  A[ch].parent = id;
	  if(j == 0)
	    {
	      A[id].left = ch;
	    }
	  else
	    {
	      A[l].right = ch;
	    }
	  l = ch;
	  
	}
    }
  
  for(i = 0; i < sugiyama; i++){
    printf("node %d: parent = %d, depth = %d, ", i, A[i].parent, depth(i));
    if(A[i].parent == B)
      {
	printf("root, [");
      }
    else if(A[i].left == B)
      {
	printf("leaf, [");
      }
    else
      {
	printf("internal node, [");
      }
    degree(A[i].left);
    printf("]\n");
  }
  return 0;
}

int depth(int d){
  int deep = 0;
  if(A[d].parent == B)
    {
      return 0;
    }
  else 
    {
      deep = depth(A[d].parent) + 1;
      return deep;
    }
}

int degree(int e){
  if(e == B)
    {
      return 0;
    }
  else 
    {
    if(A[e].right == B){
      printf("%d",e); 
    }
    else
      {
	printf("%d, ",e);
	degree(A[e].right);
      }
    }
}
