#include<stdio.h>

int main(){
 int n;
 int min;
 int max = -1e18;
 scanf("%d%d",&n,&min);
 for(int i; i < n-1; i++){
  int temp;
  scanf("%d",&temp);
  if(max < temp - min){
   max = temp - min;
  }
  if(temp < min){
   min = temp;
  }
 }
 printf("%d\n",max);
}
