#include <stdio.h>

#define MAX 100005
#define NIL -1

int p[MAX],left[MAX],right[MAX],d[MAX],h[MAX],sib[MAX];
int Depth(int n)
{
  int d=0;
  while(p[n]!=NIL)
  {
    n=p[n];
    d+=1;
  }
  return d;
}
void printChildren(int n)
{
  int child = left[n];
  while(child!=NIL)
  {
    printf("%d",child);
    child=right[child];
  }
}
int height(int u)
{
  int h1=0,h2=0;
  if(left[u]!=NIL)h1=height(left[u])+1;
  if(right[u]!=NIL)h2=height(right[u])+1;
  if(h1>h2)return h[u]=h1;
  else return h[u]=h2;
}
int sibling(int u)
{
  if(p[u]==NIL)return NIL;
  if(left[p[u]]!=u&&left[p[u]]!=NIL)return left[p[u]];
  if(right[p[u]]!=u&&right[p[u]]!=NIL)return right[p[u]];
  return NIL;
}
int main()
{
  int i,j,id,num,deg,root;
  scanf("%d",&num);
  for(i=0;i<num;i++)
  {
    p[i]=left[i]=right[i]=NIL;
  }
  for(i=0;i<num;i++)
  {
    scanf("%d",&id);
    scanf("%d%d",&left[id],&right[id]);
    if(left[id]!=NIL)p[left[id]]=id;
    if(right[id]!=NIL)p[right[id]]=id;
  }
  for(i=0;i<num;i++)if(p[i]==NIL)root=i;
  height(root);
  for(i=0;i<num;i++)
  {
    d[i]=Depth(i);
  }
  for(i=0;i<num;i++)
  {
    j=0;
    printf("node %d: parent = %d, sibling = %d, ",i,p[i],sibling(i));
    deg=0;
    if(left[i]!=NIL)deg++;
    if(right[i]!=NIL)deg++;
    printf("degree = %d, depth = %d, height = %d, ",deg,d[i],h[i]);
    if(p[i]==NIL)printf("root");
    else if(left[i]==NIL&&right[i]==NIL)printf("leaf");
    else printf("internal node");
    printf("\n");
  }
  return 0;
}
