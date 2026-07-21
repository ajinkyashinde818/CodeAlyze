#include<stdio.h>

#define N 200000


int main(){

  int n,i,max,min;
  int kawase[N];

  scanf("%d",&n);

  for(i = 0;i < n;i++)
    scanf("%d",&kawase[i]);
  
  max = -999999999;
  min = kawase[0];
  for(i = 1;i < n;i++){
    
    if(max <  kawase[i]-min)
      max = kawase[i]-min;

    if(min > kawase[i])
      min = kawase[i];

  }
      
    
  printf("%d\n",max);

  return 0;
}
