#include<stdio.h>
#define N 200000


main(){

  int n,a[N],j,max,min;

  scanf("%d",&n);

for(j=0;j<n;j++){
  
 
      scanf("%d",&a[j]);
 }

 min = a[0];
 max = a[1] - a[0];
 for(j=1;j<n;j++){
      
      if(max<a[j]-min) max=a[j]-min;
      if(min > a[j])min = a[j];
 }

 printf("%d\n",max);
 return 0;
}
