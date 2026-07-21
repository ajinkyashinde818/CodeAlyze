#include <stdio.h>
int main(void){
    int h,w,i,j;
    char s[51][51];
    scanf("%d%d",&h,&w);
    for(i=0;i<h;i++){
        scanf("%s",s[i]);
    }
    for(i=0;i<h;i++){
        for(j=0;j<w;j++){
            if(s[i][j]=='#'){
                int c=0;
                if(i>0 && s[i-1][j]=='#') c++;
                if(i<h && s[i+1][j]=='#') c++;
                if(j>0 && s[i][j-1]=='#') c++;
                if(j<w && s[i][j+1]=='#') c++;
                if(c==0){
                    printf("No");
                    return 0;
                }
            }
        }
    }
    printf("Yes");
    return 0;
}
