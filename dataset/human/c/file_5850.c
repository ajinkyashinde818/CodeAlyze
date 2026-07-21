#include<stdio.h>
 
int main(){
 
int a,b,max=-2000000000,min;
 
scanf("%d",&a);
 
int r[200000];
 
int i;

for(i=0;i<a;i++)scanf("%d",&r[i]);
 
min=r[0];
 

 
for(i=1;i<a;i++){
 
if(r[i]-min>max)max=r[i]-min;
if(min>r[i])min=r[i];
}
 
printf("%d\n",max);
 
return 0;
}
