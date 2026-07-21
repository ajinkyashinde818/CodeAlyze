#include<stdio.h>
#include<stdlib.h>
int main(){
  int a,b,k;
  int i;
  scanf("%d %d %d",&a,&b,&k);
  int *sosuu;
  sosuu=malloc(k*sizeof(int));
  
  int max;
  if(a>b)
    max=a;
  else
    max=b;
  int count=0;
  
  for(i=max;i>0;i--){
    if(a%i==0&&b%i==0){
      sosuu[count++]=i;
    }
    if(count==k)
      break;
  }
  printf("%d",sosuu[k-1]);
    	
  return 0;
}
