#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(){
    int a,b,k,ans,count=0,kotae;
    scanf("%d%d%d",&a,&b,&k);
    if (a>=b) {
        ans=b;
    }else{
        ans=a;
    }
    for (int i=ans; count!=k; i--) {
        if (a%i==0&&b%i==0) { //aの約数でかつbの約数
            kotae=i;
            count++;
        }
    }
    printf("%d\n",kotae);
    return 0;
}
