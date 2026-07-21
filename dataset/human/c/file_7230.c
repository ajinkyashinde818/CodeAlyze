#include<stdio.h>
int main(void){
    int H,W,i,j,Hkai,Wkai;
    for(;;){
    scanf("%d%d",&H,&W);
            if(H==0&&W==0){
            break;}
    for(Hkai=1;Hkai<=H;Hkai++){
    for(Wkai=1;Wkai<=W;Wkai++){
    i = Wkai % 2;
    j = Hkai % 2;
        if(i==1&&j==1||i==0&&j==0){
            printf("#");
        }
        else{
            printf(".");
        }
    }
    puts("");
    }
    puts("");
    }
    return 0;
}
