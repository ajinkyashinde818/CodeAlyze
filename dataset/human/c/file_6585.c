#include<stdio.h>
#define N 200000

int main(){
  int n,num[N],i,max,min;
  
  scanf("%d",&n);
  
  for(i=0;i<n;i++)scanf("%d",&num[i]);
  
  max=num[1]-num[0];
  min=num[0];
  for(i=1;i<n;i++){
    if(num[i]-min>max)max=num[i]-min;
    if(min>num[i])min=num[i];
  }
  
  printf("%d\n",max);
  return 0;
}
