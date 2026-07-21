#include <stdio.h>

int main(int argc, const char * argv[])
{
    int H,W,x,y;
    
    while(1){
        scanf("%d %d",&H,&W);
        if(H==0&&W==0){
            break;
        }
        else if(H>=1&&W<=300){
            for(y=0;y<H;y++){
                for(x=0;x<W;x++){
                    if((x+y)%2==0){
                        printf("#");
                    }else if((x+y)%2==1){
                        printf(".");
                    }
                }printf("\n");
            }printf("\n");
        }
    }
    
    return 0;
}
