#include <stdio.h>
int main (void){
   int H,W,i,j,k;
   for(;;){
      scanf("%d%d",&H,&W);
      if(H==0&&W==0)break;
      for(i=0;i<H;i++){
         for(j=0;j<W;j++){
            k=i+j;
            if(k%2==0){
               printf("#");
            }
            else if(k%2==1){
               printf(".");
            }
         }
        puts("");
      }
      puts("");
}
return 0;
}
