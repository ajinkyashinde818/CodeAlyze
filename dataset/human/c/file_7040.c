#include <stdio.h>
 
int main(void){
    int i,j,H,W,num;
     
    scanf("%d %d",&H,&W);
    while(H!=0 && W!=0){
        for(i=1;i<=H;i++){
            for(j=1;j<=W;j++){
            num=i+j;
            if(num%2==0) printf("#");
            else printf(".");
            }
        printf("\n");
        }
        printf("\n");
        scanf("%d %d",&H,&W);
    }
}
