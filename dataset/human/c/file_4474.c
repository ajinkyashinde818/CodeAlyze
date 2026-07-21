#include <stdio.h>
int main(void){
    int N,i,flag=0,cnt=0;
    int D[110][3];
    scanf("%d",&N);
    for(i=1;i<=N;i++){
        scanf("%d",&D[i][1]);
        scanf("%d",&D[i][2]);
    }

    for(i=1;i<=N;i++){
        if(D[i][1]==D[i][2]){
            cnt++;
        }else{
            cnt=0;
        }
        
        if(cnt==3){
            flag=1;
        }


    }

    if(flag==1){
        printf("Yes\n");
    }else{
        printf("No\n");
    }

    return 0;


}
