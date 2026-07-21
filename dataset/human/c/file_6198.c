#include<stdio.h>
#define N 2000000   
int main(){
   
  int n,i,max=-100000000000,min,r[N];
   
 scanf("%d",&n);
 
 for(i=0;i<n;i++){
 scanf("%d",&r[i]);
 }
   
 min=r[0];
   
  
   
for(i=1;i<n;i++){
 
  if(r[i]-min>max){
  max=r[i]-min;
  }
  if(min>r[i]){
  min=r[i];
  }
}
   
printf("%d\n",max);
   
return 0;
}
