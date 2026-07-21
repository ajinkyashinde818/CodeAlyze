#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <string.h>
#define ll long long int

int main(void)
{int n,k;
  scanf("%d%d",&k,&n);
  int a[n];
    for(int i=0;i<n;i++){
      scanf("%d",&a[i]);
}
  int max=k-a[n-1]+a[0];
for(int i=0;i<n-1;i++){
  int l=a[i+1]-a[i];
  if(l>max)
    max=l;
 
}
  	 		
  printf("%d",k-max);

    return EXIT_SUCCESS;
}
