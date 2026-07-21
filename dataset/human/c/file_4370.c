#include <stdio.h>
int main(){
    int n,count,ans;
    scanf ("%d",&n);
    int d[n][2];
    count = 0;
    ans =0;
    for(int i=0;i<n;i++){
        scanf("%d %d",&d[i][0],&d[i][1]);
        if(d[i][0]==d[i][1]){
            count++;
            if(ans<count){
                ans =count;
            }
        }else{
            count =0;
        }
    }
    if(ans>2){
        printf("Yes");
    }else{
        printf("No");
    }
    
    return 0;
}
