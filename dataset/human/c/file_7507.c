#include<stdio.h>

int main(void)
{
   int num[10000];
   int a = 1;
   int b;
   int i = 1;
   
   while(a){
      scanf("%d", &num[i]);
   
      if(num[i]==0){
         a = 0;}
   	i++;
   }
	
	b = i-1;
         
   for(i=1;i<b;i++){
      printf("Case %d: %d\n", i,num[i]);
      }
      
   return 0;
}
