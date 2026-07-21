#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int main(){
    int n,r,ans;
    scanf("%d %d",&n,&r);
    if(n>=10){
        printf("%d",r);
        return 0;
    }
    else {
        printf("%d",r+100*(10-n));
        return 0;
    }
}
