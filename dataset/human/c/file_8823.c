#include<stdio.h>
int main(){
    int h,w;
    char str[100][100];
    int map[100][100]={{}};

    scanf("%d %d",&h,&w);
    for(int i=0;i<h;i++){
        scanf("%s",str[i]);
    }
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(str[i][j]=='.'){
                map[i][j]=-1;
            }
        }
    }

    for(int i=0;i<h;i++){
        for(int j=0;j<w-1;j++){
            if(str[i][j]=='#'){
                if(str[i][j]==str[i][j+1]){
                    map[i][j]=map[i][j+1]=1;
                }
            }
        }
    }
    for(int i=0;i<w;i++){
        for(int j=0;j<h-1;j++){
            if(str[j][i]=='#'){
                if(str[j][i]==str[j+1][i]){
                    map[j][i]=map[j+1][i]=1;
                }
            }
        }
    }
   
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(map[i][j]==0){
                printf("No\n");
                return 0;
            }
        }
    }
    printf("Yes\n");
    return 0;
}
