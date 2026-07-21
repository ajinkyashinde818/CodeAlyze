#include <stdio.h>
#include <math.h>
int main(int argc, const char * argv[])
{
    int x[10000],i=0,c;
for(c=0;c<10000;c++){
x[c]=0;
}
   while(1){
      scanf("%d",&x[i]);
      if(x[i]==0){
         break;
      }
      i++;
   }
   i=0;
   while(1){
     if(x[i]==0){
         break;
     }
     printf("Case %d: %d\n",i+1,x[i]);
     i++;
   }
    return 0;
}
