#include<stdio.h>
int main(){
  int n,m,s,a=1e9,i;
  scanf("%d %d %d",&n,&m,&s);
  if(s>1e8)a=1;
  for(i=0;i<m;i++)printf("%d ",s);
  for(i=m;i<n;i++)printf("%d ",a);
  printf("\n");
  return 0;
}
