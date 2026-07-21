#include <stdio.h>

#define MAX 25

typedef struct {
  int P;
  int L;
  int R;
}tree;

tree T[MAX];
int N;

int height(int);

int max(int,int);

int main()
{
  int n,i,j,id,k,kodomo,irekae,depth,degree,hei;

  scanf("%d",&n);



  /*入力編*/

  for(i=0;i<n;i++)/*一旦全部の親を-1にする。*/
    {
      T[i].P=-1;
      T[i].R=-1;
      T[i].L=-1;
    }
  
  for(i=0;i<n;i++)
    {
      scanf("%d",&id);/*idとkの入力*/
      scanf("%d",&T[id].L);
      kodomo=T[id].L;
      if(kodomo!=-1)T[kodomo].P=id;
      scanf("%d",&T[id].R);
      kodomo=T[id].R;
      if(kodomo!=-1)T[kodomo].P=id;
    }

  /*出力編*/

  for(i=0;i<n;i++)
    {

      printf("node %d: ",i);/*ノード番号出力*/
 
      printf("parent = %d, ",T[i].P);/*親出力*/
      
      if(T[i].P==-1) printf("sibling = -1, ");
      else if(i==T[ T[i].P ].L)printf("sibling = %d, ",T[ T[i].P ].R);
      else if(i==T[ T[i].P ].R)printf("sibling = %d, ",T[ T[i].P ].L);

      
      degree=0;
      if(T[i].L!=-1)degree++;
      if(T[i].R!=-1)degree++;
      printf("degree = %d, ",degree);
      
      depth=0;
      id=i;
      
      while(1)
	{
	  if(T[id].P==-1)break;
	  
	  depth++;
	  
	  irekae=id;
	  id=T[irekae].P;
	}

      printf("depth = %d, ",depth);/*深さ出力*/  

      N=n;
      
      hei=height(i);

      printf("height = %d, ",hei);
      
      if(T[i].P==-1)
	{
	  printf("root\n");
	}
      else if(T[i].L==-1&&T[i].R==-1)
	{
	  printf("leaf\n");
	}
      else
	{
	  printf("internal node\n");
	}
    }
      
  return 0;
}
  
int height(int i)
{
  if(T[i].L==-1&&T[i].R==-1)return 0;
  else if(T[i].L==-1)return 1+height(T[i].R);
  else if(T[i].R==-1)return 1+height(T[i].L);
  return 1+max( height(T[i].L), height(T[i].R) );
}

int max(int l,int r)
{
  if(l>r)return l;
  else return r;
}
