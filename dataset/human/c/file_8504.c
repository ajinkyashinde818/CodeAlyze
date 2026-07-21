#define MAX 10
#include <stdio.h>

void score_plass(int puz[][5], int *score, int count, int i,int j){
    int k;
    *score+=(puz[i][j]*(count+1));
    for(k=0;k<=count;k++)
        puz[i][j-k]=0;
}

void drop_puzzle(int puz[][5], int i, int j){
    for(;i>0;i--){
        puz[i][j] = puz[i-1][j];
    }
    puz[0][j]=0;
}

int main(void) {
    int h,score,total_score,i,j,count;
    int puz[MAX][5] = {};
    score = 0;
    
    while(1){
        total_score=0;
        count=0;
        scanf("%d",&h);
        if(h==0)
            break;
        for(i=0;i<h;i++){
            for(j=0;j<5;j++)
                scanf("%d",&puz[i][j]);
        }
        while(1){
            for(i=0;i<h;i++){
                for(j=0;j<4;j++){
                    if(puz[i][j] == puz[i][j+1])
                        count++;
                    else if (count >= 2){
                        score_plass(puz,&score,count,i,j);
                        count = 0;
                    }else
                        count=0;
                }
                if(count>=2)
                    score_plass(puz,&score,count,i,j);
                count=0;
            }
            if(score==0)
                break;
            total_score += score;
            score = 0;
            for(i=0;i<h;i++){
                for(j=0;j<5;j++)
                    if(puz[i][j]==0)
                        drop_puzzle(puz,i,j);
            }
        }
        printf("%d\n",total_score);
    }
    
    return 0;
}
