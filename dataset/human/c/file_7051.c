#include<stdio.h>
 
int main(){
    int w,h,i,j;
    while(1){
        scanf("%d %d",&w,&h);
        if(w==0&&h==0) break;
        for(i=0;i<w;i++){
            for(j=0;j<h;j++){
                if((i%2==0&&j%2==0)||(i%2==1&&j%2==1)){
                    printf("#");
                }else{
                    printf(".");
                }
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
