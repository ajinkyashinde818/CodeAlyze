#include<stdio.h>
int main(void){
    int i,j,n,k,h,w;
    while(1){
    scanf("%d%d",&h,&w);
    if(h==0 || w==0){
        break;
    }
        for(i=0;i<h;i++){
            for(j=0;j<w;j++){
                    k=i%2;
                    n=j%2;
                if(k!=n){
                    printf(".");
                }
                else {
                    printf("#");
                }
            }
             printf("\n");
        }

        printf("\n");
    }
return 0;
}
