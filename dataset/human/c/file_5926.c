#include <stdio.h>
#include <math.h>

int main(){
  int n,i,count=0, min, max=-1000000000;
  int Number[200000];
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&Number[i]);
  }
  
  min=Number[0];
  
  
  for(i=1;i<n;i++){
  	if(max<Number[i]-min){
  		max=Number[i]-min;
  }if(min>Number[i]){
  	min=Number[i];
  }
  }
  printf("%d\n", max);
  return 0;
}
