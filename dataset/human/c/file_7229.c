#include <stdio.h>
int main(){
    int i,j,h,w;
    while(1){
        scanf("%d %d",&h,&w);
        if(h==0 &&w==0){
            break;
        }
        for(i=1;i<=h;i++){
            for(j=1;j<=w;j++){
                if(i%2 == 1){
                    if(j%2==1){
                        printf("#");
                    }else{
                        printf(".");
                    }
                }else{
                    if(j%2==1){
                        printf(".");
                    }else{
                        printf("#");
                    }
                }
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
