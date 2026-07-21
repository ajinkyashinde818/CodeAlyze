#include <stdio.h>
#include<string.h>
int main(void){
    // Your code here!
    int n,dice[3][1000];
    scanf("%d",&n);
    int sum=0,flag=0;
    for(int i=1;i<=n;i++){
    scanf("%d%d",&dice[0][i],&dice[1][i]);
    if(dice[0][i]==dice[1][i]) sum++;
    else sum=0;
    if(sum==3) {flag =1;
    break;
    }
    }
    if(flag==1) printf("Yes\n");
    else printf("No\n");
    return 0;
    
}
