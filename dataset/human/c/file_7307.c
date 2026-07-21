#include <stdlib.h>
#include <stdio.h>
long long MIN(long long a, long long b){
    return a<b?a:b;
}
int main()
{   int h,w,k;
    scanf("%d%d%d",&h,&w,&k);
    char s[h][w+1];
    for(int i=0;i<h;i++){
        scanf("%s",s[i]);
    }
    int a[300][300]={0},cat=1,map[h];
    for(int i=0;i<h;i++){
        map[i]=0;
    }
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(s[i][j]=='#'){
               map[i]++; 
            }
        }
    }
    for(int i=0;i<h;i++){
        if(map[i]>0){
            int flag=0,x=0;
            for(int j=0;j<w;j++){
                if(s[i][j]=='#'&&flag==0){
                    while(x<=j){
                        a[i][x]=k;
                        x++;
                    }
                    flag=1;
                }
                if(s[i][j]=='#'){
                    a[i][j]=k;
                    x=j+1;
                    while(s[i][x]=='.'){
                        a[i][x]=k;
                        x++;
                    }
                    k--;
                }
            }
        }
    }
    int up=0,down=0;
    for(int i=0;i<h;i++){
        if(map[i]==0){
            up++;
        }else if(up>0){
            down=i-1;
            while(up>0){
                for(int j=0;j<w;j++){
                    a[down][j]=a[down+1][j];
                }
                down--;
                up--;
            }
            
        }
        if(i==h-1&&up>0){
            while(up>0){
                for(int j=0;j<w;j++){
                a[i-up+1][j]=a[i-up][j];
                }
                up--;
            }
        }
    }
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
