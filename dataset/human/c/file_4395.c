#include <stdio.h>


int main(void)
{
    int n,judge=0;
    int d[100][2]={0};
    scanf("%d",&n);
    for(int i=0;i<=n-1;i++){
        scanf("%d%d",&d[i][0],&d[i][1]);
    }
    for(int i=2;i<=n-1;i++){
        if(judge == 1) break;
        if(d[i][0] == d[i][1]) {
            
            
            if(d[i-1][0] == d[i-1][1]) {
                
                
                if(d[i-2][0] == d[i-2][1]) {
                judge++;
                }
            
            }
        }
    }
    if(judge == 1){
        printf("Yes");
    }else{
        printf("No");
    }
    

}
