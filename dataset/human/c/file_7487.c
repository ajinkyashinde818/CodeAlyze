#include<stdio.h>
   #define NUMBER 10000
   int main(void){
       int i,c=0,x[NUMBER];
       for(i=0;1;i++){
          scanf("%d",&x[i]);
          if(x[i]==0)
            break;
          c++;
     }
      for(i=0;i<c;i++){
         printf("Case %d: %d\n",i+1,x[i]);
      }
      return 0;
  }
