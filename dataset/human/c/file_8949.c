#include<stdio.h>

long long count(long long int c){
    int n=0;
    while(c!=1){
        if(c%2==0)c/=2;
        else c=3*c+1;
        n++;
    }
    return n;
}

int main()
{

    long long int aa,bb,a,b,t,i,max;

    while(~scanf("%lld",&aa) && aa){
        printf("%lld\n",count(aa));
    }
    return 0;
}
