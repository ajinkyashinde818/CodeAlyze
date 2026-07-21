#include<stdio.h> //rooted trees
#define M 100001
typedef struct tree
{
  int p,l,r;
}t;
t T[M];
  
int main(void)
{
  int n,i,j,k,id,c,tmp,tmp2;
  
  scanf("%d",&n);
  
  for(i=0;i<n;i++)
    {
    T[i].p=T[i].l=T[i].r=-1;
    }
  for(i=0;i<n;i++)
    {
    scanf("%d %d",&id,&k);
    for(j=0;j<k;j++)
      {
      scanf("%d",&c);
      T[c].p=id;
      if(j==0)
    T[id].l=c;
      else
    T[tmp].r=c;
      tmp=c;
    }
  }
  for(i=0;i<n;i++)
    {
    id=0;
    k=0;
    tmp=T[i].p;
    tmp2=T[i].l;
    while(tmp!=-1)
      {
      k++,tmp=T[tmp].p;
    }
    printf("node %d: parent = %d, depth = %d, ",i,T[i].p,k);
    if(T[i].p==-1)
      printf("root, [");
    else if(T[i].l!=-1)
      printf("internal node, [");
    else
      printf("leaf, [");
    while(tmp2!=-1)
      {
      if(id==0)
	{
    printf("%d",T[i].l);
    id=1;
      }
      else
    printf(", %d",tmp2);
      tmp2=T[tmp2].r;
    }
    printf("]\n");
  }
  return 0;
}
