#include <stdio.h>
#include <stdlib.h>
#define Yes()       printf("Yes\n")
#define No()        printf("No\n")

char s[51][51]={0};

int check(int h, int w){
    if     ( h<0 || w<0 )   return 0;
    else if( s[h][w]=='.' ) return 1;
    else                    return 0;
}

int main(){
    int h,w;
    scanf("%d%d",&h,&w);
    for(int i=0; i<h; i++){ scanf("%s", s[i]); }
    
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            if( s[i][j]=='#'
            &&  check(i-1,j)    //上
            &&  check(i+1,j)    //下
            &&  check(i,j-1)    //左
            &&  check(i,j+1) )  //右
            {
                No();
                return 0;
            }
        }
    }
    Yes();
    return 0;
}
