#include<stdio.h>
#define MAX 100001
#define NIL -1
struct Node
{
  int A;
  int B;
  int C;
};
 
struct Node Three[MAX];
 
int getDepth(int K)
{
  int dep = 0;
   
  for(dep = 0; Three[K].A != NIL; dep++)
  {
    K = Three[K].A;
  }
  return dep;
}
 
int main()
{
  int i,j,n;
  int num,deg,child,l = 0;

  scanf("%d",&n);

  for(i = 0; i < n; i++)
    {
      Three[i].A = NIL;
      Three[i].B = NIL;
      Three[i].C = NIL;
    }
     
 
    for(i = 0; i < n; i++)
    {
 
      scanf("%d%d",&num,&deg);

      for(j = 0; j < deg; j++)
      {
        scanf("%d",&child);
 
        if(j == 0) Three[num].B = child;
        else Three[l].C = child;
 
        l = child;
        Three[child].A = num;
      }
 
    }
     
    for(i = 0; i < n; i++)
    {
      printf("node %d: parent = %d, depth = %d",i,Three[i].A,getDepth(i));
       

      if(getDepth(i) == 0)
      {
 
        printf(", root, [");
 
      }
      else if(Three[i].B == NIL)
      {
 
        printf(", leaf, [");
 
      }
 
      else
      {
        printf(", internal node, [");
      }
       
      j = Three[i].B;
       
      while(j != NIL)
      {
        printf("%d", j);
 
        j = Three[j].C;
         
        if(j != NIL)
        {
 
          printf(", ");
          
        }
 
      }
 
 
      printf("]\n");
 
    }
 
     
    return 0;
}
