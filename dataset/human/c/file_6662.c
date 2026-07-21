#include<stdio.h>

int main()
{
  int n,a[200000],mini,maxi=-1000000001,i;
  scanf("%d",&n);
  for(i = 0;i<n;i++)
    scanf("%d",&a[i]);
  mini = a[0];
  for (i =1;i<n;i++) {
    if(maxi<a[i]-mini)
      maxi = a[i]-mini; 
    if(mini>a[i])
       mini = a[i];
  }
  printf("%d\n",maxi);
  return 0;
}
