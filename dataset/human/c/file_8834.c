#include"stdio.h"
int main(){
    int H,W,res=1;
    scanf("%d%d",&H,&W);
    char s[51][51];
    for(int i=0;i<H;i++){
        scanf("%s",s[i]);
    }
    for(int i=0;i<H&&res;i++){
        for(int j=0;j<W&&res;j++){
            if(s[i][j]=='#'){
                if(s[i-1][j]=='#'||s[i+1][j]=='#'||s[i][j-1]=='#'||s[i][j+1]=='#'){
                    continue;
                }else{
                    res=0;
                }
            }
        }
    }
    if(res) printf("Yes");
    else printf("No");
    return 0;
}
