#include<stdio.h>

int main()
{
 int H,W,h,w,n=0;
 while(1){
  scanf("%d %d",&H,&W);
  if(H==0&&W==0) break;
  for(h=0;h<H;h++){
   for(w=0;w<W;w++){
      if(w%2==n){
         printf("#");
      }else{
         printf(".");
      }
     }
     printf("\n");
     if(n==0){
        n=1;
     }else{
        n=0;
     }
    }
    printf("\n");
    n=0;
   }
   return 0;
}
