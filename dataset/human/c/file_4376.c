#include<stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    int d[n][2];
    for(int i=0;i<n;i++){
        scanf("%d %d",&d[i][0],&d[i][1]);
    }

    int make=0;
    for(int i=0;i<n;i++){
        if(d[i][0]==d[i][1]){
            if(d[i+1][0]==d[i+1][1]&&d[i+2][0]==d[i+2][1]){
                make++;
            }
        }
    }
    if(make>0){
        printf("Yes\n");
    }else{
        printf("No\n");
    }
    return 0;
}
