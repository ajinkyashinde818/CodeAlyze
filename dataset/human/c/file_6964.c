#include <stdio.h>
 
int main(){
    int H,W;
    int i,j;
    scanf("%d %d",&H,&W);
    do{
    for (i=1;i<=H;i++){
        for(j=1;j<=W;j++){
            if(i%2==1){
                if(j%2==0){
                    printf(".");
                }
                if(j%2==1){
                    printf("#");
                }
            }
            else if(j%2==0){
                printf("#");
            }
            else if(j%2==1){
                printf(".");
            }
        }
        printf("\n");
    }
    printf("\n");
    scanf("%d %d",&H,&W);
    }while(H!=0&&W!=0);
    return 0;
}
