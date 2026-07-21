#include<stdio.h>
int main(){
  int a,b[200000],i,max,min;
  scanf("%d",&a);
  for(i=0;i<a;i++){
    scanf("%d",&b[i]);
  }
  min=b[0];
  max=b[1]-b[0];
  for(i=1;i<a;i++){
    if(max<b[i]-min){
      max=b[i]-min;
    }
    if(min>b[i]){
      min=b[i];
    }
  }
  
  printf("%d\n",max);
  return 0;
}
