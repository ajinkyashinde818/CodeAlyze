#include<stdio.h>
int main()
{
  int n,i,k,max=0,min=0;
  scanf("%d",&n);
  int a[n];
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  max=a[1]-a[0];
  min=a[0];
  for(i=1;i<n;i++){
    int b=a[i]-min;
    if(b>max)max=b;
    if(a[i]<min)min=a[i];
  }
  printf("%d\n",max);
  return 0;
}
