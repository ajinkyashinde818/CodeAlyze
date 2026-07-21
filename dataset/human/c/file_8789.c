#include <stdio.h>
int main(void){
    int h,w,x;
    scanf("%d%d",&h,&w);
    char a[h][w+1];
    for(int i=0;i<h;i++){
        scanf("%s",a[i]);
    }
    for(int i=1;i<h;i++){
        for(int j=0;j<w;j++){
            if(a[i-1][j]=='#'||a[i-1][j]=='A'){
                if(a[i][j]=='#'||a[i][j]=='A'){
                    a[i-1][j]='A';
                    a[i][j]='A';
                }
            }
        }
    }
    for(int i=0;i<h;i++){
        for(int j=1;j<w;j++){
            if(a[i][j-1]=='#'||a[i][j-1]=='A'){
                if(a[i][j]=='#'||a[i][j]=='A'){
                    a[i][j-1]='A';
                    a[i][j]='A';
                }
            }
        }
    }
    x=0;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(a[i][j]=='#')x++;
        }
    }
    if(x!=0)printf("No\n");
    if(x==0)printf("Yes\n");
}
