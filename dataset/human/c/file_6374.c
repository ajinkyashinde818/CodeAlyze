#include<stdio.h>
int main(){
  int a,b[200000],n,max,min;
  scanf("%d",&a);
  for(n=0;n<a;n++){
    scanf("%d",&b[n]);
  }
  min=b[0];
  max=b[1]-b[0];
  for(n=1;n<a;n++){
    if(max<b[n]-min){
      max=b[n]-min;
    }
    
    if(min>b[n]){
      min=b[n];
    }
    
  }
  
  
  printf("%d\n",max);
  return 0;
}
