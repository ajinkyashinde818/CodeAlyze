#include <stdio.h>
int main(void){
    // Your code here!
   
 int date[10000],i=1;

 while(1){
 if(i>10000)break;
 scanf("%d",&date[i]);
 if(date[i]==0)break;
 printf("Case %d: %d\n",i,date[i]);
 i++;
 }
 i=1;
 while(1){
 if(date[i]==0)break;
 if(date[i]!=0){
 i++;
 }
 return 0;
 }
}
