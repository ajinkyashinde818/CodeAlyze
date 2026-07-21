#include <stdio.h>
int main(void){
    while(1){
        int H;
        scanf("%d",&H);
        if(H==0)break;
        int A[H][5];
        for(int i=0;i<H;i++)for(int j=0;j<5;j++)scanf("%d",&A[i][j]);
        int ans=0;
        while(1){
            int flag=0;
            for(int i=0;i<H;i++){
                if(A[i][0]==A[i][1]&&A[i][1]==A[i][2]&&A[i][2]==A[i][3]&&A[i][3]==A[i][4]&&A[i][2]!=0){flag=1;ans+=A[i][0]*5;for(int j=0;j<5;j++)A[i][j]=0;}
                else if(A[i][0]==A[i][1]&&A[i][1]==A[i][2]&&A[i][2]==A[i][3]&&A[i][2]!=0){flag=1;ans+=A[i][0]*4;for(int j=0;j<4;j++)A[i][j]=0;}
                else if(A[i][1]==A[i][2]&&A[i][2]==A[i][3]&&A[i][3]==A[i][4]&&A[i][2]!=0){flag=1;ans+=A[i][1]*4;for(int j=1;j<=4;j++)A[i][j]=0;}
                else if(A[i][2]==A[i][3]&&A[i][3]==A[i][4]&&A[i][2]!=0){flag=1;ans+=A[i][2]*3;for(int j=2;j<5;j++)A[i][j]=0;}
                else if(A[i][1]==A[i][2]&&A[i][2]==A[i][3]&&A[i][2]!=0){flag=1;ans+=A[i][2]*3;for(int j=1;j<4;j++)A[i][j]=0;}
                else if(A[i][0]==A[i][1]&&A[i][1]==A[i][2]&&A[i][2]!=0){flag=1;ans+=A[i][2]*3;for(int j=0;j<3;j++)A[i][j]=0;}
            }
            while(1){
                int flag3=0;
                for(int i=0;i<H-1;i++)for(int j=0;j<5;j++){
                    if(A[i+1][j]==0&&A[i][j]!=0){flag3=1;A[i+1][j]=A[i][j];A[i][j]=0;}
                }
                if(flag3==0)break;
            }
            if(flag==0)break;
        }
        printf("%d\n",ans);
    }
    return 0;
}
