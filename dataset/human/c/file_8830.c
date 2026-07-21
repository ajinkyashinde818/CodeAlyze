#include <stdio.h>


int main(void){
    int H,W;
    scanf("%d %d",&H,&W);
    int dx[4]={0,1,0,-1};
    int dy[4]={1,0,-1,0};
    char po[100][100];
    for(int i=0;i<100;i++){po[0][i]='.';po[H+1][i]='.';}
    for(int i=1;i<=H;i++)scanf("%s",po[i]);
    for(int i=1;i<=H;i++)for(int j=0;j<W;j++){
        if(po[i][j]=='#'){
            int flag=0;
            for(int k=0;k<4;k++){
                if(j+dx[k]>=0&&j+dx[k]<W&&po[i+dy[k]][j+dx[k]]=='#')flag=1;
            }
            if(flag==0){printf("No");return 0;}
        }
    }
    printf("Yes");
    return 0;
}
