#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define rep(i,n) for(i=0;i<n;i++)
#define PI 3.14159265358979323846264338327950L
int main(){
    long long int x,total;
    scanf("%lld",&x);
    if(x%11>6) total=(x/11)*2+2;
    else if(6>=x%11&&x%11>0) total=(x/11)*2+1;
    else total=(x/11)*2;
    printf("%lld",total);
    return 0;
}
