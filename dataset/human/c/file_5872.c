#include<stdio.h>


int main(){
  int n,data,i,max,min;

scanf("%d",&n);

scanf("%d",&min);

for(i=1;i<n;i++){
scanf("%d",&data);
if(i==1)
max=data-min;
if(max<(data-min))
    max=data-min;
    if(min>data)
    min=data;
 }

 printf("%d\n",max);

 
   return 0;
}
