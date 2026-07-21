#include <stdio.h>
#include <string.h>

int main(void)
{
    int i,j;
    int H,W;
    int ans=1;
    char s[50][50];
    char t[3]=".#";
    scanf("%d",&H);
    scanf("%d",&W);
    for(i=0;i<H;i++){
            scanf("%s",&s[i]);
    }
    #if 0
    for(i=0;i<H;i++){
        for(j=0;j<H;j++){
            printf(s[i][j]);
        }
        printf("\n");
    }
   #endif
//   printf("\n%s\n",s[0][1]);
    for(i=0;i<H;i++){
        for(j=0;j<W;j++){
            if(s[i][j]==t[1]){
                if(i!=0 && s[i-1][j]==t[1]) {
                    ans=1;
                }else if(j!=0 && s[i][j-1]==t[1]){
                    ans=1;
                }else if(i!=H-1 && s[i+1][j]==t[1]){
                    ans=1;
                }else if(j!=W-1 && s[i][j+1]==t[1]){
                    ans=1;
                }else{
                    ans=0;
                    break;
                }
            }
        }
        if(ans==0) break;
    }
    if(ans==1){
        printf("Yes");
    }else{
        printf("No");
    }
    return 0;
}
