#include<stdio.h>

int main()
{
    long a,b;
    
    scanf("%ld%ld",&a,&b);
    long long x=a*b;
    long tmp;
    long r;
    if(a<b){
        tmp=a;
        a=b;
        b=tmp;
    }
    r=a%b;
    while(r!=0){
        a=b;
        b=r;
        r=a%b;
    }
    printf("%ld\n",x/b);
    return 0;

}
