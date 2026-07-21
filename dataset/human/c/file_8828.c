#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main(void){
    int h,w;
    scanf("%d%d",&h,&w);
    char s[h+1][w+1];
    for (int i=0; i<h; i++){
        scanf("%s",s[i]);
    }
    for (int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            if(s[i][j]=='#'){
                if(s[i][j-1]=='#' || s[i][j+1]=='#' || s[i-1][j]=='#' || s[i+1][j]=='#'){
                    
                } else {
                    printf ("No\n");
                    exit (0) ;
                }
            }
        }
    }
    printf ("Yes\n");
    return 0 ;
}
