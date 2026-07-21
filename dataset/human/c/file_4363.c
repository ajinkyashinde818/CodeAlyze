#include<stdio.h>

int main(void){
    int N;
    int x,y,i,j;
    int flag=0,ans=0;

    scanf("%d",&N);
    for(i =0;i < N;i++){
        scanf("%d%d",&x,&y);
        if(x == y){
            flag++;
            if(flag==3){
                ans=1;
            }
        }
        else{
            flag=0;
        }
    }
    if(ans==1){
        printf("Yes\n");
    }
    else{
        printf("No\n");
    }
    return 0;
}
