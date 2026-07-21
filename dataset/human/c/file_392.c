#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    int n,r;
    scanf("%d %d",&n,&r);
    if(n >= 10){
        printf("%d",r);
    }else{
        int ans = r + 100*(10 - n);
        printf("%d",ans);
    }
    return 0;
}
