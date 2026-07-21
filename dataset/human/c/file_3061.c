#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//typedef long long ll;
int comp(const void *a,const void *b)
{
  return *(int *)a-*(int *)b; 
}
int main(void)
{
  int k,n;
  scanf("%d%d",&k,&n);
  int a[n],max;
  for(int i=0;i<n;i++) scanf("%d",&a[i]);
  qsort(a,n,sizeof(int),comp);
  max=a[0]+k-a[n-1];
  for(int i=1;i<n;i++)
    if((a[i]-a[i-1])>max) max=a[i]-a[i-1];
  printf("%d\n",k-max);
  return 0;
}
