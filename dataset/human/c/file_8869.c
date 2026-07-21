#include<stdio.h>

int main(void){
    int h,w;
    scanf("%d%d", &h,&w);

    char s[h][w+1];
    for(int i=0; i<h; i++){
        scanf("%s", s[i]);
    }
    
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    int tmpx,tmpy;

    int flag_ans = 1;
    int flag_part = 0;
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            
            if(s[i][j] == '#'){
                flag_part = 0;
                for(int k=0; k<4; k++){
                    tmpx = i+dx[k];
                    tmpy = j+dy[k];

                    if((0<=tmpx)&&(tmpx<h)){
                        if((0<=tmpy)&&(tmpy<w)){
                            if(s[tmpx][tmpy] == '#'){
                                flag_part = 1;
                            }
                        }
                    }
                }

                if(flag_part == 0){
                    flag_ans = 0;
                    goto loopend;
                }
            }
        }
    }

    loopend:
    if(flag_ans == 1){
        printf("Yes\n");
    }else{
        printf("No\n");
    }

    return 0;
}
