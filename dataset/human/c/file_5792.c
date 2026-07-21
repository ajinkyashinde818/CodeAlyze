#include<stdio.h>
int main()
{
  int i,n;
  long int max=-999999999999999999,min;
  scanf("%d",&n);
  int t[n];
  for(i=0; i<n; i++)
    scanf("%d",&t[i]);
  min=t[0];
  for(i=1; i<n;i++){
    if(max<t[i]-min)
      max=t[i]-min;
    if(min>t[i])
      min=t[i];
  }
 // printf("max:%ld min:%ld\n",max,min);
  printf("%ld\n",max);
    
 
return 0;
}
