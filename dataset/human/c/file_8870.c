#include<stdio.h>
char tgt[100][100];
int h_offset[4]={1,0,-1,0};
int w_offset[4]={0,1,0,-1};
int main(void){
    int h,w,i,j,k,flg,x,y;
    char tmp;
    scanf("%d %d",&h,&w);
    for(i=0;i<h;i++){
        for(j=0;j<w;j++){
            scanf("%c",&tmp);
            if(tmp!='\n'){
                tgt[i][j]=tmp;
            }else{
                j--;
            }
        }
    }
    flg=0;
    for(i=0;i<h;i++){
        for(j=0;j<w;j++){
            if(tgt[i][j]=='#'){
                flg=1;
                for(k=0;k<4;k++){
                    x=j+w_offset[k];
                    y=i+h_offset[k];
                    if(0<=  x <=100 && 0<= y <=100){
                        if(tgt[y][x]=='#'){
                            flg=0;
                            break;
                        }
                    }
                }
                if(flg==1){
                    printf("No\n");
                    return 0;
                }
            }
        }
    }
    printf("Yes\n");
    return 0;
}
